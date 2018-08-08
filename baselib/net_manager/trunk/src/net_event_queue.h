//! @file net_event_queue.h


#ifndef _NET_EVENT_QUEUE_H_
#define _NET_EVENT_QUEUE_H_


#include "cycle_buffer.h"
#include "net_event.h"
#include "config.h"


//! @typedef Net_Event_Queue
//! @brief �����¼�����
//!
//! ͨ�Ų�����¼�������˶���, Ӧ�ò�ȡ���¼����ͷ�
//! �˶��в����̰߳�ȫ
typedef Cycle_Buffer_T<Net_Event*, MAX_NET_EVENT_COUNT> Net_Event_Queue;


#endif // _NET_EVENT_QUEUE_H_
