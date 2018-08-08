/// @file qstr.h

#ifndef QSTR_H
#define QSTR_H

#include <cstddef>
#include <string>
#include <ostream>

#include <assert.h>

namespace utils
{
    class qstr_buffer;

    /// 快速字符串
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

        std::string const str() const
        {
            return std::string(ptr_, size_);
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
        std::size_t size_; // 长度，不包含最后的\0
    };

    class qstr_buffer
    {
    public:
        qstr_buffer()
            : use_(0)
        {
        }

        const qstr put(
            std::string const & str)
        {
            return put(&str[0], str.size());
        }

        const qstr put(
            char const * str)
        {
            return put(str, strlen(str));
        }

        const qstr put(
            qstr const & str)
        {
            return put(str.ptr(), str.size());
        }

        const qstr put(
            char const * str, 
            std::size_t len)
        {
            if (len > max_size - use_)
                return qstr();
            qstr s(&buf_[use_], len);
            memcpy(buf_ + use_, str, len);
            use_ += len;
            return s;
        }

        bool contains(
            qstr const & str)
        {
            return str.ptr() >= &buf_[0] && str.ptr() < &buf_[use_];
        }

        void clear()
        {
            use_ = 0;
        }

    private:
        static const std::size_t max_size = 65536;

    private:
        char buf_[max_size];
        std::size_t use_;
    };

    inline std::ostream & operator << (std::ostream & os, qstr const & str)
    {
        os.write(str.ptr(), str.size());
        return os;
    }

} // namespace utils

#endif // QSTR_H
