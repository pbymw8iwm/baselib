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
        ת���ֽ�˳���ģ�壬����˳��->����˳��

        Ϊ���ñ������Զ�����Ӧ��ת������
        ע�⣺û��ʵ��8���ֽ����ݵ��ֽ�˳��ת��
        */ 
        template <typename T, int size = sizeof(T)>
        struct hton
        {
            static void apply(
                T &)
            {
            }
        };

        /// 2���ֽ����ݵ��ֽ�˳��ת��
        template <typename T>
        struct hton<T, 2>
        {
            static void apply(
                T & t)
            {
                t = (T)htons(t);
            }
        };

        /// 4���ֽ����ݵ��ֽ�˳��ת��
        template <typename T>
        struct hton<T, 4>
        {
            static void apply(
                T & t)
            {
                t = (T)htonl((u_long)t);
            }
        };

        /// �����ֽ�˳�����л���
        class net_binary_oarchive
            : public basic_oarchive<net_binary_oarchive>
        {
            friend class basic_oarchive<net_binary_oarchive>;

        public:
            /// ��ostream����
            net_binary_oarchive(
                std::ostream & os)
                : basic_oarchive<net_binary_oarchive>(*os.rdbuf())
            {
            }

            /// ���л�ͨ������ʵ��
            template <typename T>
            void save(
                T const & t)
            {
                // ��ת���ֽ�˳��
                T t1 = t;
                hton<T>::apply(t1);
                save_binary((char const *)&t1, sizeof(T));
            }

            using basic_oarchive<net_binary_oarchive>::save;

            // ���л����飬ֱ�Ӷ���������д�룬�����char������Ż�ʵ��
            void save_array(
                serialization::array<char> const & a)
            {
                save_binary((char const *)a.address(), (std::streamsize)a.count());
            }

            /// �ж�ĳ�������Ƿ�����Ż���������л�
            /// ֻ��char�����ܹ�ֱ�����л����飬����Ҫת���ֽ�˳��
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
