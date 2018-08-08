/// @file text_iarchive.h

#ifndef TEXT_IARCHIVE_H
#define TEXT_IARCHIVE_H

#include "serialization/basic_iarchive.h"

#include <istream>
#include <string>

namespace utils
{

    namespace serialization
    {

        class text_iarchive
            : public basic_iarchive<text_iarchive>
        {
            friend class basic_iarchive<text_iarchive>;

        public:
            text_iarchive(
                std::istream & is)
                : basic_iarchive<text_iarchive>(*is.rdbuf())
                , is_(is)
            {
            }

        public:
            /// 从流中读出变量
            template<class T>
            void load(
                T & t)
            {
                if (state_) return;
                is_ >> t;
                if (is_.fail())
                    state_ = 1;
            }

            /// 从流中读出标准库字符串
            void load(
                std::string & t)
            {
                std::size_t len;
                load(len);
                if (state_) return;
                t.resize(len);
                if (is_.get() == EOF) { // 跳过空格
                    state_ = 1;
                    return;
                }
                load_binary(&t[0], len);
            }

            using basic_iarchive<text_iarchive>::load;

        private:
            std::istream & is_;
        };

    } // namespace archive

} // namespace utils

#endif // TEXT_IARCHIVE_H
