//! @file os.h
//! @brief ����socket�������


#ifndef _OS_H_
#define _OS_H_


#include "types.h"


#ifdef WIN32	// for windows
#define FD_SETSIZE 1024
#include <winsock2.h>
#include <direct.h>
#include <io.h>
#include <sys/stat.h>
#include <sys/types.h>

typedef int socklen_t;

//! ����Ϊ������ģʽ
inline int set_socket_nonblocking(SOCKET socket)
{
	int iMode = 1;
	int nret = ioctlsocket(socket, FIONBIO, (u_long FAR*)&iMode);

	return nret;
}

//! �ر�socket
inline int close(SOCKET socket)
{
	return closesocket(socket);
}

//! ������
inline int error_no()
{
	return WSAGetLastError();
}


#define NETMANAGER_EAGAIN		WSAEWOULDBLOCK		//<! �����ݿɶ����д
#define NETMANAGER_EINPROGRESS	WSAEWOULDBLOCK			//<! ��������
#define NETMANAGER_EWOULDBLOCK	WSAEWOULDBLOCK

/*
//! ˯�ߣ���Ϊ����
inline void sleep(unsigned long _m)
{
	Sleep(_m);
}
*/

//! �����ļ���
inline int mkdir(const char *dirname, int)
{
	return _mkdir(dirname);
}


#define F_OK 0
#define W_OK 2
#define R_OK 4


//! ����ļ�
inline int access(const char *path, int mode)
{
	return _access(path, mode);
}




#else			// for linux

#define NETMANAGER_EAGAIN		EAGAIN
#define NETMANAGER_EINPROGRESS	EINPROGRESS
#define NETMANAGER_EWOULDBLOCK	EWOULDBLOCK

#include <sys/types.h>
#include <sys/socket.h>
#include <sys/time.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <fcntl.h>
#include <errno.h>
#include <unistd.h>
#include <time.h>

//! @typedef SOCKET
//! @brief socket����
typedef int SOCKET;


//! @def INVALID_SOCKET
//! @brief ��Чsocket
#define INVALID_SOCKET -1

//! ˯�ߣ���Ϊ����
inline void Sleep(unsigned long _m)
{
	struct timespec req;
	req.tv_sec = (int)_m/1000;
	req.tv_nsec = (_m-req.tv_sec*1000)*1000000L;
	nanosleep(&req, NULL);
}

//! ����Ϊ������ģʽ
inline int set_socket_nonblocking(SOCKET socket)
{
	int val = fcntl(socket, F_GETFL, 0);
	int nret = fcntl(socket, F_SETFL, val | O_NONBLOCK);

	return nret > -1 ? 0 : nret;
}

//! ������
inline int error_no()
{
	return errno;
}


#endif

//����socket���ջ��߷��ͻ�������С
inline int set_socket_bufsize(SOCKET sock, bool isRead, int netbufsize)
{
	int opt_name = isRead ? SO_RCVBUF : SO_SNDBUF;
	int nBufSize = netbufsize;
	return ::setsockopt(sock, SOL_SOCKET, opt_name, reinterpret_cast<char*>(&nBufSize), sizeof(nBufSize));
}

inline int get_socket_bufsize(SOCKET sock, bool isRead, int& netbufsize)
{
	int opt_name = isRead ? SO_RCVBUF : SO_SNDBUF;
	socklen_t nsize = sizeof(netbufsize);
	return ::getsockopt(sock, SOL_SOCKET, opt_name, reinterpret_cast<char*>(&netbufsize), &nsize);
}

#endif // _OS_H_

