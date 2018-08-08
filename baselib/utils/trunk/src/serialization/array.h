/// @file array.h

#ifndef SERIALIZATION_ARRAY_H
#define SERIALIZATION_ARRAY_H

#include "template/template_logic.h"
#include "serialization/serialization.h"

namespace utils
{
    namespace serialization
    {
        /// 指示Archive是否支持某个类型T的数组优化序列化
        /// 默认不支持
        template <class Archive, typename T>
        struct use_array_optimization : false_value {};

        /// 内部一种特殊的数组类型，某些Archive类支持对其进行优化的序列化
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

            // 默认实现
            template<class Archive>
            void serialize_optimized(Archive & ar, false_type)
            {
                // 通过循环单个序列化
                std::size_t c = count();
                value_type * t = address();
                while(0 < c--)
                    ar & *t++;
            }

            // 优化实现
            template<class Archive>
            void serialize_optimized(Archive & ar, true_type)
            {
                split_member(ar, *this);
            }

            // 优化实现序列化
            template<class Archive>
            void save(Archive & ar) const
            {
                ar.save_array(*this);
            }

            // 优化实现反序列化
            template<class Archive>
            void load(Archive & ar)
            {
                ar.load_array(*this);
            }

            template<class Archive>
            void serialize(Archive & ar)
            {
                // 根据use_array_optimization指示分别调用优化与非优化版本的序列化方法
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

        /// 指定数组指针和数组大小构造array
        template<class T>
        inline const array<T> make_array(T * t, std::size_t s){
                return array<T>(t, s);
        }

        /// 从定常数组构造array
        template<class T, std::size_t s>
        inline const array<T> make_array(T (&t)[s]){
            return array<T>(&t[0], s);
        }
    }    
}

/// Archive用此宏指示其支持某些类型的数组优化序列化
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
