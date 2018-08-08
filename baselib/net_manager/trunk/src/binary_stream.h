
//=============================================================================
/**
 *  @file binary_stream.h
 *  ������ʵ��һ������������ȡ���д����
 */
//=============================================================================


#ifndef _BINARY_STREAM_H_
#define _BINARY_STREAM_H_


#include "types.h"
#include "stream_types.h"
#include "os.h"
#include <string.h>


//! �հ�ͷ(����ĳЩû�а�ͷ��Э��ʹ�ô˰�ͷ)
class NULL_HEAD;


//! @class Binary_Read_Stream
//! @brief �����ƶ�ȡ��
template<typename HEAD = NULL_HEAD>
class Binary_Read_Stream
{
public:
	//! ���캯��
	//! @param buf ������ָ��
	//! @param len ���ݳ���
	Binary_Read_Stream(const char *buf, int len);

	//! ��������
	~Binary_Read_Stream();

public:
	//! ȡ��ͷ
	//! @return ��ͷ����
	HEAD& head();

public:
	//! ��ȡuint8
	//! @param data ��ȡ����
	//! @return �����ƶ�ȡ��
	Binary_Read_Stream& operator >>(uint8_t &data);

	//! ��ȡuint16(תΪ�����ֽ���)
	//! @param data ��ȡ����
	//! @return �����ƶ�ȡ��
	Binary_Read_Stream& operator >>(uint16_t &data);

	//! ��ȡuint32(תΪ�����ֽ���)
	//! @param data ��ȡ����
	//! @return �����ƶ�ȡ��
	Binary_Read_Stream& operator >>(uint32_t &data);

	//! ��ȡuint64(תΪ�����ֽ���)
	//! @param data ��ȡ����
	//! @return �����ƶ�ȡ��
	Binary_Read_Stream& operator >>(uint64_t &data);

	//! ��ȡ�ַ���
	//! @param data ��ȡ����
	//! @return �����ƶ�ȡ��
	Binary_Read_Stream& operator >>(String &data);

	//! ��ȡ�ַ���
	//! @param data ��ȡ����
	//! @return �����ƶ�ȡ��
	//Binary_Read_Stream& operator >>(const String &data);

	//! ��ȡ���ݿ�
	//! @param data ��ȡ����
	//! @return �����ƶ�ȡ��
	Binary_Read_Stream& operator >>(Binary &data);

public:
	//! ȡ��״̬
	//! @return ��״̬
	bool good() const;

	//! ȡ��������־
	//! @return ��������־
	bool eof() const;

public:
	//! ��ȡuint8
	uint8_t read_uint8();

	//! ��ȡuint16
	uint16_t read_uint16();

	//! ��ȡuint32
	uint32_t read_uint32();

	//! ��ȡString
	String read_string();

	//! ��ȡBinary
	Binary read_binary();

private:
	const char *m_buf;
	int m_len;
	int m_pos;
	bool m_good;
	bool m_eof;
};

//! �ػ��ް�ͷ�汾�Ĺ��캯��
//! @param buf ������ָ��
//! @param len ���ݳ���
template<>
Binary_Read_Stream<NULL_HEAD>::Binary_Read_Stream(const char *buf, int len);




template<typename HEAD>
class Binary_Write_Stream;


//! @fn Binary_Write_Stream<HEAD>& Binary_Begin(Binary_Write_Stream<HEAD>& write_stream)
//! @brief ������д����������, ��ʼһ�����ݿ�
template<typename HEAD>
Binary_Write_Stream<HEAD>& Binary_Begin(Binary_Write_Stream<HEAD>& write_stream);


//! @fn Binary_Write_Stream<HEAD>& Binary_End(Binary_Write_Stream<HEAD>& write_stream)
//! @brief ������д����������, ����һ�����ݿ�
template<typename HEAD>
Binary_Write_Stream<HEAD>& Binary_End(Binary_Write_Stream<HEAD>& write_stream);


//! @class Binary_Write_Stream
//! @brief ������д����
template<typename HEAD = NULL_HEAD>
class Binary_Write_Stream
{
public:
	//! ���캯��
	//! @param buf ������ָ��
	//! @param len ����������
	Binary_Write_Stream(char *buf, int len);
	
	Binary_Write_Stream();

	//! ��������
	~Binary_Write_Stream();

public:
	//! ����������Ԫ, ��ʼһ�����ݿ�
	friend Binary_Write_Stream& Binary_Begin<>(Binary_Write_Stream& write_stream);

	//! ����������Ԫ, ����һ�����ݿ�
	friend Binary_Write_Stream& Binary_End<>(Binary_Write_Stream& write_stream);

public:
	//! ȡ��ͷ
	//! @return ��ͷ����
	HEAD& head();
	
	void reset();
	void detach();
	void attach(char *buf, int len);

public:

	//! д��uint8
	//! @param data д������
	//! @return ������д����
	Binary_Write_Stream& operator <<(uint8_t data);

	//! д��uint16(תΪ�����ֽ���)
	//! @param data д������
	//! @return ������д����
	Binary_Write_Stream& operator <<(uint16_t data);

	//! д��uint32(תΪ�����ֽ���)
	//! @param data д������
	//! @return ������д����
	Binary_Write_Stream& operator <<(uint32_t data);

	//! д��uint64(תΪ�����ֽ���)
	//! @param data д������
	//! @return ������д����
	Binary_Write_Stream& operator <<(uint64_t data);

	//! д���ַ���
	//! @param data д������
	//! @return ������д����
	Binary_Write_Stream& operator <<(const String& data);

	//! д���ַ���
	//! @param data д������
	//! @return ������д����
	Binary_Write_Stream& operator <<(const char *data);

	//! д�����ݿ�
	//! @param data д������
	//! @return ������д����
	Binary_Write_Stream& operator <<(const Binary& data);

	//! ִ����������
	//! @param pfn ������������ָ��
	//! @return ������д����
	Binary_Write_Stream& operator <<(Binary_Write_Stream& (*pfn)(Binary_Write_Stream&));

public:
	//! ȡ��״̬
	//! @return ��״̬
	bool eof() const;

	//! ȡ��������־
	//! @return ��������־
	bool good() const;

	//! ȡ��д������ݳ���
	//! @return ���ݳ���
	int length() const;

public:
	//! д��uint8
	void write_uint8(uint8_t data);

	//! д��uint16
	void write_uint16(uint16_t data);

	//! д��uint32
	void write_uint32(uint32_t data);

	//! д��string
	void write_string(const String& data);

	//! ��ʼ���������ݿ�
	void begin_binary();

	//! �������������ݿ�
	void end_binary();

	//! д����������ݿ�
	void write_binary(const Binary& data);
	//! д�벻�����ȵ����ݿ�
	void write_raw(char* data, int len);


private:
	char *m_buf;
	int m_len;
	int m_pos;
	bool m_good;
	bool m_eof;
	bool m_begin_binary;
	int m_binary_len_pos;
	uint16_t m_binary_len;
};

//! �ػ��ް�ͷ�汾���캯��
//! @param buf ������ָ��
//! @param len ����������
template<>
Binary_Write_Stream<NULL_HEAD>::Binary_Write_Stream(char *buf, int len);

template<>
void Binary_Write_Stream<NULL_HEAD>::reset();
template<>
void Binary_Write_Stream<NULL_HEAD>::detach();
template<>
void Binary_Write_Stream<NULL_HEAD>::attach(char *buf, int len);


#include "binary_stream.inl"	// ģ��ʵ�ִ���


#endif // _BINARY_STREAM_H_
