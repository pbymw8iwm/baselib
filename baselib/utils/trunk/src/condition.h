/// @file condition.h

#ifndef THREAD_CONDITION_H
#define THREAD_CONDITION_H

namespace utils
{
    namespace thread
    {
        class condition_impl;

        /**
            ���������Ŀ�ƽ̨ʵ��

            �ڲ��������߳���Mutex

            - �����ߣ�
            <CODE>
                Condtion & cond;
                while (true) {
                    cond.lock();
                    cond.wait();
                    // ��ȡ��Ʒ
                    cond.unlock();
                    // ��������
                }
            </CODE>

            - �����ߣ�
            <CODE>
                Condtion & cond;
                cond.lock();
                // �ύ��Ʒ
                cond.signal();
                // ����cond.broadcast();
                cond.unlock(); // Win32ƽ̨���������ں����ͷ�
            </CODE>
         */
        class Condition
        {
        public:
            Condition();

            ~Condition();

        public:
            // ��ʼ��
            int init();

            /// ��ȡ��
            int lock();

            /// �ͷ���
            int unlock();

            /// �ȴ���������������
            int wait();

            /// �ȴ���������������ʱ
            int timed_wait(int msec);

            /// �����źţ�����һ���ȴ��߳�
            int signal();

            /// �㲥�źţ��������еȴ��߳�
            int broadcast();

        private:
            condition_impl * impl_;

        };

    } // namespace thread

} // namespace utils

#endif // THREAD_CONDITION_H
