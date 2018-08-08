/// @file console_iarchive.h

#ifndef CONSOLE_IARCHIVE_H
#define CONSOLE_IARCHIVE_H

#include "serialization/basic_iarchive.h"

#include <string>
#include <iostream>
#include <limits>

#undef max

namespace utils
{

    namespace serialization
    {

        class console_iarchive
            : public basic_iarchive<console_iarchive>
        {
            friend class basic_iarchive<console_iarchive>;
            friend struct load_access;

        public:
            console_iarchive()
                : basic_iarchive<console_iarchive>(*std::cin.rdbuf())
            {
            }

        public:
            /// 从流中读出变量
            template<class T>
            void load(
                T & t)
            {
                std::cin >> t;
                if (std::cin.fail()) {
                    std::cout << "wrong!!!";
                    state_ = 1;
                    std::cin.clear();
                    std::cin.ignore(std::numeric_limits<streamsize>::max(), '\n');
                }
            }

            void load(
                unsigned char & t)
            {
                unsigned short t1;
                std::cin >> t1;
                if (std::cin.fail()) {
                    std::cout << "wrong!!!";
                    state_ = 1;
                    std::cin.clear();
                    std::cin.ignore(std::numeric_limits<streamsize>::max(), '\n');
                }
                if (t1 > 255)
                    state_ = 1;
                else
                    t = (unsigned char)t1;
            }

            /// 从流中读出变标准库字符串
            void load(
                std::string & t)
            {
                std::cin >> t;
                if (std::cin.fail()) {
                    std::cout << "wrong!!!";
                    state_ = 1;
                    std::cin.clear();
                    std::cin.ignore(std::numeric_limits<streamsize>::max(), '\n');
                }
            }

            using basic_iarchive<console_iarchive>::load;

            void load_start(
                std::string const & name)
            {
                std::cout << ident_ << name << ": ";
            }

            void sub_start()
            {
                std::cout << std::endl;
                ident_ += "  ";
            }

            void sub_end()
            {
                ident_.erase(ident_.size() - 2);
            }

        private:
            std::string ident_;
        };


    } // namespace archive

} // namespace utils

#endif // CONSOLE_IARCHIVE_H
