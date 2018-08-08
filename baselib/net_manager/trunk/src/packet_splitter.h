//! @file packet_splitter.h


#ifndef _PACKET_SPLITTER_H_
#define _PACKET_SPLITTER_H_


#include "types.h"


//! @class Packet_Splitter
//! @brief tcp����ӿ�
class Packet_Splitter
{
public:
	virtual ~Packet_Splitter();

	//! ���
	//! @param buf ���ݻ���
	//! @param len ���ݳ���
	//! @param packet_begin ���ز��� ����ʼλ��
	//! @param packet_len ���ز��� ������
	//! @return -1:���ݸ�ʽ����, 0:������û��������, 1:�õ�һ����
	virtual int split(const char *buf, int len, int& packet_begin, int& packet_len) = 0;
};


#endif // _PACKET_SPLITTER_H_
