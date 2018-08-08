//! @file net_event.h


#ifndef _NET_EVENT_H_
#define _NET_EVENT_H_


#include "types.h"
#include "inet_addr.h"
#include "net_packet.h"
#include "pool_allocator.h"
#include "config.h"

class Net_Event;
//! �����¼�������
typedef void (*pfnNetEventHandler)(Net_Event& net_event);

//! @enum NET_EVENT_TYPE
//! @brief �����¼�����
enum NET_EVENT_TYPE
{
	TYPE_NULL,			//!< ���¼�
	TYPE_DATA,			//!< ���ݵ���
	TYPE_CONNECT,		//!< tcp���ӳɹ�
	TYPE_ACCEPT,		//!< tcp��������
	TYPE_CLOSE,			//!< tcp���ӹر�
	TYPE_LISTEN_CLOSE,  //!<����socket�ر�
	TYPE_EXCEPTION,		//!< �쳣
	TYPE_LISTEN_EXCEPTION, //!<����socket�쳣
	TYPE_TIMEOUT,		//!< ��ʱ
	TYPE_SYS_ERROR		//!< ϵͳ�쳣
};


//! @class Net_Event
//! @brief �����¼���
//!
//! ����������㱻���䲢��ʹ��, ��Ӧ�ò㱻ʹ�ò�����, Ϊ���Ч��ʹ��Ԥ��������
class Net_Event
{
public:
	Net_Event();
	~Net_Event();

public:
	DECLARE_ALLOCATOR(Net_Event, NET_EVENT_POOL_COUNT)
public:
	//! �����¼�����
	NET_EVENT_TYPE net_event_type;

	//! �����¼���ͨ��id
	uint32_t id;

	//! ������ͨ��id, ���û�в�����ͨ���˴�Ϊ0
	uint32_t new_id;

	//! ���ص�ַ
	INET_Addr local_addr;

	//! �Զ˵�ַ
	INET_Addr remote_addr;

	//! ���ݰ�
	Net_Packet packet;
	
	//! ���¼�������ָ��
	void* UserData;

};

#endif // _NET_EVENT_H_
