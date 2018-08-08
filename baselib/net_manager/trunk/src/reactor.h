//! @file reactor.h


#ifndef _REACTOR_H_
#define _REACTOR_H_

#include "types.h"
#include "List.h"

class Event_Handler;

class Reactor;

//! @class Reactor
//! @brief ��Ӧ��ģ��
class Reactor
{
	friend class HandlerIterator;
public:
	virtual ~Reactor();

	//! �¼���ѭ��
	//! @return >=0:�����¼��ĸ���, <0:��Ӧ������
	virtual int run_reactor_event_loop() = 0;

	//! ֹͣ�¼���ѭ������������ע��Ĵ�����
	virtual int end_reactor_event_loop();

	//! ע��һ���¼�����
	//! @param event_handler �¼�������
	//! @param masks Ҫ�������¼�
	//! @return 0:�ɹ�, <0:ʧ��
	virtual int register_handler(Event_Handler *event_handler, uint32_t masks) = 0;

	//! ɾ��һ���¼�����
	//! @param event_handler �¼�������
	//! @param masks Ҫɾ�����¼�
	//! @return 0:�ɹ�, <0:ʧ��
	virtual int remove_handler(Event_Handler *event_handler, uint32_t masks) = 0;

	//! ɾ��һ��sock�ϵ����м���
	//! @param event_handler �¼�������
	//! @return 0:�ɹ�, <0:ʧ��
	virtual int delete_handler(Event_Handler *event_handler) = 0;

	//! ���ó�ʱ
	//! @param id ����ͨ��
	//! @param timeout ��ʱʱ��(��)
	//! @return 0:�ɹ�, <0:ʧ��
	virtual int set_timeout(uint32_t id, int timeout) = 0;

	//! ȡ����ʱ
	//! @param id ����ͨ��
	//! @return 0:�ɹ�, <0:ʧ��
	virtual int cancel_timeout(uint32_t id) = 0;

	//! ֪ͨ�ر�ͨ��
	//! @param id ͨ��id
	//! @return 0:�ɹ�, <0:ʧ��
	virtual int notify_close(uint32_t id) = 0;

	//! ȡͨ���¼�������
	//! @param id ͨ��id
	//! @return �¼�������
	virtual Event_Handler* get_event_handler(uint32_t id) = 0;
public:
	void initHandlerTable();
	void finitHandlerTable();
protected:

	Event_Handler* getHandler(uint32_t id);
	void putHandler(Event_Handler* pHandler, uint32_t id);
	void removeHandler(uint32_t id);
	void removeHandler(Event_Handler* pHandler);
	int m_HandlerCount;

#ifdef _DEBUG
#define HANDLER_TABLE_SIZE		1027
#else
#define HANDLER_TABLE_SIZE		100003
#endif
	list_head HandlerTable[HANDLER_TABLE_SIZE];
};


#endif // _REACTOR_H_
