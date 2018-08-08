//! @file thread_mutex.h
//! @brief �߳���


#ifndef _THREAD_MUTEX_H_
#define _THREAD_MUTEX_H_


#ifdef WIN32
#define WIN32_LEAN_AND_MEAN
  #include <windows.h>
#else
  #include <pthread.h>
#endif


namespace utils {


//! @class Thread_Mutex
//! @brief �߳���
class Thread_Mutex
{
public:
	Thread_Mutex();
	~Thread_Mutex();

	//! ����
	//! @return 0:�ɹ�, <0:ʧ��
	int acquire();

	//! ����
	//! @return 0:�ɹ�, <0:ʧ��
	int release();

private:
	//! �߳���
#ifdef WIN32
	CRITICAL_SECTION m_thread_section;
#else
	pthread_mutex_t m_thread_mutex;
#endif
};


//! @class Thread_Mutex_Guard
//! @brief �߳���������
//!
//! �����ڹ��캯������, ������������
class Thread_Mutex_Guard
{
public:
	//! ���캯��
	//! @param mutex �õ����߳���
	Thread_Mutex_Guard(Thread_Mutex& mutex);

	//! ��������
	~Thread_Mutex_Guard();

private:
	Thread_Mutex& m_mutex;
};


} // namepsace utils


#endif // _THREAD_MUTEX_H_
