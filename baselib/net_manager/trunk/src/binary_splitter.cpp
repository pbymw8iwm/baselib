

#include "binary_splitter.h"
#include "os.h"
#include "config.h"


// class Binary_Splitter

Binary_Splitter::Binary_Splitter(PACKLEN_TYPE packlentype)
: m_packlentype(packlentype)
{

}

Binary_Splitter::~Binary_Splitter()
{

}

int Binary_Splitter::split(const char *buf, int len, int& packet_begin, int& packet_len)
{
	uint8_t nMinLen = m_packlentype == PACKLENTYPE_WORD ? sizeof(uint16_t) : sizeof(uint32_t);
	if (len < nMinLen) {
		return 0;
	}

	int pack_len = m_packlentype == PACKLENTYPE_WORD ? ntohs(*(uint16_t*)buf) : ntohl(*(uint32_t*)buf);
	if (pack_len < nMinLen) {
		return -1;
	}

	if (len >= pack_len) {
		packet_begin = 0;
		packet_len = pack_len;
		return 1;
	}

	if(len < pack_len)	//缓冲区中的数据不足一个包
	{
		packet_begin = 0;		
		packet_len = pack_len;
	}

	return 0;
}

