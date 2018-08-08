/// @file net_binary_ostream.h

#ifndef NET_BINARY_OSTREAM_H
#define NET_BINARY_OSTREAM_H

#include "stream/basic_ostream.h"

#ifdef WIN32
#include <winsock2.h>
#else
#include <netinet/in.h>
#endif

namespace utils
{

    class net_binary_ostream
        : public basic_ostream<net_binary_ostream, uint16_t>
    {
        typedef basic_ostream<net_binary_ostream, uint16_t> super;
        friend class basic_ostream<net_binary_ostream, uint16_t>;

    public:
        net_binary_ostream(char * buf, std::size_t size)
            : super(buf, size)
        {
        }

    private:
        template<class T>
        void save(T const & t)
        {
            T t1 = t;
            hton<T>::apply(t1);
            super::save_binary((char const *)&t1, sizeof(T));
        }

        template<class T>
        void rewind_save(T const & t)
        {
           save(t);
        }

    private:
        /**
        转换字节顺序的模板，主机顺序->网络顺序

        为了让编译器自动绑定相应的转换函数
        注意：没有实现8个字节数据的字节顺序转换
        */ 
        template <typename T, int size = sizeof(T)>
        struct hton
        {
            static void apply(T &)
            {
                assert(0);
            }
        };

        /// 1个字节数据的字节顺序转换
        template <typename T>
        struct hton<T, 1>
        {
            static void apply(T & t)
            {
                // 什么也不用做
            }
        };

        /// 2个字节数据的字节顺序转换
        template <typename T>
        struct hton<T, 2>
        {
            static void apply(T & t)
            {
                t = (T)htons(t);
            }
        };

        /// 4个字节数据的字节顺序转换
        template <typename T>
        struct hton<T, 4>
        {
            static void apply(T & t)
            {
                t = (T)htonl((u_long)t);
            }
        };

    };


} // namespace utils

#endif // NET_BINARY_OSTREAM_H
