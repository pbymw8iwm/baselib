//! @file net_manager.h


#ifndef _NET_MANAGER_H_
#define _NET_MANAGER_H_


#include "types.h"
#include "config.h"
#include "cycle_buffer.h"
#include "net_thread.h"
#include "id_manager.h"
#include "event_handler.h"
#include "inet_addr.h"
#include "net_packet.h"
#include "net_event.h"
#include "net_event_queue.h"
#include "packet_splitter.h"

#ifdef WIN32	// for windows
  #include "select_reactor.h"
  //! windowsƽ̨��ʹ��select
  typedef Select_Reactor Net_Reactor;
#define NETBUF_SIZE 81920
#else			// for linux
  //! linuxƽ̨��ʹ��epoll
  #include "epoll_reactor.h"
  typedef Epoll_Reactor Net_Reactor;
#define NETBUF_SIZE 81920
#endif

  //! @typedef Net_Send_Task_Queue
  //! @brief ��������ķ����������
  //!
  //! �˶��в����̰߳�ȫ
  //! ��������Ϊ100��
  typedef Cycle_Buffer_T<Net_Packet*, MAX_NET_SEND_TASK_COUNT> Net_Send_Packet_Queue;


  //! @typedef Socket_Send_Task_Queue
  //! @brief ĳ������ͨ���ķ����������
  //!
  //! �˶��в����̰߳�ȫ
  //! ��������Ϊ1��
  typedef Cycle_Buffer_T<Net_Packet*, MAX_SOCKET_SEND_TASK_COUNT> Socket_Send_Packet_Queue;

//! @class Net_Manager
//! @brief ���������
class Net_Manager
{
public:
	Net_Manager();
	~Net_Manager();

public:
	//! ��������������߳�
	//! @return 0:�ɹ�, -1ʧ��
	int start();

	//! ֹͣ����������߳�
	//! @return 0:�ɹ�, -1ʧ��
	int stop();

	//! ����һ��updͨ��
	//! @param local_addr upd���ذ󶨵�ַ
	//! @param pUserData �û���������ݣ���netevent�з��ظ��û���һ�����������ӵ��¼�������ָ��
	//! @param netbufsize ����ײ㻺������С
	//! @return ͨ��id, >0:�ɹ�, 0ʧ��
	uint32_t create_udp(const INET_Addr& local_addr, void* pUserData, int netbufsize = NETBUF_SIZE);

	//! ����һ��updͨ��
	//! @param local_ip upd���ذ�ip
	//! @param local_port upd���ذ�port
	//! @param pUserData �û���������ݣ���netevent�з��ظ��û���һ�����������ӵ��¼�������ָ��
	//! @param netbufsize ����ײ㻺������С
	//! @return ͨ��id, >0:�ɹ�, 0ʧ��
	uint32_t create_udp(const char *local_ip, int local_port, void* pUserData, int netbufsize = NETBUF_SIZE);

	//! ����һ��tcp clientͨ��
	//! @param remote_addr tcp�Զ˵�ַ
	//! @param packet_splitter tcp�����
	//! @param pUserData �û���������ݣ���netevent�з��ظ��û���һ�����������ӵ��¼�������ָ��
	//! @param timeout ���ӳ�ʱʱ��(��)
	//! @param netbufsize ����ײ㻺������С
	//! @return ͨ��id, >0:�ɹ�, 0ʧ��
	uint32_t create_tcp_client(const INET_Addr& remote_addr, Packet_Splitter *packet_splitter, 
		void* pUserData, int timeout, int netbufsize = NETBUF_SIZE);

	//! ����һ��tcp clientͨ��
	//! @param remote_ip �Զ�ip
	//! @param remote_port �Զ�port
	//! @param packet_splitter tcp�����
	//! @param pUserData �û���������ݣ���netevent�з��ظ��û���һ�����������ӵ��¼�������ָ��
	//! @param timeout ���ӳ�ʱʱ��(��)
	//! @param netbufsize ����ײ㻺������С
	//! @return ͨ��id, >0:�ɹ�, 0ʧ��
	uint32_t create_tcp_client(const char *remote_ip, int remote_port, Packet_Splitter *packet_splitter, 
		void* pUserData, int timeout, int netbufsize = NETBUF_SIZE);

	//! ����һ��tcp serverͨ��
	//! @param local_addr tcp���ؼ�����ַ
	//! @param packet_splitter tcp�����
	//! @param pUserData �û���������ݣ���netevent�з��ظ��û���һ�����������ӵ��¼�������ָ��
	//! @param netbufsize ����ײ㻺������С
	//! @return ͨ��id, >0:�ɹ�, 0ʧ��
	uint32_t create_tcp_server(const INET_Addr& local_addr, Packet_Splitter *packet_splitter, void* pUserData, int netbufsize = NETBUF_SIZE);

	//! ����һ��tcp serverͨ��
	//! @param local_ip tcp���ؼ���ip
	//! @param local_port tcp���ؼ���port
	//! @param packet_splitter tcp�����
	//! @param pUserData �û���������ݣ���netevent�з��ظ��û���һ�����������ӵ��¼�������ָ��
	//! @param netbufsize ����ײ㻺������С
	//! @return ͨ��id, >0:�ɹ�, 0ʧ��
	uint32_t create_tcp_server(const char *local_ip, int local_port, Packet_Splitter *packet_splitter, void* pUserData, int netbufsize = NETBUF_SIZE);

	//! ֪ͨɾ������ͨ��
	//! @param id ͨ��id
	//! @return 0:�ɹ� <0:ʧ��
	int delete_net(uint32_t id);

	//! �������ݰ�
	//! @warning ����˵��óɹ�, packet����������������ͷ�; ����˵���ʧ��, packet���ɵ��÷������ͷ�
	//! @param id ͨ��id
	//! @param packet ���ݰ�
	//! @param remote_addr �Զ˵�ַ(udp��Ҫʹ�ô˵�ַ, tcp���Դ˵�ַ)
	//! @return ���ͽ��, 0:�ɹ�, -1:ʧ��(ͨ��������), -2:ʧ��(��������)
	int send_packet(uint32_t id, Net_Packet* packet, const INET_Addr& remote_addr);

	//! �������ݰ�
	//! @warning ����˵��óɹ�, packet����������������ͷ�; ����˵���ʧ��, packet���ɵ��÷������ͷ�
	//! @param id ͨ��id
	//! @param packet ���ݰ�
	//! @param remote_ip �Զ�ip
	//! @param remote_port �Զ�port
	//! @return ���ͽ��, 0:�ɹ�, -1:ʧ��(ͨ��������), -2:ʧ��(��������)
	int send_packet(uint32_t id, Net_Packet* packet, const char *remote_ip, int remote_port);

	//! �������ݰ�(ֻ������tcp)
	//! @warning ����˵��óɹ�, packet����������������ͷ�; ����˵���ʧ��, packet���ɵ��÷������ͷ�
	//! @param id ͨ��id
	//! @param packet ���ݰ�
	//! @return ���ͽ��, 0:�ɹ�, -1:ʧ��(ͨ��������), -2:ʧ��(��������)
	int send_packet(uint32_t id, Net_Packet* packet);

	//! ȡ�����¼�
	//! @warning �ͻ���Ӧѭ�����ô˺�����ȡ�����¼�, ���ڴ������ÿ�������¼������ͷ�
	//! @return �����¼�, û�������¼�ʱ����NULL
	Net_Event* get_event();

	//! ��ȡδ����ķ����¼�������
	//! @return �����¼�������
	int get_send_size();

	//! ��ȡδ����Ľ����¼�������
	//! @return �����¼�������
	int get_recv_size();

public:
	friend class Net_Thread;
	friend class SOCK_Dgram;
	friend class SOCK_Acceptor;
	friend class SOCK_Connector;
	friend class SOCK_Stream;

private:
	//! ����һ�������¼�
	//! @param net_event �����¼�
	void put_event(Net_Event* net_event);

	//! ȡ��������
	//! @return ��������, û�з�������ʱ����NULL
	Net_Packet* get_send_packet();

	//! �������(reactor����)
	void on_net_error();

private:
	//! ����״̬ 0:ֹͣ, 1:����, 2:�쳣
	int m_status;

	//! ����������߳�
	Net_Thread* m_net_thread;

	//! ͨ��id������
	Id_Manager m_id_manager;

	//! ��Ӧ��
	Net_Reactor m_reactor;

	//! �����¼�����
	Net_Event_Queue *m_net_event_queue;

	//! �������������
	Net_Send_Packet_Queue *m_send_packet_queue;
};


#endif // _NET_MANAGER_H_
