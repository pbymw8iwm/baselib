//! @file sock_acceptor.h


#ifndef _SOCK_ACCEPTOR_H_
#define _SOCK_ACCEPTOR_H_

#include "net_event.h"
#include "event_handler.h"
#include "inet_addr.h"

class Net_Manager;
class Packet_Splitter;


//! @class SOCK_Acceptor
//! @brief tcp����������
class SOCK_Acceptor : public Event_Handler
{
public:
	//! ���캯��
	//! @param net_manager ���������
	//! @param packet_splitter �����
	SOCK_Acceptor(Net_Manager *net_manager, Packet_Splitter *packet_splitter, void* pUserData);

	//! ��������
	virtual ~SOCK_Acceptor();

public:
	//! ����tcp������
	//! @param local_addr tcp���ؼ�����ַ
	//! @return ���, 0:�ɹ�, -1ʧ��
	int create_tcp_server(const INET_Addr& local_addr, int netbufsize);

	//! �ر�ͨ��
	void close_tcp_server();

	//! ��ȡͨ��id
	//! @return ͨ��id
	virtual uint32_t get_id();

	//! ��ȡsocket���
	//! @return socket���
	virtual SOCKET get_handle();

	//! �����
	//! @return ������ 0:��������, -1: ���ӱ��ر�, -2:�����쳣
	virtual int handle_input();

	//! ����д
	//! @return ������ 0:��������, -1: ���ӱ��ر�, -2:�����쳣
	virtual int handle_output();

	//! �����쳣
	virtual int handle_exception();

	//! ���ӹر�
	virtual int handle_close();

	//! ��ʱ
	virtual int handle_timeout();

	//! �ύ��������
	//! @param send_task �����͵�����
	virtual int post_packet(Net_Packet *send_packet);

private:
	//! ͨ��id
	uint32_t m_id;

	//! socket���
	SOCKET m_socket;

	//! ���ؼ�����ַ
	INET_Addr m_local_addr;

	//! ���������
	Net_Manager *m_net_manager;

	//! �����
	Packet_Splitter *m_packet_splitter;
	
	//!
	void* m_UserData;
};


#endif // _SOCK_ACCEPTOR_H_
