/// @file mark.h

#ifndef MARK_H
#define MARK_H

#include <cstddef>

namespace utils
{
    /// 流标志，可以回写
    template <typename T>
    class mark
    {
    public:
        mark(
            T & t) 
            :t_(t)
            , p_(NULL)
        {

        }

        T & data() const
        {
            return t_;
        }

        char * ptr() const
        {
            return p_;
        }

        void ptr(char * p) const
        {
            p_ = p;
        }

    private:
        T & t_;
        mutable char * p_;
    };


} // namespace utils

#endif // MARK_H
