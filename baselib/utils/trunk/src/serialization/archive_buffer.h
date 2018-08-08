/// @file archive_buffer.h

#ifndef ARCHIVE_BUFFER_H
#define ARCHIVE_BUFFER_H

#include <streambuf>
#include <stdexcept>

namespace utils
{
    namespace serialization
    {

        class const_buffer
        {
        public:
            const_buffer(const char * ptr, std::size_t n)
                : ptr_(ptr)
                , n_(n)
            {
            }

            const char * ptr() const
            {
                return ptr_;
            }

            char const & operator [] (std::size_t n) const
            {
                return ptr_[n];
            }

            size_t size() const
            {
                return n_;
            }

        private:
            const char * ptr_;
            std::size_t n_;
        };

        class mutable_buffer
        {
        public:
            mutable_buffer(char * ptr, std::size_t n)
                : ptr_(ptr)
                , n_(n)
            {
            }

            char * ptr() const
            {
                return ptr_;
            }

            char & operator [] (std::size_t n) const
            {
                return ptr_[n];
            }

            size_t size() const
            {
                return n_;
            }

        private:
            mutable char * ptr_;
            std::size_t n_;
        };

        class archive_buffer
            : public std::streambuf
        {
        public:
            archive_buffer(
                char_type * buf, 
                std::size_t buf_size, 
                std::size_t data_size = 0)
                : buf_(buf)
                , buf_size_(buf_size)
            {
                setg(buf_, buf, buf + data_size);
                setp(buf_, buf + buf_size);
                pbump(data_size);
            }

            /**
            返回读缓存的数据

            并不移动读指针。
            */
            const_buffer data(std::size_t n)
            {
                if (gptr() + n > pptr())
                    n = pptr() - gptr();
                return const_buffer(gptr(), n);
            }

            /**
            将写缓存的数据提交的读缓存

            追加从写指针开始的 @c n 字节数据到读缓存，写指针向前移动 @c n 字节。
            需要在外部写入实际数据，然后提交
             */
            void commit(std::size_t n)
            {
                if (pptr() + n > epptr())
                    n = epptr() - pptr();
                pbump(static_cast<int>(n));
                setg(eback(), gptr(), pptr());
            }

            /**
            从读缓存移除数据

            读指针向前移动 @c n 字节。
            需要在外部读出实际数据，然后移除相应数据
            */
            void consume(std::size_t n)
            {
                if (gptr() + n > pptr())
                    n = pptr() - gptr();
                gbump(static_cast<int>(n));
            }

            /**
            在写缓存中准备一段空间

            并不移动写指针。
            */
            mutable_buffer prepare(std::size_t n)
            {
                if (pptr() + n > epptr())
                    n = epptr() - pptr();
                return mutable_buffer(pptr(), n);
            }

        protected:
            virtual int_type underflow()
            {
                return traits_type::eof();
            }

            virtual int_type overflow(int_type c)
            {
                throw std::length_error("archive_buffer too long");
                return traits_type::not_eof(c);
            }

        private:
            char_type * buf_; ///< 缓存首地址
            std::size_t buf_size_; ///< 缓存大小

        }; // class archive_buffer

    } // namespace serialization

} // namespace utils


#endif // ARCHIVE_BUFFER_H
