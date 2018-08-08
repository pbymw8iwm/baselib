//! @file stream_types.h


#ifndef _STREAM_TYPES_H_
#define _STREAM_TYPES_H_


#include "types.h"


//! @class String
//! @brief �ַ���
class String
{
public:
	//! ���캯��
	String();

	//! ���캯��
	//! @param buf �ַ���ָ��
	//! @param len ����
	//!
	//! д����ʱ ��buf�ڵ��ַ���д������, ͬʱ��д�����0
	//! ��ȡ��ʱ ���bufΪNULL ��bufָ�����е��ַ���,
	//!	         ���buf��ΪNULL����len�ĳ����㹻 �����е��ַ���������buf��
	String(const char *buf, int len);

public:
	const char *buf;	//!< �ַ���ָ��
	int len;			//!< �ַ�������(����������0)
};


//! @class Binary
//! @brief ���������ݿ�
class Binary
{
public:
	//! ���캯��
	Binary();

	//! ���캯��
	//! @param buf ���ݿ�ָ��
	//! @param len ����
	//!
	//! д����ʱ ��buf�ڵ����ݿ�д������
	//! ��ȡ��ʱ ��bufָ�����е����ݿ�
	Binary(const char *buf, int len);

public:
	const char *buf;	//!< ���ݿ�ָ��
	int len;			//!< ���ݿ鳤��
};

#endif // _STREAM_TYPES_H_

