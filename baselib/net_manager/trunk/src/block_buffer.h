//! @file block_buffer.h


#ifndef _BLOCK_BUFFER_H_
#define _BLOCK_BUFFER_H_


#include <string.h>
#include <assert.h>

#include "log.h"


//! @class Block_Buffer_T
//! @brief ���ݿ黺��
//!
//! ģ����� BUFFER_LENGTH �ǻ���������
template <int BUFFER_LENGTH>
class Block_Buffer_T
{
public:
	Block_Buffer_T();
	~Block_Buffer_T();

	//! ȡ��ָ��
	char* rd_ptr();

	//! ��ָ��ǰ��
	void rd_ptr(int n);

	//! ȡдָ��
	char* wr_ptr();

	//! дָ��ǰ��
	void wr_ptr(int n);

	//! ���泤��
	int buffer_length();

	//! �������ݳ���
	int data_length();

	//! ʣ��ռ䳤��
	int space_length();
	
	//! ʵ�ʳ���
	int length();

	//! ���տռ�
	void recycle();

	//! ��չbuffer�ռ�
	void extend(int new_length);
	
private:
	//! ������
	char* m_buffer;

	//! ��λ��
	int m_read_index;

	//! дλ��
	int m_write_index;

	//! ��ǰbufferʵ�ʴ�С
	int _length;
};


template <int BUFFER_LENGTH>
Block_Buffer_T<BUFFER_LENGTH>::Block_Buffer_T()
{
	m_read_index = 0;
	m_write_index = 0;
	m_buffer = new char[BUFFER_LENGTH];
	_length = BUFFER_LENGTH;
}

template <int BUFFER_LENGTH>
Block_Buffer_T<BUFFER_LENGTH>::~Block_Buffer_T()
{
	delete[] m_buffer;
}

template <int BUFFER_LENGTH>
char* Block_Buffer_T<BUFFER_LENGTH>::rd_ptr()
{
	return m_buffer + m_read_index;
}

template <int BUFFER_LENGTH>
void Block_Buffer_T<BUFFER_LENGTH>::rd_ptr(int n)
{
	assert((m_write_index - m_read_index) >= n);
	m_read_index += n;
}

template <int BUFFER_LENGTH>
char* Block_Buffer_T<BUFFER_LENGTH>::wr_ptr()
{
	return m_buffer + m_write_index;
}

template <int BUFFER_LENGTH>
void Block_Buffer_T<BUFFER_LENGTH>::wr_ptr(int n)
{
	assert((_length - m_write_index) >= n);
	m_write_index += n;
}

template <int BUFFER_LENGTH>
int Block_Buffer_T<BUFFER_LENGTH>::buffer_length()
{
	return _length;
}

template <int BUFFER_LENGTH>
int Block_Buffer_T<BUFFER_LENGTH>::data_length()
{
	return (m_write_index - m_read_index);
}

template <int BUFFER_LENGTH>
int Block_Buffer_T<BUFFER_LENGTH>::space_length()
{
	return (_length - m_write_index);
}

template <int BUFFER_LENGTH>
int Block_Buffer_T<BUFFER_LENGTH>::length()
{
	return _length;
}

template <int BUFFER_LENGTH>
void Block_Buffer_T<BUFFER_LENGTH>::recycle()
{
	int data_len = m_write_index - m_read_index;
	if (0 == data_len) {
		m_write_index = 0;
		m_read_index = 0;
	}
	else {
		memmove(m_buffer, m_buffer + m_read_index, data_len);
		m_read_index = 0;
		m_write_index = data_len;
	}
}

template <int BUFFER_LENGTH>
void Block_Buffer_T<BUFFER_LENGTH>::extend(int new_length)
{
	int data_len = m_write_index - m_read_index;
	char* ext_buffer = new char[new_length+data_len];

	LOG_INFO("Block_Buffer_T extend from %d to %d for datalen:%d newlength:%d",
					_length, new_length+data_len,
					data_len, new_length);
	
	if(data_len == 0)
	{
		m_write_index = 0;
		m_read_index = 0;		
	}
	else
	{
		memmove(ext_buffer, m_buffer + m_read_index, data_len);
		m_read_index = 0;
		m_write_index = data_len;
	}
	
	delete[] m_buffer;
	m_buffer = ext_buffer;
	_length = new_length+data_len;
}



#endif // _BLOCK_BUFFER_H_
