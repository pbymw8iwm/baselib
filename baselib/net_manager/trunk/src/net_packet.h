//! @file net_packet.h


#ifndef _NET_PACKET_H_
#define _NET_PACKET_H_

#include <string.h>
#include <string>

#include "types.h"
#include "config.h"
#include "os.h"
#include "pool_allocator.h"
#include "List.h"
#include "inet_addr.h"



class Net_Buff1
{
public:
	list_head item;
	//! ������
	char m_packet[MAX_PACKET_LENGTH];	
	DECLARE_ALLOCATOR(Net_Buff1, NET_PACKET_POOL_COUNT)
};

struct Bookmark 
{
	uint32_t absPos;
	int pos;
	Net_Buff1* netBuf;
};

//! @class Net_Packet
//! @brief �������װ��
class Net_Packet
{
public:
	Net_Packet();
	explicit Net_Packet(uint32_t size);
	//ע�⣺��copy���캯�����޸�packet��ֵ
	Net_Packet(Net_Packet& packet);
	~Net_Packet();
	
	DECLARE_ALLOCATOR(Net_Packet, NET_PACKET_POOL_COUNT)
//!�����߶�ȡ���ݽӿ�
public:
	void cloneData(Net_Packet* packet); //��¡Դpacket�����ݵ��Լ�������ȥ
public:
	inline Net_Packet& operator >>(uint8_t &data)
	{
		data = read_uint8();
		return *this;
	}
	inline Net_Packet& operator >>(uint16_t &data)
	{
		data = read_uint16();
		return *this;
	}

	inline Net_Packet& operator >>(uint32_t &data)
	{
		data = read_uint32();
		return *this;
	}

	inline Net_Packet& operator >>(uint64_t &data)
	{
		data = read_uint64();
		return *this;
	}

	inline Net_Packet& operator >>(float &data)
	{
		data = read_float();
		return *this;
	}

	inline Net_Packet& operator >>(double &data)
	{
		data = read_double();
		return *this;
	}

//!�����߲������ݽӿ�
public:

	inline Net_Packet& operator <<(uint8_t data)
	{
		write_uint8(data);
		return *this;
	}

	inline Net_Packet& operator <<(uint16_t data)
	{
		write_uint16(data);
		return *this;
	}

	inline Net_Packet& operator <<(uint32_t data)
	{
		write_uint32(data);
		return *this;
	}

	inline Net_Packet& operator <<(uint64_t data)
	{
		write_uint64(data);
		return *this;
	}

	inline Net_Packet& operator <<(float data)
	{
		write_float(data);
		return *this;
	}

	inline Net_Packet& operator <<(double data)
	{
		write_double(data);
		return *this;
	}

	inline Net_Packet& operator <<(const char *data)
	{
		int nlen = strlen(data);
		write_data(data, nlen);
		return *this;
	}

	inline Net_Packet& operator <<(const std::string& str)
	{
		write_data(str.c_str(), str.length());
		return *this;
	}

public:
	//!��ȡ��ǰ����λ��
	Bookmark getcurpos();

	Bookmark getBkByPos(uint32_t nabspos);
	//!��ȡ���ݳ���
	int getdatalen();
	inline bool good() const
	{
		return m_datagood;
	}
	//!����ڴ�����
	std::string dump();
	//��������
	void clear();
//!�����߶�ȡ���ݽӿ�
public:
	uint8_t read_uint8();
	uint8_t read_uint8(Bookmark pos);

	uint16_t read_uint16();
	uint16_t read_uint16(Bookmark pos);

	uint32_t read_uint32();
	uint32_t read_uint32(Bookmark pos);

	uint64_t read_uint64();
    uint64_t read_uint64(Bookmark pos);

	float read_float();
	float read_float(Bookmark pos);

	double read_double();
	double read_double(Bookmark pos);

	int read_string(std::string& str, uint16_t nDataLen);
	int read_string(std::string& str, uint16_t nDataLen, Bookmark pos);

	//!���ڲ�����copyһ�����ȵĵ�Ŀ�Ļ�������
	int readdata(char* pBuf, uint32_t nDataLen);
	int readdata(char* pBuf, uint32_t nDataLen, Bookmark pos);
//!�����߷������ݽӿ�
public:
	void write_uint8(uint8_t data);
	void write_uint8(uint8_t data, Bookmark pos);

	void write_uint16(uint16_t data);
	void write_uint16(uint16_t data, Bookmark pos);

	void write_uint32(uint32_t data);
	void write_uint32(uint32_t data, Bookmark pos);

	void write_uint64(uint64_t data);
	void write_uint64(uint64_t data, Bookmark pos);

	void write_float(float data);
	void write_float(float data, Bookmark pos);

	void write_double(double data);
	void write_double(double data, Bookmark pos);

	void write_string(const std::string& str);
	void write_string(const std::string& str, Bookmark pos);

	void write_data(const char* pbuf, uint32_t nsize);
	void write_data(const char* pbuf, uint32_t nsize, Bookmark pos);
private:
	//!��ʼ������
	void initdata(uint32_t size);
	//!���������С���ڴ��
	void allocate_buff(uint32_t size);
	//!ɾ���������ڴ��
	void release_buff();

	int appenddata(const char* pBuf, uint32_t nLen);

	bool islastnode() const
	{
		return m_CurBuf->item.next == &netBufhead;
	}

private:
	//!�ڴ������ͷ
	list_head netBufhead;
	//!��ǰ��ָ��
	Net_Buff1* m_CurBuf;
	//!��ǰ�����λ��
	int m_CurPos;
	//!��ǰ����λ��
	uint32_t m_CurAbsPos;
	//!��Ч���ݳ���
	uint32_t m_DataLength;
	//!���Ȳ����־
	bool m_datagood;
public:
	//! ͨ��id
	uint32_t id;

	//! �Զ˵�ַ
	INET_Addr remote_addr;
public:
	//!
	void movetobegin();

	//!���ص�ǰ���ָ��Ͷ�Ӧ���ʣ�����ݳ��� 
	char* get_rptr(int& ndataLen);
	//!�ƶ�����ָ��
	void move_rptr(int ndataLen);
public:

	enum NET_COMMAND
	{
		NET_TCP_ACCEPTOR_REGISTER,
		NET_TCP_CONNECTOR_REGISTER,
		NET_UDP_REGISTER,
		NET_DELETE
	};

	struct INTERNAL_CMD
	{
		uint32_t id;
		NET_COMMAND cmd;
		void* data;
		int mask;
		int timeout;
	} m_cmd;
};

#endif // _NET_PACKET_H_
