//! @file cycle_buffer.h


#ifndef _CYCLE_BUFFER_H_
#define _CYCLE_BUFFER_H_


//! @class Cycle_Buffer_T
//! @brief ѭ������
//!
//! ģ����� T ��ѭ���������д�ŵ���������, ��д��Ͷ�ȡʱ���ᷢ������, ���� T ����̫��
//! ģ����� MAX_COUNT ��ѭ��������������ŵ�Ԫ�ظ���
//! ���̷߳��ʴ���ʱҪȷ������д��ֻ��һ���߳�
template <typename T, int MAX_COUNT>
class Cycle_Buffer_T
{
public:
	Cycle_Buffer_T();
	~Cycle_Buffer_T();

	//! ��ȡ����
	//! @param data ����������
	//! @return ��ȡ���, true:��ȡ�ɹ�, false:��ȡʧ��,����Ϊ��
	bool read(T& data);

	//! д������
	//! @param data Ҫд�������
	//! @return д����, true:д��ɹ�, false:д��ʧ��,��������
	bool write(const T& data);

	//! ��ȡ��ǰbuffer�еĽ�����
	int size();

private:
	//! ����Ԫ�ؽ��
	T m_datas[MAX_COUNT];

//		volatile int _size;
	//! ���±�
	volatile int m_read_index;

	//! д�±�
	volatile int m_write_index;
};


template <typename T, int MAX_COUNT>
Cycle_Buffer_T<T, MAX_COUNT>::Cycle_Buffer_T()
{
	m_read_index = 0;
	m_write_index = 0;
}


template <typename T, int MAX_COUNT>
Cycle_Buffer_T<T, MAX_COUNT>::~Cycle_Buffer_T()
{
}


template <typename T, int MAX_COUNT>
bool Cycle_Buffer_T<T, MAX_COUNT>::read(T& data)
{
	if (m_read_index == m_write_index) {
		return false;
	}

	data = m_datas[m_read_index];

	if (m_read_index < MAX_COUNT - 1) {
		m_read_index++;
	}
	else {
		m_read_index = 0;
	}

//		_size--;
	return true;
}


template <typename T, int MAX_COUNT>
bool Cycle_Buffer_T<T, MAX_COUNT>::write(const T& data)
{
	if (m_read_index == 0)
	{
		if (m_write_index == (MAX_COUNT - 1)) {
			return false;
		}
	}
	else
	{
		if (m_write_index == (m_read_index - 1)) {
			return false;
		}
	}

	m_datas[m_write_index] = data;

	if (m_write_index < MAX_COUNT - 1) {
		m_write_index++;
	}
	else {
		m_write_index = 0;
	}
//		_size++;

	return true;
}

template <typename T, int MAX_COUNT>
int Cycle_Buffer_T<T, MAX_COUNT>::size()
{
	//����m_write_index, m_read_index��Ϊvolatile,�˴�������޶ȵĵõ���ȷ������ֵ
	int tmp_write_index = m_write_index;
	int tmp_read_index = m_read_index;

	return tmp_write_index >= tmp_read_index ? (tmp_write_index-tmp_read_index): tmp_write_index+(MAX_COUNT-tmp_read_index);
}


#endif // _CYCLE_BUFFER_H_
