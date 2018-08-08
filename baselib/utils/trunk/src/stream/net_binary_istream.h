/// @file net_binary_istream.h

#ifndef NET_BINARY_ISTREAM_H
#define NET_BINARY_ISTREAM_H

#include "stream/basic_istream.h"

#ifdef WIN32
#include <winsock2.h>
#else
#include <netinet/in.h>
#endif

namespace utils
{

    class net_binary_istream
        : public basic_istream<net_binary_istream, uint16_t>
    {
        typedef basic_istream<net_binary_istream, uint16_t> super;
        friend class basic_istream<net_binary_istream, uint16_t>;

    public:
        net_binary_istream(char * buf, std::size_t size)
            : super(buf, size)
        {
        }

    private:
        template<class T>
        void load (T & t)
        {
            super::load_binary((char *)&t, sizeof(T));
            if (super::state_ == 0)
                ntoh<T>::apply(t);
        }

        template<class T>
        void rewind_load(T const & t)
        {
            load(t);
        }

    private:
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
                assert(0);
            }
        };

        /// 1���ֽ����ݵ��ֽ�˳��ת��
        template <typename T>
        struct ntoh<T, 1>
        {
            static void apply(T & t)
            {
                // ʲôҲ������
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

    };

} // namespace utils

#endif // NET_BINARY_ISTREAM_H
