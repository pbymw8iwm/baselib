//! @file types.h
//! @brief ģ���õ��ĸ�������������Ͷ���


#ifndef _TYPES_H_
#define _TYPES_H_

#ifdef WIN32	// for windows

#include <stddef.h>				// for size_t
#include <stdint.h>
/*typedef __int8					int8_t;
typedef __int16					int16_t;
typedef __int32					int32_t;
typedef __int64					int64_t;

typedef unsigned __int8			uint8_t;
typedef unsigned __int16		uint16_t;
typedef unsigned __int32		uint32_t;
typedef unsigned __int64		uint64_t;
*/
typedef int						ssize_t;
typedef int						socklen_t;
typedef uint32_t				in_addr_t;
typedef uint16_t				in_port_t;

#else			// for linux

#include <stddef.h>				// for size_t
#include <unistd.h>				// for ssize_t and socklen_t
#include <netinet/in.h>			// for in_addr_t and in_port_t
#include <stdint.h>

#endif

#endif // _TYPES_H_
