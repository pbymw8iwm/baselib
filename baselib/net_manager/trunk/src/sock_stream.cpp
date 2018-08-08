

#include "sock_stream.h"
#include "net_manager.h"
#include "log.h"
#include <assert.h>


// class SOCK_Stream
SOCK_Stream::SOCK_Stream(uint32_t id, Net_Manager *net_manager, Packet_Splitter *packet_splitter, SOCKET socket, const INET_Addr& local_addr, 
						 const INET_Addr& remote_addr, void* pUserData)
{
	m_id = id;
	m_socket = socket;
	m_local_addr = local_addr;
	m_remote_addr = remote_addr;
	m_net_manager = net_manager;
	m_packet_splitter = packet_splitter;
	m_current_send_packet = NULL;
	m_current_send_length = 0;
	m_UserData = pUserData;
	m_PartDataEvent = NULL;
	m_PartDataLeftLen = 0;
}

SOCK_Stream::~SOCK_Stream()
{
	if (0 != m_id) {
		m_net_manager->m_id_manager.release(m_id);
	}

	//���δ��������ݰ�
	if (m_current_send_packet != NULL)
	{
		delete m_current_send_packet;
		m_current_send_packet = NULL;
	}
	
	while(m_send_packet_queue.read(m_current_send_packet))
	{
		delete m_current_send_packet;
	}
}

void SOCK_Stream::close_stream()
{
	if (INVALID_SOCKET != m_socket) {
		close(m_socket);
		m_socket = INVALID_SOCKET;
	}
}

uint32_t SOCK_Stream::get_id()
{
	return m_id;
}

SOCKET SOCK_Stream::get_handle()
{
	return m_socket;
}

int SOCK_Stream::handle_input()
{
	while (true)
	{
		int rc = recv(m_socket, m_recv_buffer.wr_ptr(), m_recv_buffer.space_length(), 0);
		if (rc > 0)
		{
			m_recv_buffer.wr_ptr(rc);

			if (m_PartDataEvent != NULL)
			{
				if (m_recv_buffer.data_length() < m_PartDataLeftLen)
				{
					m_PartDataEvent->packet.write_data(m_recv_buffer.rd_ptr(), m_recv_buffer.data_length());
					m_PartDataLeftLen -= m_recv_buffer.data_length();
					m_recv_buffer.rd_ptr(m_recv_buffer.data_length());
					m_recv_buffer.recycle();
					continue;
				}
		
				m_PartDataEvent->packet.write_data(m_recv_buffer.rd_ptr(), m_PartDataLeftLen);
				m_PartDataEvent->packet.movetobegin();

				m_net_manager->put_event(m_PartDataEvent);


				m_PartDataEvent = NULL;
				m_recv_buffer.rd_ptr(m_PartDataLeftLen);
				m_PartDataLeftLen = 0;
			}
			
			int packet_begin = 0;
			int packet_len = 0;

			// ѭ�����
			while (true)
			{
				packet_len = 0;
				int split_result = m_packet_splitter->split(m_recv_buffer.rd_ptr(), m_recv_buffer.data_length(), packet_begin, packet_len);
				if (1 == split_result)
				{
//						if (packet_len > MAX_PACKET_LENGTH) {
//							// Э���
//							LOG(ERROR)("SOCK_Stream::handle_input error, split error, packet_len:%d", packet_len);
//							return -2;
//						}

					// got a packet
					
					Net_Event *net_event = new Net_Event;

					net_event->net_event_type = TYPE_DATA;
					net_event->id = m_id;
					net_event->new_id = 0;
					net_event->local_addr = m_local_addr;
					net_event->remote_addr = m_remote_addr;
					net_event->UserData = m_UserData;
					net_event->packet.write_data(m_recv_buffer.rd_ptr() + packet_begin, packet_len);
					net_event->packet.movetobegin();
					m_net_manager->put_event(net_event);

					m_recv_buffer.rd_ptr(packet_begin + packet_len);
				}
				else if (0 == split_result)
				{
					// no packet in buf
					if(packet_len > m_recv_buffer.length())
					{
						//��������һ���ϴ�Ļ�����,������ǰ����������ת�ƹ�ȥ
						//m_recv_buffer.extend(packet_len);
						m_PartDataEvent = new Net_Event;
						m_PartDataEvent->net_event_type = TYPE_DATA;
						m_PartDataEvent->id = m_id;
						m_PartDataEvent->new_id = 0;
						m_PartDataEvent->local_addr = m_local_addr;
						m_PartDataEvent->remote_addr = m_remote_addr;
						m_PartDataEvent->UserData = m_UserData;
						m_PartDataLeftLen = packet_len - m_recv_buffer.data_length();
						m_PartDataEvent->packet.write_data(m_recv_buffer.rd_ptr() + packet_begin, m_recv_buffer.data_length());
						m_recv_buffer.rd_ptr(m_recv_buffer.data_length());
					}
					
					break;
				}
				else
				{
					// Э���
					LOG(ERROR)("SOCK_Stream::handle_input error, split error, split_result:%d", split_result);
					return -2;
				}

				if (0 == m_recv_buffer.data_length())
				{
					// buf is empty, no packet in buf
					break;
				}
			}

			if ((m_recv_buffer.data_length() == 0) || (m_recv_buffer.space_length() == 0)
				|| (m_recv_buffer.data_length()+m_recv_buffer.space_length())<packet_len)
			{
				m_recv_buffer.recycle();
			}
		}
		else if (rc == 0)
		{
			// close
			LOG(INFO)("SOCK_Stream::handle_input, socket close by peer");
			return -1;
		}
		else
		{
			if (NETMANAGER_EAGAIN == error_no()) {
				return 0;
			}
			else {
				// exception
				LOG(WARN)("SOCK_Stream::handle_input error, recv error, errno:%d", error_no());
				return -2;
			}
		}
	}

	return 0;
}

int SOCK_Stream::handle_output()
{
#ifdef WIN32
	if (m_sendBuffer.data_length() == 0 && m_send_packet_queue.size() == 0)
	{
		m_net_manager->m_reactor.remove_handler(this, MASK_WRITE);
	}
#else
	m_net_manager->m_reactor.remove_handler(this, MASK_WRITE);
#endif

	LOG(DEBUG)("call handle_output");
	if (m_sendBuffer.data_length() == 0 && m_send_packet_queue.size() == 0)
	{
		return 0;
	}
	
	int rc = realSend();
	if (-1 == rc)
	{
		// ���ӹر�
		reactor()->delete_handler(this);
		handle_close();
		return -1;
	}
	else if (-2 == rc)
	{
		// �����쳣
		reactor()->delete_handler(this);
		handle_exception();
		return -2;
	}
	else if(-3 == rc)
	{	

	}


/*
	//��ʱ����ʱ���Ѷ����е����ݺϳ�һ�������ͣ�Ч�ʻ����Щ
	if (m_current_send_packet != NULL)
	{
		int rc = realSend();
		if (rc != 0)
		{
			return rc;
		}
	}

	assert(m_current_send_packet == NULL);
	assert(m_current_send_length == 0);

	while (true)
	{
		bool brc = m_send_packet_queue.read(m_current_send_packet);
		if (false == brc) {
			// ���Ͷ����ѿ�
			break;
		}
		int rc = realSend();
		if (rc != 0)
		{
			return rc;
		}
	}

	assert(m_current_send_packet == NULL);
	assert(m_current_send_length == 0);
*/
	return 0;
}

int SOCK_Stream::handle_exception()
{
	if (INVALID_SOCKET != m_socket) {
		close(m_socket);
		m_socket = INVALID_SOCKET;
	}

	Net_Event *net_event = new Net_Event;

	net_event->net_event_type = TYPE_EXCEPTION;
	net_event->id = m_id;
	net_event->new_id = 0;
	net_event->local_addr = m_local_addr;
	net_event->remote_addr = m_remote_addr;
	net_event->UserData = m_UserData;

	m_net_manager->put_event(net_event);

	return 0;
}

int SOCK_Stream::handle_close()
{
	if (INVALID_SOCKET != m_socket) {
		LOG(DEBUG)("SOCK_Stream::handle_close, net:%d, m_current_send_task:%p, m_send_task_queue:%d",
					get_id(),
					m_current_send_packet, m_send_packet_queue.read(m_current_send_packet));
		close(m_socket);
		m_socket = INVALID_SOCKET;
	}

	if (notify_close)
	{
		return 0;
	}
	
	Net_Event *net_event = new Net_Event;

	net_event->net_event_type = TYPE_CLOSE;
	net_event->id = m_id;
	net_event->new_id = 0;
	net_event->local_addr = m_local_addr;
	net_event->remote_addr = m_remote_addr;
	net_event->UserData = m_UserData;

	m_net_manager->put_event(net_event);

	return 0;
}

int SOCK_Stream::handle_timeout()
{
	if (INVALID_SOCKET != m_socket) {
		close(m_socket);
		m_socket = INVALID_SOCKET;
	}

	Net_Event *net_event = new Net_Event;

	net_event->net_event_type = TYPE_TIMEOUT;
	net_event->id = m_id;
	net_event->new_id = 0;
	net_event->local_addr = m_local_addr;
	net_event->remote_addr = m_remote_addr;
	net_event->UserData = m_UserData;

	m_net_manager->put_event(net_event);

	return 0;
}

int SOCK_Stream::post_packet(Net_Packet* send_packet)
{
	bool bSend = false;
	int nFreeSpace = m_sendBuffer.space_length();
	//����û�з�����
	if (m_sendBuffer.data_length() > 0)
	{
		if (m_current_send_packet == NULL)
		{
			if (nFreeSpace > 0)
			{
				if (nFreeSpace >= send_packet->getdatalen())
				{
					send_packet->readdata(m_sendBuffer.wr_ptr(), send_packet->getdatalen());
					m_sendBuffer.wr_ptr(send_packet->getdatalen());
					delete send_packet;
				}
				else
				{
					send_packet->readdata(m_sendBuffer.wr_ptr(), nFreeSpace);
					m_sendBuffer.wr_ptr(nFreeSpace);
					m_current_send_packet = send_packet;
					m_current_send_length = nFreeSpace;
				}
			}
			else
			{
				m_current_send_packet = send_packet;
				m_current_send_length = 0;
			}			
		}
		else
		{
			//��ʱ�������������е�ǰûcopy�������е�����
			bool brc = m_send_packet_queue.write(send_packet);
			if (true != brc) {
				// �����þ�
				LOG(ERROR)("SOCK_Stream::send_data error, send task queue is full, packet lost,net_id%d,peer ip:0X%08x,port:%u",m_id,m_remote_addr.get_addr(),m_remote_addr.get_port());
				delete send_packet;
				return 0;
			}
		}

		if (m_send_packet_queue.size() >= (MAX_SOCKET_SEND_TASK_COUNT / 2))
		{
			bSend = true;
		}		
	}
	else
	{
		if (nFreeSpace >= send_packet->getdatalen())
		{
			send_packet->readdata(m_sendBuffer.wr_ptr(), send_packet->getdatalen());
			m_sendBuffer.wr_ptr(send_packet->getdatalen());
			delete send_packet;
		}
		else
		{
			send_packet->readdata(m_sendBuffer.wr_ptr(), nFreeSpace);
			m_sendBuffer.wr_ptr(nFreeSpace);
			m_current_send_packet = send_packet;
			m_current_send_length = nFreeSpace;
		}
		bSend = true;
	}

	if (bSend)
	{
		int rc = realSend();
		if (-1 == rc)
		{
			// ���ӹر�
			reactor()->delete_handler(this);
			handle_close();
			return -1;
		}
		else if (-2 == rc)
		{
			// �����쳣
			reactor()->delete_handler(this);
			handle_exception();
			return -2;
		}
		else if(-3 == rc)
		{	

		}
	}
	
/*
	if (m_current_send_packet != NULL)
	{
		bool brc = m_send_packet_queue.write(send_packet);
		if (true != brc) {
			// �����þ�
			LOG(ERROR)("SOCK_Stream::send_data error, send task queue is full, packet lost,net_id%d,peer ip:0X%08x,port:%u",m_id,m_remote_addr.get_addr(),m_remote_addr.get_port());
			delete send_packet;
			return 0;
		}
	}
	else
	{
		m_current_send_packet = send_packet;
		int rc = realSend();
		if (-1 == rc)
		{
			// ���ӹر�
			reactor()->delete_handler(this);
			handle_close();
			return -1;
		}
		else if (-2 == rc)
		{
			// �����쳣
			reactor()->delete_handler(this);
			handle_exception();
			return -2;
		}
		else if(-3 == rc)
		{	

		}
	}
*/
	return 0;
}

int SOCK_Stream::realSend()
{
	/*
	�õ����͵����ݺ�������ͻ���Ϊ�գ���ʾ�Ѿ��������ˣ���ʱ��ȫ����Ӧ��Ϊ�յģ���������copy�����ͻ����У�
	���������ȫcopy��������packet���Ƹ�curpacket�����÷��ͺ������з��ͣ����ȫ�������꣬�����curpacket����
	��ʣ�������Ҳcopy�����ͻ��棬�������ͣ������������ɷ�����ϣ����ͻ���Ϊ�գ�curpacketҲΪ�ա�
	������ͻ��治Ϊ�գ���˵���������������ƣ���ʱӦ�÷Ž����У��������������������һ��ʱ�������һ�η��ͣ��Ա���
	��ѭ����û�м�ʱ���͵��������Ϊ����ļ�����ڴ�ѭ��֮���
	*/
	int rc = 0;
	while(m_sendBuffer.data_length() > 0)
	{
		rc = send(m_socket, m_sendBuffer.rd_ptr(), m_sendBuffer.data_length(), 0);
		if (rc > 0) {
			// ���ͳɹ�
			//m_current_send_length += rc;
			m_sendBuffer.rd_ptr(rc);
			if (m_sendBuffer.data_length() == 0)
			{
				m_sendBuffer.recycle();
				while(m_current_send_packet != NULL)
				{
					int nFreeSpace = m_sendBuffer.space_length();
					if (nFreeSpace >= (m_current_send_packet->getdatalen() - m_current_send_length))
					{
						m_current_send_packet->readdata(m_sendBuffer.wr_ptr(), m_current_send_packet->getdatalen() - m_current_send_length);
						m_sendBuffer.wr_ptr(m_current_send_packet->getdatalen() - m_current_send_length);
						delete m_current_send_packet;
						m_current_send_packet = NULL;
						m_current_send_length = 0;
					}
					else
					{
						m_current_send_packet->readdata(m_sendBuffer.wr_ptr(), nFreeSpace);
						m_sendBuffer.wr_ptr(nFreeSpace);
						m_current_send_length += nFreeSpace;
					}
					if (m_sendBuffer.space_length() == 0)
					{
						break;
					}
					if (m_current_send_packet == NULL)
					{
						bool brc = m_send_packet_queue.read(m_current_send_packet);
						if (false == brc) 
						{
							// ���Ͷ����ѿ�
							break;
						}
						m_current_send_length = 0;
					}
										
				}
			}
		}
		else {
			if (NETMANAGER_EAGAIN == error_no()) {
#ifdef WIN32
				m_net_manager->m_reactor.register_handler(this, MASK_WRITE);
#else
				m_net_manager->m_reactor.register_handler(this, MASK_READ | MASK_WRITE);
#endif
				LOG(WARN)("SOCK_Stream::handle_output error,net_id%d,peer ip:0X%08x,port:%u",m_id,m_remote_addr.get_addr(),m_remote_addr.get_port());
				return -3;	//����δд�꣬��Ҫ�ȴ�����д��
			}
			else {
				LOG(WARN)("SOCK_Stream::handle_output error, send error, errno:%d", error_no());
				return -2;
			}
		}
	}
	return 0;
}


IMPLEMENT_ALLOCATOR(SOCK_Stream)

