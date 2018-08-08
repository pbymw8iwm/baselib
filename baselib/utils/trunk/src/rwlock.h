/// @file rwlock.h

#ifndef THREAD_RWLOCK_H
#define THREAD_RWLOCK_H

namespace utils
{
    namespace thread
    {
        class rwlock_impl;

        /**
            ��д���Ŀ�ƽ̨ʵ��
         */
        class ReadWriteLock
        {
        public:
            ReadWriteLock();

            ~ReadWriteLock();

        public:
            /// ֧���Զ��ͷŵĶ���
            class ReadLock
            {
            public:
                ReadLock(ReadWriteLock & lock)
                    : lock_(lock)
                {
                    lock_.read_lock();
                }

                ~ReadLock()
                {
                    lock_.read_unlock();
                }

            private:
                ReadWriteLock & lock_;

            };

            /// ֧���Զ��ͷŵ�д��
            class WriteLock
            {
            public:
                WriteLock(ReadWriteLock & lock)
                    : lock_(lock)
                {
                    lock_.write_lock();
                }

                ~WriteLock()
                {
                    lock_.write_unlock();
                }

            private:
                ReadWriteLock & lock_;

            };

        public:
            ReadLock read_locker()
            {
                return ReadLock(*this);
            }

            WriteLock write_locker()
            {
                return WriteLock(*this);
            }

        public:
            // ��ʼ��
            int init();

            /// ��ȡ����
            int read_lock();

            /// ��ȡд��
            int write_lock();

            /// �ͷŶ���
            int read_unlock();

            /// �ͷ�д��
            int write_unlock();

        private:
            rwlock_impl * impl_;

        };

    } // namespace thread

} // namespace utils

#endif // THREAD_CONDITION_H
