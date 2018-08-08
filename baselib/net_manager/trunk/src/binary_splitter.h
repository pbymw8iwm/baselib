//! @file binary_splitter.h


#ifndef _BINARY_SPLITTER_H_
#define _BINARY_SPLITTER_H_


#include "packet_splitter.h"


//! @class Binary_Splitter
//! @brief ������Э��tcp�����
//!
//! ��ǰ���ֽ�Ϊ�����ֽ���İ���
class Binary_Splitter : public Packet_Splitter
{
public:
	enum PACKLEN_TYPE {PACKLENTYPE_WORD, PACKLENTYPE_DWORD};

	explicit Binary_Splitter(PACKLEN_TYPE packlentype = PACKLENTYPE_WORD);

	virtual ~Binary_Splitter();

	//! ���
	//! @param buf ���ݻ���
	//! @param len ���ݳ���
	//! @param packet_begin ���ز��� ����ʼλ��
	//! @param packet_len ���ز��� ������
	//! @return -1:���ݸ�ʽ����, 0:������û��������, 1:�õ�һ����
	virtual int split(const char *buf, int len, int& packet_begin, int& packet_len);
private:
	PACKLEN_TYPE m_packlentype;
};


#endif // _BINARY_SPLITTER_H_
