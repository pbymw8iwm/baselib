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
            ���ض����������

            �����ƶ���ָ�롣
            */
            const_buffer data(std::size_t n)
            {
                if (gptr() + n > pptr())
                    n = pptr() - gptr();
                return const_buffer(gptr(), n);
            }

            /**
            ��д����������ύ�Ķ�����

            ׷�Ӵ�дָ�뿪ʼ�� @c n �ֽ����ݵ������棬дָ����ǰ�ƶ� @c n �ֽڡ�
            ��Ҫ���ⲿд��ʵ�����ݣ�Ȼ���ύ
             */
            void commit(std::size_t n)
            {
                if (pptr() + n > epptr())
                    n = epptr() - pptr();
                pbump(static_cast<int>(n));
                setg(eback(), gptr(), pptr());
            }

            /**
            �Ӷ������Ƴ�����

            ��ָ����ǰ�ƶ� @c n �ֽڡ�
            ��Ҫ���ⲿ����ʵ�����ݣ�Ȼ���Ƴ���Ӧ����
            */
            void consume(std::size_t n)
            {
                if (gptr() + n > pptr())
                    n = pptr() - gptr();
                gbump(static_cast<int>(n));
            }

            /**
            ��д������׼��һ�οռ�

            �����ƶ�дָ�롣
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
            char_type * buf_; ///< �����׵�ַ
            std::size_t buf_size_; ///< �����С

        }; // class archive_buffer

    } // namespace serialization

} // namespace utils


#endif // ARCHIVE_BUFFER_H
