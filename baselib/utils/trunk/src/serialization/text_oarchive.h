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
            /// 向流中写入参数化类型变量
            template<class T>
            void save(T const & t)
            {
                newtoken();
                if (state_) return;
                os_ << t;
                if(os_.fail())
                    state_ = 1;
            }

            /// 向流中写入标准库字符串
            void save(std::string const & t)
            {
                save((std::size_t)t.size());
                newtoken(); // 加上一个空格
                save_binary((char const *)&t[0], t.size());
            }

            using basic_oarchive<text_oarchive>::save;

        public:
            /// 以换行符为分隔符，下一个变量将另起一行输出，然后自动恢复为空格分隔符
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

            /// 分隔符一开始是空的（none），写入第一个变量以后变为空格（space）
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
                    // 自动恢复为空格分隔符
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
