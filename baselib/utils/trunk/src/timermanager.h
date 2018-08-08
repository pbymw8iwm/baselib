#ifndef APE_COMMON_TIMER_MANAGER_H_
#define APE_COMMON_TIMER_MANAGER_H_
#include <stdint.h>
#include <list> 
//参考文献：http://www.2cto.com/os/201607/530568.html
namespace utils {
class CThreadTimer;
#define GRANULARITY 10 //10ms 设置系统tick精度
#define WHEEL_BITS1 8
#define WHEEL_BITS2 6
#define WHEEL_SIZE1 (1 << WHEEL_BITS1) //256
#define WHEEL_SIZE2 (1 << WHEEL_BITS2) //64  (spoke大小)
#define WHEEL_MASK1 (WHEEL_SIZE1 - 1)
#define WHEEL_MASK2 (WHEEL_SIZE2 - 1)
#define WHEEL_NUM 5
typedef struct stNodeLink {
    stNodeLink *prev;
    stNodeLink *next;
    stNodeLink() {prev = next = this;} //circle
}SNodeLink;
typedef struct stTimerNode {
    SNodeLink link;
    uint64_t dead_time;
    CThreadTimer *timer;
    stTimerNode(CThreadTimer *t, uint64_t dt) :  dead_time(dt), timer(t) {}
}STimerNode;
typedef struct stWheel {
    SNodeLink *spokes;
    uint32_t size;
    uint32_t spokeindex;
    stWheel(uint32_t n) : size(n), spokeindex(0){
        spokes = new SNodeLink[n];
    }
    ~stWheel() {
        if (spokes) {
            for (int j = 0; j < size; ++j) {
                SNodeLink *link = (spokes + j)->next;
                while (link != spokes + j) {
                    STimerNode *node = (STimerNode *)link;
                    link = node->link.next;
                    delete node;
                }
            }
            delete []spokes;
            spokes = NULL;
        }
    }
}SWheel;

class CTimerManager {
  public:
    CTimerManager();
    virtual ~CTimerManager();
    void DetectTimerList();
    STimerNode* AddTimer(uint32_t seconds, CThreadTimer *timer);//增加一个定时器
    void RemoveTimer(STimerNode* node);
    virtual void Dump();//清理当前无用的定时器

  private:
    uint32_t Cascade(uint32_t wheelindex);//降级处理，每个tick到来，都会检测最低级的tv1的时间轮，当每一级的时间轮走到超出该机时间轮的范围，就会触发上一级时间轮所在的spoke+1的acscade过程
    void AddTimerNode(uint32_t milseconds, STimerNode *node);
    void AddToReadyNode(STimerNode *node);
    void DoTimeOutCallBack();

  private:
    SWheel *wheels_[WHEEL_NUM];//定义的多时间轮，仿照linux的5个 8+6+6+6+6 能表示的时间大概是42亿个 
    uint64_t checktime_;//上次时间轮的检测时间
    SNodeLink readynodes_;//时间片轮已经到了触发时间的所有草位
}; 
}
#endif
