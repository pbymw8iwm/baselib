/// @file array.h

#ifndef SERIALIZATION_ARRAY_H
#define SERIALIZATION_ARRAY_H

#include "template/template_logic.h"
#include "serialization/serialization.h"

namespace utils
{
    namespace serialization
    {
        /// ָʾArchive�Ƿ�֧��ĳ������T�������Ż����л�
        /// Ĭ�ϲ�֧��
        template <class Archive, typename T>
        struct use_array_optimization : false_value {};

        /// �ڲ�һ��������������ͣ�ĳЩArchive��֧�ֶ�������Ż������л�
        template<class T>
        class array
        {
        public:    
            typedef T value_type;

            array(value_type * t, std::size_t s)
                : pointer_(t)
                , count_(s)
            {
            }

            // Ĭ��ʵ��
            template<class Archive>
            void serialize_optimized(Archive & ar, false_type)
            {
                // ͨ��ѭ���������л�
                std::size_t c = count();
                value_type * t = address();
                while(0 < c--)
                    ar & *t++;
            }

            // �Ż�ʵ��
            template<class Archive>
            void serialize_optimized(Archive & ar, true_type)
            {
                split_member(ar, *this);
            }

            // �Ż�ʵ�����л�
            template<class Archive>
            void save(Archive & ar) const
            {
                ar.save_array(*this);
            }

            // �Ż�ʵ�ַ����л�
            template<class Archive>
            void load(Archive & ar)
            {
                ar.load_array(*this);
            }

            template<class Archive>
            void serialize(Archive & ar)
            {
                // ����use_array_optimizationָʾ�ֱ�����Ż�����Ż��汾�����л�����
                typedef typename if_c<(bool)use_array_optimization<Archive, T>::value, true_type, false_type>::type use_optimized;
                serialize_optimized(ar, use_optimized());
            }

            value_type * address() const
            {
                return pointer_;
            }

            std::size_t count() const
            {
                return count_;
            }


        private:
            value_type * pointer_;
            std::size_t const count_;
        };

        /// ָ������ָ��������С����array
        template<class T>
        inline const array<T> make_array(T * t, std::size_t s){
                return array<T>(t, s);
        }

        /// �Ӷ������鹹��array
        template<class T, std::size_t s>
        inline const array<T> make_array(T (&t)[s]){
            return array<T>(&t[0], s);
        }
    }    
}

/// Archive�ô˺�ָʾ��֧��ĳЩ���͵������Ż����л�
#define SERIALIZATION_USE_ARRAY_OPTIMIZATION(Archive) \
namespace utils \
{ \
    namespace serialization \
    { \
        template <typename T> \
        struct use_array_optimization<Archive, T> \
            : Archive::use_array_optimization<T> \
        { \
        }; \
    } \
}

#endif // SERIALIZATION_ARRAY_H
