/// @file net_binary_iarchive.h

#ifndef NET_BINARY_IARCHIVE_H
#define NET_BINARY_IARCHIVE_H

#include "serialization/basic_iarchive.h"
#include "serialization/array.h"

#include <istream>

#ifdef WIN32
#include <winsock2.h>
#else
#include <netinet/in.h>
#endif

namespace utils
{

    namespace serialization
    {

        /**
        转换字节顺序的模板，网络顺序->主机顺序

        为了让编译器自动绑定相应的转换函数
        注意：没有实现8个字节数据的字节顺序转换
         */ 
        template <typename T, int size = sizeof(T)>
        struct ntoh
        {
            static void apply(T &)
            {
            }
        };

        /// 2个字节数据的字节顺序转换
        template <typename T>
        struct ntoh<T, 2>
        {
            static void apply(T & t)
            {
                t = (T)ntohs(t);
            }
        };

        /// 4个字节数据的字节顺序转换
        template <typename T>
        struct ntoh<T, 4>
        {
            static void apply(T & t)
            {
                t = (T)ntohl((u_long)t);
            }
        };

        class net_binary_iarchive
            : public basic_iarchive<net_binary_iarchive>
        {
            friend class basic_iarchive<net_binary_iarchive>;

        public:
            net_binary_iarchive(
                std::istream & is)
                : basic_iarchive<net_binary_iarchive>(*is.rdbuf())
            {
            }

        public:
            /// 从流中读出变量
            template<class T>
            void load(
                T & t)
            {
                load_binary((char *)&t, sizeof(T));
                // 执行字节顺序转换
                if (state_) return;
                ntoh<T>::apply(t);
            }

            /// 读数组，直接二进制批量读取，针对char数组的优化实现
            void load_array(
                serialization::array<char> & a)
            {
                if (state_) return;
                if (buf_.sgetn((char *)a.address(), (std::streamsize)a.count()) 
                    != (std::streamsize)a.count())
                    state_ = 1;
            }

            /// 判断某个类型是否可以优化数组的读
            /// 只有char类型能够直接读数组，不需要转换字节顺序
            template<class T>
            struct use_array_optimization
                : is_type<T, char>
            {
            };
        };
    } // namespace archive

} // namespace utils

SERIALIZATION_USE_ARRAY_OPTIMIZATION(utils::serialization::net_binary_iarchive);

#endif // NET_BINARY_IARCHIVE_H

