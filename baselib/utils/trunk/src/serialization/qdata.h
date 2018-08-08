/// @file qdata.h

#ifndef SERIALIZATION_QDATA_H
#define SERIALIZATION_QDATA_H

#include "serialization/serialization.h"

namespace utils
{
    namespace serialization
    {
        /// ¿ìËÙ×Ö·û´®
        class qdata
        {
        public:    
            qdata(char const * ptr = 0, std::size_t size = 0)
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
        struct is_primitive_type<qdata>
        {
            static const bool value = true;
        };

    } // namespace serialization

} // namespace utils

#endif // SERIALIZATION_QDATA_H
