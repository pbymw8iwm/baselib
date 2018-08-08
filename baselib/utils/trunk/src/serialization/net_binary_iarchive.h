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
        ת���ֽ�˳���ģ�壬����˳��->����˳��

        Ϊ���ñ������Զ�����Ӧ��ת������
        ע�⣺û��ʵ��8���ֽ����ݵ��ֽ�˳��ת��
         */ 
        template <typename T, int size = sizeof(T)>
        struct ntoh
        {
            static void apply(T &)
            {
            }
        };

        /// 2���ֽ����ݵ��ֽ�˳��ת��
        template <typename T>
        struct ntoh<T, 2>
        {
            static void apply(T & t)
            {
                t = (T)ntohs(t);
            }
        };

        /// 4���ֽ����ݵ��ֽ�˳��ת��
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
            /// �����ж�������
            template<class T>
            void load(
                T & t)
            {
                load_binary((char *)&t, sizeof(T));
                // ִ���ֽ�˳��ת��
                if (state_) return;
                ntoh<T>::apply(t);
            }

            /// �����飬ֱ�Ӷ�����������ȡ�����char������Ż�ʵ��
            void load_array(
                serialization::array<char> & a)
            {
                if (state_) return;
                if (buf_.sgetn((char *)a.address(), (std::streamsize)a.count()) 
                    != (std::streamsize)a.count())
                    state_ = 1;
            }

            /// �ж�ĳ�������Ƿ�����Ż�����Ķ�
            /// ֻ��char�����ܹ�ֱ�Ӷ����飬����Ҫת���ֽ�˳��
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

