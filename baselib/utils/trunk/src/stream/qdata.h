/// @file qdata.h

#ifndef QDATA_H
#define QDATA_H

#include <cstddef>

namespace utils
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

} // namespace utils

#endif // QDATA_H
