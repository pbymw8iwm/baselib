//! @file sock_stream.h


#ifndef _SOCK_STREAM_H_
#define _SOCK_STREAM_H_

#include "net_event.h"
#include "event_handler.h"
#include "inet_addr.h"
#include "block_buffer.h"
#include "pool_allocator.h"
#include "config.h"
#include "net_manager.h"

class Net_Manager;
class Packet_Splitter;


//! @class SOCK_Stream
//! @brief tcpͨ��������
class SOCK_Stream : public Event_Handler
{
private:
	//! ���캯��
	//! @param id ͨ��id
	//! @param net_manager ���������
	//! @param packet_splitter �����
	//! @param socket �׽���
	//! @param local_addr ���ص�ַ
	//! @param remote_addr �Զ˵�ַ
	SOCK_Stream(uint32_t id, Net_Manager *net_manager, Packet_Splitter *packet_splitter, SOCKET socket, const INET_Addr& local_addr, 
		const INET_Addr& remote_addr, void* pUserData);

public:
	virtual ~SOCK_Stream();

	DECLARE_ALLOCATOR(SOCK_Stream, SOCK_STREAM_POOL_COUNT)

public:
	//! �ر�����
	void close_stream();

	//! ��ȡͨ��id
	//! @return ͨ��id
	virtual uint32_t get_id();

	//! ��ȡsocket���
	//! @return socket���
	virtual SOCKET get_handle();

	//! ��
	//! @return ������ 0:��������, -1: ���ӱ��Է��ر�, -2:�����쳣
	virtual int handle_input();

	//! д
	//! @return ������ 0:��������, -1: �����쳣
	virtual int handle_output();

	//! ���ӶϿ�
	virtual int handle_exception();

	//! ��ʱ
	virtual int handle_timeout();

	//! ���ӹر�
	virtual int handle_close();

	//! �ύ��������
	virtual int post_packet(Net_Packet *send_packet);

public:
	friend class SOCK_Acceptor;
	friend class SOCK_Connector;
private:
	int realSend();
private:
	//! ͨ��id
	uint32_t m_id;

	//! socket���
	SOCKET m_socket;

	//! ���ؼ�����ַ
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

	//!��Щ���ܰ�������ȫcopy�����ͻ����packet
	Net_Packet *m_current_send_packet;
	//! ��ǰ���ڷ��͵������Ѿ����͵��ֽ���
	int m_current_send_length;
	
	//! �����ӵ��¼�������ָ��
	void* m_UserData;
private:
	Net_Event* m_PartDataEvent;
	int m_PartDataLeftLen;
};


#endif // _SOCK_STREAM_H_
