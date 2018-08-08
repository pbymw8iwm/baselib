#ifndef APE_COMMON_THREAD_TIMER_H_
#define APE_COMMON_THREAD_TIMER_H_

#include "timermanager.h" 
#include <stdint.h> 


namespace utils {
class CThreadTimer {
 public:
	 typedef enum { TIMER_ONCE = 0, TIMER_CIRCLE }ETimerType;
	 typedef enum { WAITING = 0, TIME_OUT, USER_CANCLE }EStatus;

    CThreadTimer() : powner_(NULL), status_(WAITING), data_(NULL), timernode_(NULL){} 
	CThreadTimer(CTimerManager *o, uint32_t i = 0, ETimerType t = TIMER_ONCE, void *data = NULL) :
		powner_(o), dwinterval_(i), entype_(t), status_(WAITING),  timernode_(NULL), data_(data) {
		//Start();
	}
    void Init(CTimerManager *o, uint32_t i=0, ETimerType t=TIMER_ONCE, void *data=NULL) {
        powner_ = o;
        dwinterval_ = i; 
        entype_ = t;
        data_ = data;
		//return Start();
    }
	bool Start();// (CThreadTimer* timer);
    void Stop();
    int GetStatus(){return status_;}
    void SetData(void *data) {data_ = data;}
    void *GetData() {return data_;}
    ~CThreadTimer();
	virtual int CallBackFun() = 0;//返回1表示需要删除掉这个定时器，如果返回0不需要删除，还是会继续tick
 public:
    void Callback();
    void SetInterval(uint32_t i) { dwinterval_ = i;}
    uint32_t GetInterval() { return dwinterval_;} 
	void *data_; 
	ETimerType entype_;
 private:
    CTimerManager *powner_;
    uint32_t dwinterval_; //unit : ms
    
    EStatus status_; 
    STimerNode *timernode_;    
}; 

}
#endif
