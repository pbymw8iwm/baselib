/// @file binary_iarchive.h

#ifndef BINARY_IARCHIVE_H
#define BINARY_IARCHIVE_H

#include "serialization/basic_iarchive.h"
#include "serialization/array.h"

#include <istream>
#include <string>

namespace utils
{

    namespace serialization
    {

        class binary_iarchive
            : public basic_iarchive<binary_iarchive>
        {
            friend class basic_iarchive<binary_iarchive>;
        public:
            binary_iarchive(
                std::istream & is)
                : basic_iarchive<binary_iarchive>(*is.rdbuf())
            {
            }

        public:
            /// �����ж�������
            template<class T>
            void load(
                T & t)
            {
                load_binary((char *)&t, sizeof(T));
            }

            /// �����ж������飨�Ż���
            template<class T>
            void load_array(
                serialization::array<T> & a)
            {
                load_binary((char *)a.address(), sizeof(T) * a.count());
            }
    
            /// �ж�ĳ�������Ƿ�����Ż���������л�
            /// ֻ�л��������ܹ�ֱ�����л�����
            template<class T>
            struct use_array_optimization
                : is_fundamental<T>
            {
            };
        };


    } // namespace archive

} // namespace utils

SERIALIZATION_USE_ARRAY_OPTIMIZATION(utils::serialization::binary_iarchive);

#endif // BINARY_IARCHIVE_H
