
#ifndef WIN32

#include "epoll_reactor.h"
#include "event_handler.h"
#include "log.h"
#include <assert.h>
#include <vector>


// class Epoll_Reactor
Epoll_Reactor::Epoll_Reactor()
{
	m_epfd = -1;
	m_events = new epoll_event[MAX_HANDLER * 2];
}

Epoll_Reactor::~Epoll_Reactor()
{
	delete [] m_events;
}

int Epoll_Reactor::open_reactor()
{
	m_epfd = epoll_create(MAX_HANDLER);
	if (-1 == m_epfd) {
		LOG(FATAL)("Epoll_Reactor::open_reactor error, epoll_create error, errno:%d", error_no());
		return -1;
	}

	return 0;
}

int Epoll_Reactor::close_reactor()
{
	if (-1 != m_epfd) {
		close(m_epfd);
		m_epfd = -1;
	}

	return 0;
}

int Epoll_Reactor::run_reactor_event_loop()
{
	if (-1 == m_epfd) {
		return -1;
	}

	// epoll事件
	int count = epoll_wait(m_epfd, m_events, MAX_HANDLER, 1);
	if (count < 0) {
		LOG(FATAL)("Epoll_Reactor::run_reactor_event_loop error, epoll_wait error, errno:%d", error_no());

		if(error_no() == EINTR)
		{
			return 0;
		}
		else
		{
			return -1;
		}
	}

	for (int i = 0; i < count; i++)
	{
		Event_Handler *event_handler = (Event_Handler*)m_events[i].data.ptr;

		//未注册这两个事件，因此不再判断

		// 异常
		if (m_events[i].events & EPOLLERR)
		{
			//utils::Thread_Mutex_Guard guard(m_map_mutex);

			removeHandler(event_handler);
			event_handler->handle_exception();
			delete event_handler;
			continue;
		}

		// 关闭
		if (m_events[i].events & EPOLLHUP)
		{
			//utils::Thread_Mutex_Guard guard(m_map_mutex);

			removeHandler(event_handler);
			event_handler->handle_close();
			delete event_handler;
			continue;
		}

		// 可读
		if (m_events[i].events & EPOLLIN)
		{
			int rc = event_handler->handle_input();
			//LOG(ERROR)("Epoll_Reactor::handle_input return:%d for id:%d", rc, id);
			if (-1 == rc)
			{
				// 连接关闭
				removeHandler(event_handler);				
				event_handler->handle_close();
				delete event_handler;
				continue;
			}
			if (-2 == rc)
			{
				// 连接异常
				removeHandler(event_handler);
				event_handler->handle_exception();
				delete event_handler;
				continue;
			}
		}

		// 可写
		if (m_events[i].events & EPOLLOUT)
		{
			int rc = event_handler->handle_output();
			//LOG(ERROR)("Epoll_Reactor::handle_output return:%d for id:%d", rc, id);
			if (-1 == rc)
			{
				// 连接关闭
				removeHandler(event_handler);
				event_handler->handle_close();
				delete event_handler;
				continue;
			}
			else if (-2 == rc)
			{
				// 连接异常
				removeHandler(event_handler);
				event_handler->handle_exception();
				delete event_handler;
				continue;
			}
			else 
			{
				//LOG(WARN)("Epoll_reactor:: handleoutput return:%d", rc);				
			}
		}
	}
/*
	// 处理用户通知关闭的处理器和超时的处理器
	vector<Event_Handler*> close_handler;
	vector<Event_Handler*> timeout_handler;
	//定时处理，避免每次都跑，影响系统性能
	static time_t last_scan_time = 0;
	time_t current_time = time(NULL);
	list_head* pos, *n;
	if(current_time - last_scan_time > 0)
	{ // lock section
		last_scan_time = current_time;
		list_for_each_safe(pos, n, &handler_head)
		{
			Event_Handler *event_handler = list_entry(pos, Event_Handler, item);

			// 关闭通知
			if (true == event_handler->notify_close)
			{
				//LOG(WARN)("Epoll_reactor:: checker id:%d, write:%d, writecheck:%d", 
				//				iter->first, iter->second.write, iter->second.have_check_send_task);				
				if (event_handler->write == false) 
				{
					removeHandler(event_handler);
					close_handler.push_back(event_handler);
					continue;					
				}
				else {
					// 此通道上还有待发送数据, 如果没有设置超时则设置超时
					if (event_handler->timeout == 0) {
						event_handler->timeout = current_time + 30;
					}
				}
			}

			// 超时
			if ((event_handler->timeout != 0) && (current_time >= event_handler->timeout))
			{
				removeHandler(event_handler);
				timeout_handler.push_back(event_handler);
				continue;
			}
		}
	} // end lock section

	for (size_t i = 0; i < close_handler.size(); i++)
	{
		Event_Handler *event_handler = close_handler[i];
		//LOG(ERROR)("Epoll_Reactor:: call handle_close for id:%d", event_handler->get_id());
		event_handler->handle_close();
		delete event_handler;
	}

	for (size_t i = 0; i < timeout_handler.size(); i++)
	{
		Event_Handler *event_handler = timeout_handler[i];
		//LOG(ERROR)("Epoll_Reactor:: call handle_timeout for id:%d", event_handler->get_id());
		event_handler->handle_timeout();
		delete event_handler;
	}
*/
	return count;
}

int Epoll_Reactor::end_reactor_event_loop()
{
	return Reactor::end_reactor_event_loop();
}

int Epoll_Reactor::register_handler(Event_Handler *event_handler, uint32_t masks)
{
	if (-1 == m_epfd) {
		return -1;
	}

	event_handler->reactor(this);
	uint32_t id = event_handler->get_id();

	Event_Handler* pEventHandler = get_event_handler(id);
	if (NULL == pEventHandler)
	{
		// add
		event_handler->notify_close = false;
		event_handler->timeout = 0;

		epoll_event event;
		event.events = 0;
		event.data.ptr = (void*)event_handler;

		if (masks & MASK_READ) {
			event_handler->read = true;
			event.events |= EPOLLIN|EPOLLET;
		}
		else {
			event_handler->read = false;
		}

		if (masks & MASK_WRITE) {
			event_handler->write = true;
			event.events |= EPOLLOUT|EPOLLET;
		}
		else {
			event_handler->write = false;
		}

		int rc = epoll_ctl(m_epfd, EPOLL_CTL_ADD, event_handler->get_handle(), &event);
		if (0 != rc) {
			LOG(FATAL)("Epoll_Reactor::register_handler error, epoll_ctl error, errno:%d", error_no());
			return -1;
		}

		putHandler(event_handler, event_handler->get_id());
	}
	else
	{
		// mod

		epoll_event event;
		event.events = 0;
		event.data.ptr = (void*)event_handler;

		if (masks & MASK_READ) event_handler->read = true;
		if (masks & MASK_WRITE) event_handler->write = true;

		if (event_handler->read) event.events |= EPOLLIN | EPOLLET;
		if (event_handler->write) event.events |= EPOLLOUT | EPOLLET;

		int rc = epoll_ctl(m_epfd, EPOLL_CTL_MOD, event_handler->get_handle(), &event);
		if (0 != rc) {
			LOG(FATAL)("Epoll_Reactor::register_handler error, epoll_ctl error, errno:%d", error_no());
			return -1;
		}
	}
	return 0;
}

int Epoll_Reactor::remove_handler(Event_Handler *event_handler, uint32_t masks)
{
	if (-1 == m_epfd) {
		return -1;
	}

	event_handler->reactor(this);
	uint32_t id = event_handler->get_id();

	Event_Handler* pEventHandler = get_event_handler(id);	
	if (NULL == pEventHandler) {
		return 0;
	}

	// mod

	epoll_event event;
	event.events = 0;
	event.data.ptr = (void*)event_handler;

	if (masks & MASK_READ) event_handler->read = false;
	if (masks & MASK_WRITE) event_handler->write = false;

	if (event_handler->read) event.events |= EPOLLIN;
	if (event_handler->write) event.events |= EPOLLOUT;

	int rc = epoll_ctl(m_epfd, EPOLL_CTL_MOD, event_handler->get_handle(), &event);
	if (0 != rc) {
		LOG(FATAL)("Epoll_Reactor::remove_handler error, epoll_ctl error, errno:%d", error_no());
		return -1;
	}

	return 0;
}


int Epoll_Reactor::delete_handler(Event_Handler *event_handler)
{
	if (-1 == m_epfd) {
		return -1;
	}

	event_handler->reactor(this);
	uint32_t id = event_handler->get_id();

	Event_Handler* pEventHandler = get_event_handler(id);	
	if (NULL == pEventHandler) {
		return 0;
	}

	epoll_event event;
	event.events = 0;
	event.data.ptr = (void*)event_handler;

	if (event_handler->read) event.events |= EPOLLIN;
	if (event_handler->write) event.events |= EPOLLOUT;

	removeHandler(event_handler);
	int rc = epoll_ctl(m_epfd, EPOLL_CTL_DEL, event_handler->get_handle(), &event);
	if (0 != rc) {
		LOG(FATAL)("Epoll_Reactor::remove_handler error, epoll_ctl error, errno:%d", error_no());
		return -1;
	}
	return 0;
}

int Epoll_Reactor::set_timeout(uint32_t id, int timeout)
{
	Event_Handler* pEventHandler = get_event_handler(id);
	if (NULL == pEventHandler) {
		return -1;
	}

	pEventHandler->timeout = time(NULL) + timeout;
	return 0;
}

int Epoll_Reactor::cancel_timeout(uint32_t id)
{
	Event_Handler* pEventHandler = get_event_handler(id);
	if (NULL == pEventHandler) {
		return -1;
	}

	pEventHandler->timeout = 0;
	return 0;
}

int Epoll_Reactor::notify_close(uint32_t id)
{
	Event_Handler* pEventHandler = get_event_handler(id);
	if (NULL == pEventHandler) {
		return -1;
	}

	pEventHandler->notify_close = true;

	removeHandler(pEventHandler);
	pEventHandler->handle_close();
	delete pEventHandler;

	return 0;
}

Event_Handler* Epoll_Reactor::get_event_handler(uint32_t id)
{
	return getHandler(id);
}

#endif




