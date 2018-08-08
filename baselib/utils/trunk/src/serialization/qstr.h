/// @file qstr.h

#ifndef SERIALIZATION_QSTR_H
#define SERIALIZATION_QSTR_H

#include "serialization/serialization.h"

namespace utils
{
    namespace serialization
    {
        /// ¿ìËÙ×Ö·û´®
        class qstr
        {
        public:    
            qstr(char const * ptr = 0, std::size_t size = 0)
                : ptr_(ptr)
                , size_(size)
            {
            }

            char const * ptr() const
            {
                return ptr_;
            }

            char const & operator [] (std::size_t n) const
            {
                return ptr_[n];
            }

            std::size_t size() const
            {
                return size_;
            }

        private:
            char const * ptr_;
            std::size_t size_;
        };

        template <>
        struct is_primitive_type<qstr>
        {
            static const bool value = true;
        };

    } // namespace serialization

} // namespace utils

#endif // SERIALIZATION_QSTR_H
