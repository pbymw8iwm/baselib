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
            输出文档的基类
            
            提供“<<”、“&”操作符重载
            区别对待基本类型与标准类型的序列化
            @param Archive 派生自basic_oarchive的输出文档类，实现对基本类型的输出
         */
        template <typename Archive>
        class basic_oarchive
        {
        public:
            typedef true_value is_saving; ///< 表明该归档是用于保存数据的
            typedef false_value is_loading; ///< 表明该归档“不是”用于加载数据的

        protected:
            basic_oarchive(
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

            /// 处理基本类型序列化
            struct save_primitive
            {
                template<class T>
                static void invoke(
                    Archive & ar, 
                    T const & t)
                {
                    // 直接调用Archive的save方法，通过save_access中转
                    ar.save(t);
                }
            };

            /// 处理标准类型（非基本类型）序列化
            struct save_standard
            {
                template<class T>
                static void invoke(
                    Archive & ar, 
                    T const & t)
                {
                    // 直接调用serialize方法
                    save_access::sub_start(ar);
                    serialize(ar, const_cast<T &>(t));
                    save_access::sub_end(ar);
                }
            };

            /// 处理标准类型（非基本类型）序列化
            struct save_standard_single_unit
            {
                template<class T>
                static void invoke(
                    Archive & ar, 
                    T const & t)
                {
                    // 直接调用serialize方法
                    serialize(ar, const_cast<T &>(t));
                }
            };

            /// 重载操作符“<<”
            template<class T>
            Archive & operator << (
                const T & t)
            {
                /// 根据类型类别（基本类型，标准类型），分别处理序列化
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

            /// 重载操作符“&”
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
            /// 向流中写入标准库字符串
            void save(
                std::string const & t)
            {
                *(this->This()) << t.size();
                save_binary((char const *)&t[0], t.size());
            }

            /// 向流中写入名字-值对
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

