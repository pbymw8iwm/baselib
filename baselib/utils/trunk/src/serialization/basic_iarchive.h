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
            输入文档的基类

            提供“>>”、“&”操作符重载
            区别对待基本类型与标准类型的读
            @param Archive 派生自basic_iarchive的输入文档类，实现对基本类型的输入
         */
        template <typename Archive>
        class basic_iarchive
        {
        public:
            typedef false_value is_saving; ///< 表明该归档“不是”用于保存数据的
            typedef true_value is_loading; ///< 表明该归档是用于加载数据的

        protected:
            basic_iarchive(
                std::streambuf & buf)
                : buf_(buf)
                , state_(0)
            {
            }

        public:
            /// 获取派生类的指针
            Archive * This()
            {
                return static_cast<Archive *>(this);
            }

            /// 处理基本类型的读
            struct load_primitive
            {
                template<class T>
                static void invoke(
                    Archive & ar, 
                    T & t)
                {
                    // 直接调用Archive的load方法，通过load_access中转
                   ar.load(t);
                }
            };

            /// 处理标准类型（非基本类型）的读
            struct load_standard
            {
                template<class T>
                static void invoke(
                    Archive &ar, 
                    T & t)
                {
                    // 直接调用serialize方法
                    load_access::sub_start(ar);
                    serialize(ar, t);
                    load_access::sub_end(ar);
                }
            };

            /// 处理标准类型（非基本类型）的读
            struct load_standard_single_unit
            {
                template<class T>
                static void invoke(
                    Archive &ar, 
                    T & t)
                {
                    // 直接调用serialize方法
                    serialize(ar, t);
                }
            };

            /// 重载操作符“>>”
            template<class T>
            Archive & operator >> (
                T const & t)
            {
                /// 根据类型类别（基本类型，标准类型），分别处理读
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

            /// 重载操作符“&”
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
            /// 从流中读出标准库字符串
            void load(
                std::string & t)
            {
                std::size_t len;
                *(this->This()) >> len;
                if (state_) return;
                t.resize(len);
                load_binary(&t[0], len);
            }

            /// 从流中读出名字-值对
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

