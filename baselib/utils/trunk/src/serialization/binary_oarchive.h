/// @file binary_oarchive.h

#ifndef BINARY_OARCHIVE_H
#define BINARY_OARCHIVE_H

#include "serialization/basic_oarchive.h"
#include "serialization/array.h"

#include <ostream>
#include <string>

namespace utils
{

    namespace serialization
    {

        class binary_oarchive
            : public basic_oarchive<binary_oarchive>
        {
            friend class basic_oarchive<binary_oarchive>;
            friend struct save_access;

        public:
            binary_oarchive(
                std::ostream & os)
                : basic_oarchive<binary_oarchive>(*os.rdbuf())
            {
            }

            /// ������д����������ͱ���
            template <typename T>
            void save(
                T const & t)
            {
                save_binary((char const *)&t, sizeof(T));
            }

            using basic_oarchive<binary_oarchive>::save;

            /// ������д�����飨�Ż���
            template<class T>
            void save_array(
                serialization::array<T> const & a)
            {
                save_binary((char const *)a.address(), sizeof(T) * a.count());
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

}// namespace utils

SERIALIZATION_USE_ARRAY_OPTIMIZATION(utils::serialization::binary_oarchive);

#endif // BINARY_OARCHIVE_H
