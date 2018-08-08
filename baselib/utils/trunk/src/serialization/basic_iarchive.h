/// @file basic_iarchive.h

#ifndef BASIC_IARCHIVE_H
#define BASIC_IARCHIVE_H

#include "template/template_logic.h"
#include "serialization/serialization.h"
#include "serialization/nvp.h"
#include "serialization/string.h"

#include <streambuf>

namespace utils
{

    namespace serialization
    {

        struct load_access
        {
            template <typename Archive>
            static void sub_start(Archive & ar)
            {
                ar.sub_start();
            }

            template <typename Archive>
            static void sub_end(Archive & ar)
            {
                ar.sub_end();
            }
        };

        /** 
            �����ĵ��Ļ���

            �ṩ��>>������&������������
            ����Դ������������׼���͵Ķ�
            @param Archive ������basic_iarchive�������ĵ��࣬ʵ�ֶԻ������͵�����
         */
        template <typename Archive>
        class basic_iarchive
        {
        public:
            typedef false_value is_saving; ///< �����ù鵵�����ǡ����ڱ������ݵ�
            typedef true_value is_loading; ///< �����ù鵵�����ڼ������ݵ�

        protected:
            basic_iarchive(
                std::streambuf & buf)
                : buf_(buf)
                , state_(0)
            {
            }

        public:
            /// ��ȡ�������ָ��
            Archive * This()
            {
                return static_cast<Archive *>(this);
            }

            /// ����������͵Ķ�
            struct load_primitive
            {
                template<class T>
                static void invoke(
                    Archive & ar, 
                    T & t)
                {
                    // ֱ�ӵ���Archive��load������ͨ��load_access��ת
                   ar.load(t);
                }
            };

            /// �����׼���ͣ��ǻ������ͣ��Ķ�
            struct load_standard
            {
                template<class T>
                static void invoke(
                    Archive &ar, 
                    T & t)
                {
                    // ֱ�ӵ���serialize����
                    load_access::sub_start(ar);
                    serialize(ar, t);
                    load_access::sub_end(ar);
                }
            };

            /// �����׼���ͣ��ǻ������ͣ��Ķ�
            struct load_standard_single_unit
            {
                template<class T>
                static void invoke(
                    Archive &ar, 
                    T & t)
                {
                    // ֱ�ӵ���serialize����
                    serialize(ar, t);
                }
            };

            /// ���ز�������>>��
            template<class T>
            Archive & operator >> (
                T const & t)
            {
                /// ����������𣨻������ͣ���׼���ͣ����ֱ����
                typedef typename if_<
                    is_primitive_type<T>, 
                    load_primitive, 
                    typename if_<
                        is_sigle_unit<T>, 
                        load_standard_single_unit, 
                        load_standard
                    >::type
                >::type invoke_type;
                invoke_type::invoke(*this->This(), const_cast<T &>(t));
                return *this->This();
            }

            /// ���ز�������&��
            template<class T>
            Archive & operator & (
                T & t)
            {
                return *(this->This()) >> t;
            }

            operator bool ()
            {
                return state_ == 0;
            }

            bool operator ! ()
            {
                return state_ != 0;
            }

            void fail()
            {
                state_ = 2;
            }

        protected:
            /// �����ж�����׼���ַ���
            void load(
                std::string & t)
            {
                std::size_t len;
                *(this->This()) >> len;
                if (state_) return;
                t.resize(len);
                load_binary(&t[0], len);
            }

            /// �����ж�������-ֵ��
            template<class T>
            void load(nvp<T> & t)
            {
                this->This()->load_start(t.name());
                *(this->This()) >> t.data();
                this->This()->load_end(t.name());
            }

            void load_binary(char * p, std::size_t n)
            {
                if (state_) return;
                if (buf_.sgetn(p, (std::streamsize)n) 
                    != (std::streamsize)n)
                    state_ = 1;
            }

            void load_start(
                std::string const & name)
            {
            }

            void load_end(
                std::string const & name)
            {
            }

            void sub_start()
            {
            }

            void sub_end()
            {
            }

        protected:
            std::streambuf & buf_;
            int state_;
        }; // class basic_iarchive

    }  // namespace archive

} // namespace utils

#endif // BASIC_IARCHIVE_H

