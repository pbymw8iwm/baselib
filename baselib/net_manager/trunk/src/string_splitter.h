#ifndef _STRING_SPLITTER_H
#define _STRING_SPLITTER_H

#include "packet_splitter.h"


//! @class String_Splitter
//! @brief �ı���Э������
//!
//! ÿ���ı�Ϊһ����, CR LF �ַ��Ѿ�ȥ��
class String_Splitter : public Packet_Splitter
{
public:
	virtual ~String_Splitter();

	//! ���
	//! @param buf ���ݻ���
	//! @param len ���ݳ���
	//! @param packet_begin ���ز��� ����ʼλ��
	//! @param packet_len ���ز��� ������
	//! @return -1:���ݸ�ʽ����, 0:������û��������, 1:�õ�һ����
	virtual int split(const char *buf, int len, int& packet_begin, int& packet_len);
};

#endif  /* _STRING_SPLITTER_H */
