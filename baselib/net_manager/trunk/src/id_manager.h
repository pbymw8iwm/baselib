//! @file id_manager.h


#ifndef _ID_MANAGER_H_
#define _ID_MANAGER_H_


#include "types.h"
#include "cycle_buffer.h"


//! @enum ID_TYPE
//! @brief ����ͨ��id����
enum ID_TYPE
{
	ID_UDP,
	ID_TCP_CONNECTOR,
	ID_TCP_ACCEPTOR,
	ID_TCP_STREAM
};


//! @class Id_Manager
//! @brief ����ͨ��id������
//!
//! ����ά�������㹻������ͨ��id, ʵ�����й����в����ܳ���id�þ������
class Id_Manager
{
public:
	Id_Manager();
	~Id_Manager();

	//! ����һ������ͨ��id
	//! @param type Ҫ�����ͨ������
	//! @return ͨ��id 0:ʧ��,id�þ�,  >0:�ɹ�
	uint32_t acquire(ID_TYPE type);

	//! �ͷ�����ͨ��id
	//! @param id ����ͨ��id
	void release(uint32_t id);

private:
	static const uint32_t Q1_B = 1;
	static const uint32_t Q1_E = 100000;

	static const uint32_t Q2_B = 100001;
	static const uint32_t Q2_E = 200000;

	static const uint32_t Q3_B = 200001;
	static const uint32_t Q3_E = 300000;

	static const uint32_t Q4_B = 300001;
	static const uint32_t Q4_E = 1000000;

	//! ����ͨ��id����1
	typedef Cycle_Buffer_T<uint32_t, Q1_E - Q1_B + 1> Id_Queue1;
	Id_Queue1 *m_id_queue1;

	//! ����ͨ��id����2
	typedef Cycle_Buffer_T<uint32_t, Q2_E - Q2_B + 1> Id_Queue2;
	Id_Queue2 *m_id_queue2;

	//! ����ͨ��id����3
	typedef Cycle_Buffer_T<uint32_t, Q3_E - Q3_B + 1> Id_Queue3;
	Id_Queue3 *m_id_queue3;

	//! ����ͨ��id����1
	typedef Cycle_Buffer_T<uint32_t, Q4_E - Q4_B + 1> Id_Queue4;
	Id_Queue4 *m_id_queue4;
};


#endif // _ID_MANAGER_H_
