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

        /// ָʾһ�������Ƿ������л���������
        /// �������͵����л��������л���ֱ�ӵ������л��������л������save��load������
        template <typename T>
        struct is_primitive_type
            : is_fundamental<T>
        {
        };

        /// �������в�ֳ��������л�����
        template<class Archive, class T>
        struct member_saver {
            static void invoke(
                Archive & ar, 
                const T & t)
            {
                t.save(ar);
            }
        };

        /// �������в�ֳ����ķ����л�����
        template<class Archive, class T>
        struct member_loader {
            static void invoke(
                Archive & ar, 
                T & t)
            {
                t.load(ar);
            }
        };

        /// ���������л��������л�������
        /// ����Archive�����ͷֱ����save��load����
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

        /// �������в�ֳ��������л�����
        template<class Archive, class T>
        struct free_saver {
            static void invoke(
                Archive & ar, 
                T const & t)
            {
                save(ar, t);
            }
        };

        /// �������в�ֳ����ķ����л�����
        template<class Archive, class T>
        struct free_loader {
            static void invoke(
                Archive & ar, 
                T & t)
            {
                load(ar, t);
            }
        };

        /// ���������л��������л�������
        /// ����Archive�����ͷֱ����save��load����
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

        /// ָʾһ�������Ƿ������л���������
        template <typename T>
        struct is_sigle_unit
            : false_value
        {
        };

    }
}

/// ����serialize��ֹ��ܵĺ�
#define SERIALIZATION_SPLIT_MEMBER() \
template<class Archive> \
void serialize( \
    Archive & ar) \
{ \
    utils::serialization::split_member(ar, *this); \
}

#endif // SERIALIZATION_H
