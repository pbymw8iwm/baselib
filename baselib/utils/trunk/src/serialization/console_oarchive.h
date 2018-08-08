/// @file console_oarchive.h

#ifndef CONSOLE_OARCHIVE_H
#define CONSOLE_OARCHIVE_H

#include "serialization/text_oarchive.h"

#include <iostream>
#include <string>
#include <ostream>

namespace utils
{

    namespace serialization
    {

        class console_oarchive
            : public basic_oarchive<console_oarchive>
        {
            friend class basic_oarchive<console_oarchive>;

        public:
            console_oarchive(
                std::ostream & os = std::cout)
                : basic_oarchive<console_oarchive>(*os.rdbuf())
                , sub_just_end_(false)
                , os_(os)
            {
            }

            /// 向流中写入参数化类型变量
            template <typename T>
            void save(
                T const & t)
            {
                os_ << t;
            }

            void save(
                unsigned char const & t)
            {
                unsigned short t1 = t;
                os_ << t1;
            }

            /// 向流中写入变标准库字符串
            void save(
                std::string const & t)
            {
                os_ << t;
            }

            using basic_oarchive<console_oarchive>::save;

            void save_start(
                std::string const & name)
            {
                os_ << ident_ << name << ": ";
            }

            void save_end(
                std::string const & name)
            {
                if (!sub_just_end_)
                    os_ << std::endl;
                sub_just_end_ = false;
            }

            void sub_start()
            {
                os_ << std::endl;
                ident_ += "  ";
            }

            void sub_end()
            {
                sub_just_end_ = true;
                ident_.erase(ident_.size() - 2);
            }

        private:
            std::string ident_;
            bool sub_just_end_;
            std::ostream & os_;
        };

    } // namespace archive

}// namespace utils

#endif // CONSOLE_OARCHIVE_H
