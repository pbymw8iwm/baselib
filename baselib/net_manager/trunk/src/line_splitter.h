//! @file line_splitter.h


#ifndef _LINE_SPLITTER_H_
#define _LINE_SPLITTER_H_


#include "packet_splitter.h"


//! @class Line_Splitter
//! @brief �ı���Э������
//!
//! ÿ���ı�Ϊһ����, CR LF �ַ��Ѿ�ȥ��
class Line_Splitter : public Packet_Splitter
{
public:
	virtual ~Line_Splitter();

	//! ���
	//! @param buf ���ݻ���
	//! @param len ���ݳ���
	//! @param packet_begin ���ز��� ����ʼλ��
	//! @param packet_len ���ز��� ������
	//! @return -1:���ݸ�ʽ����, 0:������û��������, 1:�õ�һ����
	virtual int split(const char *buf, int len, int& packet_begin, int& packet_len);
};


#endif // _LINE_SPLITTER_H_
