/// @file nvp.h

#ifndef SERIALIZATION_NVP_H
#define SERIALIZATION_NVP_H

#include "serialization/serialization.h"

namespace utils
{
    namespace serialization
    {

        template <typename T> // T�Ƿ�const����
        class nvp
        {
        public:
            nvp(
                char const * name, 
                T & t) 
                : name_(name)
                ,t_(t)
            {
            }

            T const & data() const
            {
                return t_;
            }

            T & data()
            {
                return t_;
            }

            char const * name() const
            {
                return name_;
            }

            /// ��֧��nvp������ֱ�����л�ֵ
            template <typename Archive>
            void serialize(Archive & ar)
            {
                ar & t_;
            }

        private:
            char const * name_;
            T & t_;
        };

        template <typename T>
        struct is_primitive_type<nvp<T> >
        {
            static const bool value = true;
        };

        /// �Ӷ������鹹��array
        template<class T>
        nvp<T> const make_nvp(
            char const * name, 
            T const & t)
        {
            return nvp<T>(name, const_cast<T &>(t));
        }

    } // namespace serialization

} // namespace utils

#define STRINGLIZE(s) #s

#define SERIALIZATION_NVP(v) \
    utils::serialization::make_nvp(STRINGLIZE(v), v)

#endif // SERIALIZATION_NVP_H
