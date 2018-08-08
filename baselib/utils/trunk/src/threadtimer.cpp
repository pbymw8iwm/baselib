#include "threadtimer.h" 
 namespace utils {
CThreadTimer::~CThreadTimer() { 
}
 
bool CThreadTimer::Start(/*CThreadTimer* timer*/) {
	 Stop();
	 status_ = TIME_OUT;
	 timernode_ =  powner_->AddTimer(dwinterval_, this);
	return  timernode_ == NULL ? false : true;
}
 
void CThreadTimer::Stop() {
    status_ = USER_CANCLE;
    if (timernode_) {
        powner_->RemoveTimer(timernode_);
        timernode_ = NULL; 
    }
}
 
void CThreadTimer::Callback() {
    timernode_ = NULL;
	CallBackFun();
    if (entype_ == TIMER_CIRCLE) {
        Start();
    }
	//CallBackFun();
    //callback_(); //must at the last line; timer may be deleted in callback_();
}
 
  
}