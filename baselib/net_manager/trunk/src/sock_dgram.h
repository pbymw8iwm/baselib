//! @file sock_dgram.h


#ifndef _SOCK_DGRAM_H_
#define _SOCK_DGRAM_H_

#include "net_event.h"
#include "event_handler.h"
#include "inet_addr.h"
#include "net_manager.h"
#include "block_buffer.h"
class Net_Manager;


//! @class SOCK_Dgram
//! @brief updͨ��������
class SOCK_Dgram : public Event_Handler
{
public:
	//! ���캯��
	//! @param net_manager ���������
	SOCK_Dgram(Net_Manager *net_manager, void* pUserData);

	//! ��������
	virtual ~SOCK_Dgram();

public:
	//! ����updͨ��
	//! @param local_addr upd���ذ󶨵�ַ
	//! @param handler �����ӵ��¼�������ָ��
	//! @return ���, 0:�ɹ�, -1ʧ��
	int create_udp(const INET_Addr& local_addr, int netbufsize);
	int create_udp_server(const string serverIp, const int serverPort, int netbufsize);
	//! �ر�ͨ��
	void close_udp();

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

	//! ���ذ󶨵�ַ
	INET_Addr m_local_addr;
	//! �Զ˵�ַ
	INET_Addr m_remote_addr;
	//! ���������
	Net_Manager *m_net_manager;

	//! �����
	Packet_Splitter *m_packet_splitter;
	//! ���ܻ���
	Block_Buffer_T<RECV_BUFFER_LENGTH> m_recv_buffer;
	//!���ͻ���
	Block_Buffer_T<RECV_BUFFER_LENGTH> m_sendBuffer;


	//! �������������
	Socket_Send_Packet_Queue m_send_packet_queue;

	//! ��ǰ���ڷ��͵�����
	Net_Packet *m_current_send_packet;
	
	//! ��ǰ���ڷ��͵������Ѿ����͵��ֽ���
	int m_current_send_length;

	//! �����ӵ��¼�������ָ��
	void* m_UserData;
private:
	int realSend();
};


#endif // _SOCK_DGRAM_H_
