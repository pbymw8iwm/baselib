//! @file pool_allocator.h


#ifndef _POOL_ALLOCATOR_H_
#define _POOL_ALLOCATOR_H_


#include "thread_mutex.h"
#include <stddef.h>
#include <assert.h>


//! @class Pool_Allocator_T
//! @brief �ط�����
//!
//! Ԥ�ȷ���һ����ڴ沢�п�, �þ���ֱ��new
//! ������Ҫ��֤�̰߳�ȫ
template <typename T, int MAX_COUNT>
class Pool_Allocator_T
{
public:
	Pool_Allocator_T();
	~Pool_Allocator_T();

public:
	//! �����ڴ�
	//! @param size Ҫ�����ڴ�ĳ���
	//! @return ���ָ��
	void* acquire(size_t size);

	//! �ͷ��ڴ�
	//! @param p Ҫ�ͷ��ڴ��ָ��
	//! @param size Ҫ�ͷ��ڴ�ĳ���
	void release(void *p, size_t size);

private:
	//! ���ݳ���(���뵽4)
	const int BLOCK_LENGTH;

	//! �ڴ��
	char *m_chunk;

	//! ����ָ������
	void *m_pool[MAX_COUNT];

	//! ��ǰ����ָ��
	int m_index;

	//! �߳���
	utils::Thread_Mutex m_mutex;
};


template <typename T, int MAX_COUNT>
Pool_Allocator_T<T, MAX_COUNT>::Pool_Allocator_T() : BLOCK_LENGTH((sizeof(T) + 3) & ~3)
{
	m_chunk = new char[MAX_COUNT * BLOCK_LENGTH];

	for (int i = 0; i < MAX_COUNT; i++)
	{
		void *p = m_chunk + i * BLOCK_LENGTH;
		m_pool[i] = p;
	}

	m_index = MAX_COUNT - 1;
}


template <typename T, int MAX_COUNT>
Pool_Allocator_T<T, MAX_COUNT>::~Pool_Allocator_T()
{
	delete [] m_chunk;
}


template <typename T, int MAX_COUNT>
void* Pool_Allocator_T<T, MAX_COUNT>::acquire(size_t size)
{
	assert(size == sizeof(T));

	void *p;

	m_mutex.acquire();

	if (m_index >= 0)
	{
		p = m_pool[m_index];
		m_index--;

		m_mutex.release();
	}
	else
	{
		m_mutex.release();

		p = new char[sizeof(T)];
	}

	return p;
}


template <typename T, int MAX_COUNT>
void Pool_Allocator_T<T, MAX_COUNT>::release(void *p, size_t size)
{
	assert(size == sizeof(T));

	m_mutex.acquire();

	if ((p >= m_chunk) && (p < m_chunk + MAX_COUNT * BLOCK_LENGTH))
	{
		m_index++;
		m_pool[m_index] = p;

		assert(m_index < MAX_COUNT);
		assert(0 == (((char*)p - m_chunk) % BLOCK_LENGTH));

		m_mutex.release();

		return;
	}

	m_mutex.release();

	delete [] (char*)p;
	return;
}


//! @def DECLARE_ALLOCATOR
//! @brief �����������������ص�new, delete
#define DECLARE_ALLOCATOR(T, MAX_COUNT)	\
private:	\
	typedef Pool_Allocator_T<T, MAX_COUNT> Pool_Allocator;	\
	static Pool_Allocator m_pool_allocator;	\
public:	\
	void* operator new(size_t size);	\
	void operator delete(void *p, size_t size);


//! @def IMPLEMENT_ALLOCATOR
//! @brief ����������������ص�new, delete
#define IMPLEMENT_ALLOCATOR(T)	\
T::Pool_Allocator T::m_pool_allocator;	\
void* T::operator new(size_t size)	\
{	\
	return m_pool_allocator.acquire(size);	\
}	\
void T::operator delete(void *p, size_t size)	\
{	\
	return m_pool_allocator.release(p, size);	\
}


#endif // _POOL_ALLOCATOR_H_
