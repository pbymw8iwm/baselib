/// @file serialization.h

#ifndef SERIALIZATION_H
#define SERIALIZATION_H

#include "template/template_type_check.h"

namespace utils
{
    namespace serialization
    {
        template<class Archive, class T>
        inline void serialize(Archive & ar, T & t){
            t.serialize(ar);
        }

        /// 指示一个类型是否是序列化基本类型
        /// 基本类型的序列化（反序列化）直接调用序列化（反序列化）类的save（load）方法
        template <typename T>
        struct is_primitive_type
            : is_fundamental<T>
        {
        };

        /// 调用类中拆分出来的序列化方法
        template<class Archive, class T>
        struct member_saver {
            static void invoke(
                Archive & ar, 
                const T & t)
            {
                t.save(ar);
            }
        };

        /// 调用类中拆分出来的反序列化方法
        template<class Archive, class T>
        struct member_loader {
            static void invoke(
                Archive & ar, 
                T & t)
            {
                t.load(ar);
            }
        };

        /// 拆分类的序列化（反序列化）方法
        /// 根据Archive的类型分别调用save，load方法
        template<class Archive, class T>
        inline void split_member(
            Archive & ar, T & t)
        {
            typedef typename if_c<
                (bool)Archive::is_saving::value, 
                member_saver<Archive, T>, 
                member_loader<Archive, T>
            >::type typex;
            typex::invoke(ar, t);
        }

        /// 调用类中拆分出来的序列化方法
        template<class Archive, class T>
        struct free_saver {
            static void invoke(
                Archive & ar, 
                T const & t)
            {
                save(ar, t);
            }
        };

        /// 调用类中拆分出来的反序列化方法
        template<class Archive, class T>
        struct free_loader {
            static void invoke(
                Archive & ar, 
                T & t)
            {
                load(ar, t);
            }
        };

        /// 拆分类的序列化（反序列化）方法
        /// 根据Archive的类型分别调用save，load方法
        template<class Archive, class T>
        inline void split_free(
            Archive & ar, T & t)
        {
            typedef typename if_c<
                (bool)Archive::is_saving::value, 
                free_saver<Archive, T>, 
                free_loader<Archive, T>
            >::type typex;
            typex::invoke(ar, t);
        }

        /// 指示一个类型是否是序列化基本类型
        template <typename T>
        struct is_sigle_unit
            : false_value
        {
        };

    }
}

/// 定义serialize拆分功能的宏
#define SERIALIZATION_SPLIT_MEMBER() \
template<class Archive> \
void serialize( \
    Archive & ar) \
{ \
    utils::serialization::split_member(ar, *this); \
}

#endif // SERIALIZATION_H
