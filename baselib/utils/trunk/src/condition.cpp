
#include "condition.h"

#ifdef WIN32
#define  _WIN32_WINNT 0x0500
#define WIN32_LEAN_AND_MEAN
#include <windows.h>
#else
#include <pthread.h>
#endif

namespace utils
{
    namespace thread
    {

#ifdef WIN32

        class condition_impl
        {
            friend class Condition;
            condition_impl(int & status)
                : sema_(NULL)
                , waiters_done_(NULL)
                , mutex_(NULL)
            {
                waiters_count_ = 0;
                was_broadcast_ = 0;
                ::InitializeCriticalSection(
                    &waiters_count_lock_);
                sema_ = ::CreateSemaphore(
                    NULL,       // no security
                    0,          // initially 0
                    0x7fffffff, // max count
                    NULL); // unnamed
                waiters_done_ = CreateEvent (
                    NULL,  // no security
                    FALSE, // auto-reset
                    FALSE, // non-signaled initially
                    NULL); // unnamed
                mutex_ = ::CreateMutex(
                    NULL,  // no security
                    FALSE, // notinitial owner 
                    NULL); // unnamed
                if (sema_ == NULL 
                    || waiters_done_ == NULL 
                    || mutex_ == NULL)
                    status = -1;
            }

            ~condition_impl()
            {
                if (mutex_ != NULL)
                    ::CloseHandle(mutex_);
                if (waiters_done_ != NULL)
                    ::CloseHandle(waiters_done_);
                if (sema_ != NULL)
                    ::CloseHandle(sema_);
                ::DeleteCriticalSection(&waiters_count_lock_);
            }

            int lock()
            {
                return ::WaitForSingleObject(mutex_, INFINITE) == WAIT_OBJECT_0 ? 0 : -1;
            }

            int unlock()
            {
                return ::ReleaseMutex(mutex_) ? 0 : -1;
            }

            int wait()
            {
                return timed_wait(INFINITE);
            }

            int timed_wait(int msec)
            {
                // Avoid race conditions.
                ::EnterCriticalSection (&waiters_count_lock_);
                waiters_count_++;
                ::LeaveCriticalSection (&waiters_count_lock_);

                // This call atomically releases the mutex and waits on the
                // semaphore until <pthread_cond_signal> or <pthread_cond_broadcast>
                // are called by another thread.
                // 假设等待信号的操作时间比较长，其他的获取锁的操作应该都比较短
                ::SignalObjectAndWait (mutex_, sema_, msec, FALSE);

                // Reacquire lock to avoid race conditions.
                ::EnterCriticalSection (&waiters_count_lock_);

                // We're no longer waiting...
                waiters_count_--;

                // Check to see if we're the last waiter after <pthread_cond_broadcast>.
                int last_waiter = was_broadcast_ && waiters_count_ == 0;

                ::LeaveCriticalSection (&waiters_count_lock_);

                // If we're the last waiter thread during this particular broadcast
                // then let all the other threads proceed.
                if (last_waiter)
                    // This call atomically signals the <waiters_done_> event and waits until
                    // it can acquire the <external_mutex>.  This is required to ensure fairness. 
                    ::SignalObjectAndWait (waiters_done_, mutex_, INFINITE, FALSE);
                else
                    // Always regain the external mutex since that's the guarantee we
                    // give to our callers. 
                    ::WaitForSingleObject (mutex_, INFINITE);
                return 0;
            }

            int signal()
            {
                EnterCriticalSection (&waiters_count_lock_);
                int have_waiters = waiters_count_ > 0;
                LeaveCriticalSection (&waiters_count_lock_);

                // If there aren't any waiters, then this is a no-op.  
                if (have_waiters)
                    ReleaseSemaphore (sema_, 1, 0);
                return 0;
            }

            int broadcast()
            {
                // This is needed to ensure that <waiters_count_> and <was_broadcast_> are
                // consistent relative to each other.
                EnterCriticalSection (&waiters_count_lock_);
                int have_waiters = 0;

                if (waiters_count_ > 0) {
                    // We are broadcasting, even if there is just one waiter...
                    // Record that we are broadcasting, which helps optimize
                    // <pthread_cond_wait> for the non-broadcast case.
                    was_broadcast_ = 1;
                    have_waiters = 1;
                }

                if (have_waiters) {
                    // Wake up all the waiters atomically.
                    ReleaseSemaphore (sema_, waiters_count_, 0);

                    LeaveCriticalSection (&waiters_count_lock_);

                    // Wait for all the awakened threads to acquire the counting
                    // semaphore. 
                    WaitForSingleObject(waiters_done_, INFINITE);
                    // This assignment is okay, even without the <waiters_count_lock_> held 
                    // because no other waiter threads can wake up to access it.
                    was_broadcast_ = 0;
                }
                else
                    LeaveCriticalSection (&waiters_count_lock_);
                return 0;
            }

            int waiters_count_;
            // Number of waiting threads.

            CRITICAL_SECTION waiters_count_lock_;
            // Serialize access to <waiters_count_>.

            HANDLE sema_;
            // Semaphore used to queue up threads waiting for the condition to
            // become signaled. 

            HANDLE waiters_done_;
            // An auto-reset event used by the broadcast/signal thread to wait
            // for all the waiting thread(s) to wake up and be released from the
            // semaphore. 

            size_t was_broadcast_;
            // Keeps track of whether we were broadcasting or signaling.  This
            // allows us to optimize the code if we're just signaling.

            HANDLE mutex_;
        };

#else

        class condition_impl
        {
            friend class Condition;
            condition_impl(int & status)
                : init_status_(0)
            {
                if (::pthread_mutex_init(&mutex_, NULL) == 0)
                    init_status_ |= 1;
                if (::pthread_cond_init(&cond_, NULL) == 0)
                    init_status_ |= 2;
                if (init_status_ != 3)
                    status = -1;
            }

            ~condition_impl()
            {
                if (init_status_ & 2)
                    ::pthread_cond_destroy(&cond_);
                if (init_status_ & 1)
                    ::pthread_mutex_destroy(&mutex_);
            }

            int lock()
            {
                return ::pthread_mutex_lock(&mutex_);
            }

            int unlock()
            {
                return ::pthread_mutex_unlock(&mutex_);
            }

            int wait()
            {
                return ::pthread_cond_wait(&cond_, &mutex_);
            }

            int timed_wait(int msec)
            {
                struct timespec ts;
                // 这里clock_gettime从rt库导出，链接时需要指定“-l rt”
                clock_gettime(CLOCK_REALTIME, &ts);
                ts.tv_sec += msec / 1000;
                ts.tv_nsec += (msec % 1000) * 1000 * 1000;
                if (ts.tv_nsec >= 1000 * 1000 * 1000) {
                    ts.tv_sec++;
                    ts.tv_nsec -= 1000 * 1000 * 1000;
                }
                return ::pthread_cond_timedwait(&cond_, &mutex_, &ts);
            }

            int signal()
            {
                return ::pthread_cond_signal(&cond_);
            }

            int broadcast()
            {
                return ::pthread_cond_broadcast(&cond_);
            }

            pthread_mutex_t mutex_;
            pthread_cond_t cond_;
            int init_status_;
        };

#endif

        Condition::Condition()
            : impl_(NULL)
        {
        }

        Condition::~Condition()
        {
            if (impl_)
                delete impl_;
        }

        int Condition::init()
        {
            int status = 0;
            impl_ = new condition_impl(status);
            return status;
        }

        int Condition::lock()
        {
            return impl_->lock();
        }

        int Condition::unlock()
        {
            return impl_->unlock();
        }

        int Condition::wait()
        {
            return impl_->wait();
        }

        int Condition::timed_wait(int msec)
        {
            return impl_->timed_wait(msec);
        }

        int Condition::signal()
        {
            return impl_->signal();
        }

        int Condition::broadcast()
        {
            return impl_->broadcast();
        }

    } // namespace thread

} // namespace utils
