/// @file text_oarchive.h

#ifndef TEXT_OARCHIVE_H
#define TEXT_OARCHIVE_H

#include "serialization/basic_oarchive.h"
#include <ostream>
#include <string>

namespace utils
{

    namespace serialization
    {

        class text_oarchive
            : public basic_oarchive<text_oarchive>
        {
        public:
            text_oarchive(
                std::ostream & os)
                : basic_oarchive<text_oarchive>(*os.rdbuf())
                , delimiter_(none)
                , os_(os)
            {
            }

        public:
            /// ������д����������ͱ���
            template<class T>
            void save(T const & t)
            {
                newtoken();
                if (state_) return;
                os_ << t;
                if(os_.fail())
                    state_ = 1;
            }

            /// ������д���׼���ַ���
            void save(std::string const & t)
            {
                save((std::size_t)t.size());
                newtoken(); // ����һ���ո�
                save_binary((char const *)&t[0], t.size());
            }

            using basic_oarchive<text_oarchive>::save;

        public:
            /// �Ի��з�Ϊ�ָ�������һ������������һ�������Ȼ���Զ��ָ�Ϊ�ո�ָ���
            void newline()
            {
                delimiter_ = eol;
            }

        private:
            enum {
                none,
                eol,
                space
            } delimiter_;

            /// �ָ���һ��ʼ�ǿյģ�none����д���һ�������Ժ��Ϊ�ո�space��
            void newtoken()
            {
                if (state_) return;
                switch (delimiter_)
                {
                default:
                    state_ = 1;
                    break;
                case eol:
                    if (!os_.put('\n'))
                        state_ = 1;
                    // �Զ��ָ�Ϊ�ո�ָ���
                    delimiter_ = space;
                    break;
                case space:
                    if (!os_.put(' '))
                        state_ = 1;
                    break;
                case none:
                    delimiter_ = space;
                    break;
                }
            }

        private:
            std::ostream & os_;
        };

    } // namespace archive

} // namespace utils

#endif // TEXT_OARCHIVE_H
