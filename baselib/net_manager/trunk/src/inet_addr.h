//! @file inet_addr.h


#ifndef _INET_ADDR_H_
#define _INET_ADDR_H_


#include "types.h"


//! @class INET_Addr
//! @brief Internet���ַ�ķ�װ��
class INET_Addr
{
public:
	INET_Addr();
	~INET_Addr();

	//! ��������
	INET_Addr(const INET_Addr& rhs);

	//! ��ֵ������
	INET_Addr& operator=(const INET_Addr& rhs);

public:
	//! ���������ַ
	void set_addr(in_addr_t addr);

	//! ȡ�����ַ
	in_addr_t get_addr() const;

	//! ���ö˿�(�����ֽ�)
	void set_port(in_port_t port);

	//! ȡ�˿�(�����ֽ�)
	in_port_t get_port() const;

	//! �����ַ
	void clear();

private:
	//! �����ַ
	in_addr_t m_addr;

	//! �˿�(�����ֽ�)
	in_port_t m_port;
};


#endif // _INET_ADDR_H_
