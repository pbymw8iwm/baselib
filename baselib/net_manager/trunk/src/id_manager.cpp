
#include "id_manager.h"
#include <assert.h>


// class Id_Manager
Id_Manager::Id_Manager()
{
	m_id_queue1 = new Id_Queue1;
	for (uint32_t id = Q1_B; id <= Q1_E; id++) {
		m_id_queue1->write(id);
	}

	m_id_queue2 = new Id_Queue2;
	for (uint32_t id = Q2_B; id <= Q2_E; id++) {
		m_id_queue2->write(id);
	}

	m_id_queue3 = new Id_Queue3;
	for (uint32_t id = Q3_B; id <= Q3_E; id++) {
		m_id_queue3->write(id);
	}

	m_id_queue4 = new Id_Queue4;
	for (uint32_t id = Q4_B; id <= Q4_E; id++) {
		m_id_queue4->write(id);
	}
}

Id_Manager::~Id_Manager()
{
	delete m_id_queue1;
	delete m_id_queue2;
	delete m_id_queue3;
	delete m_id_queue4;
}

uint32_t Id_Manager::acquire(ID_TYPE type)
{
	bool rc = false;
	uint32_t id;

	switch (type)
	{
	case ID_UDP:
		rc = m_id_queue1->read(id);
		break;
	case ID_TCP_CONNECTOR:
		rc = m_id_queue2->read(id);
		break;
	case ID_TCP_ACCEPTOR:
		rc = m_id_queue3->read(id);
		break;
	case ID_TCP_STREAM:
		rc = m_id_queue4->read(id);
		break;
	default:
		break;
	}

	if (false == rc) {
		assert(true == false);	// �˴�id�������þ�
		return 0;
	}

	return id;
}

void Id_Manager::release(uint32_t id)
{
	if ((id >= Q1_B) && (id <= Q1_E)) {
		m_id_queue1->write(id);
	}
	else if ((id >= Q2_B) && (id <= Q2_E)) {
		m_id_queue2->write(id);
	}
	else if ((id >= Q3_B) && (id <= Q3_E)) {
		m_id_queue3->write(id);
	}
	else if ((id >= Q4_B) && (id <= Q4_E)) {
		m_id_queue4->write(id);
	}
	else {
		assert(true == false);
	}
}

