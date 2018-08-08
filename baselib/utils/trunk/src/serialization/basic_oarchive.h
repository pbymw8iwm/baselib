/// @file basic_oarchive.h

#ifndef BASIC_OARCHIVE_H
#define BASIC_OARCHIVE_H

#include "template/template_logic.h"
#include "serialization/serialization.h"
#include "serialization/nvp.h"
#include "serialization/string.h"

#include <streambuf>

namespace utils
{

    namespace serialization
    {

        struct save_access
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
            ����ĵ��Ļ���
            
            �ṩ��<<������&������������
            ����Դ������������׼���͵����л�
            @param Archive ������basic_oarchive������ĵ��࣬ʵ�ֶԻ������͵����
         */
        template <typename Archive>
        class basic_oarchive
        {
        public:
            typedef true_value is_saving; ///< �����ù鵵�����ڱ������ݵ�
            typedef false_value is_loading; ///< �����ù鵵�����ǡ����ڼ������ݵ�

        protected:
            basic_oarchive(
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

            /// ��������������л�
            struct save_primitive
            {
                template<class T>
                static void invoke(
                    Archive & ar, 
                    T const & t)
                {
                    // ֱ�ӵ���Archive��save������ͨ��save_access��ת
                    ar.save(t);
                }
            };

            /// �����׼���ͣ��ǻ������ͣ����л�
            struct save_standard
            {
                template<class T>
                static void invoke(
                    Archive & ar, 
                    T const & t)
                {
                    // ֱ�ӵ���serialize����
                    save_access::sub_start(ar);
                    serialize(ar, const_cast<T &>(t));
                    save_access::sub_end(ar);
                }
            };

            /// �����׼���ͣ��ǻ������ͣ����л�
            struct save_standard_single_unit
            {
                template<class T>
                static void invoke(
                    Archive & ar, 
                    T const & t)
                {
                    // ֱ�ӵ���serialize����
                    serialize(ar, const_cast<T &>(t));
                }
            };

            /// ���ز�������<<��
            template<class T>
            Archive & operator << (
                const T & t)
            {
                /// ����������𣨻������ͣ���׼���ͣ����ֱ������л�
                typedef typename if_<
                    is_primitive_type<T>, 
                    save_primitive, 
                    typename if_<
                        is_sigle_unit<T>, 
                        save_standard_single_unit, 
                        save_standard
                    >::type
                >::type invoke_type;
                invoke_type::invoke(*this->This(), t);
                return *this->This();
            }

            /// ���ز�������&��
            template<class T>
            Archive & operator & (
                const T & t)
            {
                *(this->This()) << t;
                return *this->This();
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
            /// ������д���׼���ַ���
            void save(
                std::string const & t)
            {
                *(this->This()) << t.size();
                save_binary((char const *)&t[0], t.size());
            }

            /// ������д������-ֵ��
            template<class T>
            void save(
                nvp<T> const & t)
            {
                this->This()->save_start(t.name());
                *(this->This()) << t.data();
                this->This()->save_end(t.name());
            }

            void save_binary(
                char const * p, 
                std::size_t n)
            {
                if (state_) return;
                if (buf_.sputn(p, (std::streamsize)n) 
                    != (std::streamsize)n)
                    state_ = 1;
            }

            void save_start(
                std::string const & name)
            {
            }

            void save_end(
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

        };

    } // namespace archive

} // namespace utils

#endif // BASIC_OARCHIVE_H

