//! @file epoll_reactor.h


#ifndef _EPOLL_REACTOR_H_
#define _EPOLL_REACTOR_H_

#ifndef WIN32

#include "reactor.h"
#include "cycle_buffer.h"
#include <sys/epoll.h>
#include <map>

using namespace std;


//! @class Epoll_Reactor
//! @brief EPOLL�汾�ķ�Ӧ��
class Epoll_Reactor : public Reactor
{
public:
	Epoll_Reactor();
	virtual ~Epoll_Reactor();

public:
	//! ��reactor
	//! @return 0:�ɹ�, <0:ʧ��
	int open_reactor();

	//! �ر�reactor
	//! @return 0:�ɹ�, <0:ʧ��
	int close_reactor();

	//! �¼���ѭ��
	//! @return >=0:�����¼��ĸ���, <0:��Ӧ������
	virtual int run_reactor_event_loop();

	//! ֹͣ�¼���ѭ������������ע��Ĵ�����
	virtual int end_reactor_event_loop();

	//! ע��һ���¼�����
	//! @param event_handler �¼�������
	//! @param masks Ҫ�������¼�
	//! @return 0:�ɹ�, <0:ʧ��
	virtual int register_handler(Event_Handler *event_handler, uint32_t masks);

	//! ɾ��һ���¼�����
	//! @param event_handler �¼�������
	//! @param masks Ҫɾ�����¼�
	//! @return 0:�ɹ�, <0:ʧ��
	virtual int remove_handler(Event_Handler *event_handler, uint32_t masks);

	//! ɾ��һ��sock�ϵ����м���
	//! @param event_handler �¼�������
	//! @return 0:�ɹ�, <0:ʧ��
	virtual int delete_handler(Event_Handler *event_handler);

	//! ���ó�ʱ
	//! @param id ����ͨ��
	//! @param timeout ��ʱʱ��(��)
	//! @return 0:�ɹ�, <0:ʧ��
	virtual int set_timeout(uint32_t id, int timeout);

	//! ȡ����ʱ
	//! @param id ����ͨ��
	//! @return 0:�ɹ�, <0:ʧ��
	virtual int cancel_timeout(uint32_t id);

	//! ֪ͨ�ر�
	//! @param id ͨ��id
	//! @return 0:�ɹ�, <0:ʧ��
	virtual int notify_close(uint32_t id);

	//! ȡͨ���¼�������
	//! @param id ͨ��id
	//! @return �¼�������
	virtual Event_Handler* get_event_handler(uint32_t id);

private:
	//! �������(20��)
	static const int MAX_HANDLER = 200000;

	//! epoll������
	int m_epfd;

	//! epoll���ص��¼�
	epoll_event *m_events;
};

#endif

#endif // _EPOLL_REACTOR_H_
