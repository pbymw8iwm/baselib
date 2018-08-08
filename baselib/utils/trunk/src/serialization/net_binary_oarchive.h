/// @file binary_oarchive.h

#ifndef NET_BINARY_OARCHIVE_H
#define NET_BINARY_OARCHIVE_H

#include "serialization/basic_oarchive.h"
#include "serialization/array.h"

#include <ostream>

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
        转换字节顺序的模板，主机顺序->网络顺序

        为了让编译器自动绑定相应的转换函数
        注意：没有实现8个字节数据的字节顺序转换
        */ 
        template <typename T, int size = sizeof(T)>
        struct hton
        {
            static void apply(
                T &)
            {
            }
        };

        /// 2个字节数据的字节顺序转换
        template <typename T>
        struct hton<T, 2>
        {
            static void apply(
                T & t)
            {
                t = (T)htons(t);
            }
        };

        /// 4个字节数据的字节顺序转换
        template <typename T>
        struct hton<T, 4>
        {
            static void apply(
                T & t)
            {
                t = (T)htonl((u_long)t);
            }
        };

        /// 网络字节顺序序列化类
        class net_binary_oarchive
            : public basic_oarchive<net_binary_oarchive>
        {
            friend class basic_oarchive<net_binary_oarchive>;

        public:
            /// 从ostream构造
            net_binary_oarchive(
                std::ostream & os)
                : basic_oarchive<net_binary_oarchive>(*os.rdbuf())
            {
            }

            /// 序列化通用类型实现
            template <typename T>
            void save(
                T const & t)
            {
                // 先转换字节顺序
                T t1 = t;
                hton<T>::apply(t1);
                save_binary((char const *)&t1, sizeof(T));
            }

            using basic_oarchive<net_binary_oarchive>::save;

            // 序列化数组，直接二进制批量写入，是针对char数组的优化实现
            void save_array(
                serialization::array<char> const & a)
            {
                save_binary((char const *)a.address(), (std::streamsize)a.count());
            }

            /// 判断某个类型是否可以优化数组的序列化
            /// 只有char类型能够直接序列化数组，不需要转换字节顺序
            template<class T>
            struct use_array_optimization
                : is_type<T, char>
            {
            };
        };

    } // namespace archive

} // namespace utils

SERIALIZATION_USE_ARRAY_OPTIMIZATION(utils::serialization::net_binary_oarchive);

#endif // NET_BINARY_OARCHIVE_H
