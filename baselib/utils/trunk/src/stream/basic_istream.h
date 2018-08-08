/// @file basic_istream.h

#ifndef BASIC_ISTREAM_H
#define BASIC_ISTREAM_H

#include "stream/qstr.h"
#include "stream/qdata.h"
#include "stream/batch_sequence.h"
#include "stream/mark.h"

#include <cstddef>
#include <string>
#include <vector>
#include <map>

namespace utils
{

    template <typename Stream, typename SizeType = std::size_t>
    class basic_istream
    {
    public:
        basic_istream(char * buf, std::size_t size)
            : buf_(buf)
            , gptr_(buf)
            , egptr_(buf + size)
            , state_(0)
        {
        }

    public:
        /// ���ز�������>>��
        template<class T>
        Stream & operator >> (const T & t)
        {
            (const_cast<T &>(t)).serialize(*this->This());
            return *this->This();
        }

        /// ���ز�������&��
        template<class T>
        Stream & operator & (T & t)
        {
            (*this->This()) >> t;
            return *this->This();
        }

#define DEFINE_LOAD_PRIMITIVE_TYPE(T) \
        Stream & operator >> (T & t) \
        { \
            this->This()->load(t); \
            return *this->This(); \
        }

        DEFINE_LOAD_PRIMITIVE_TYPE(unsigned char)
        DEFINE_LOAD_PRIMITIVE_TYPE(unsigned short)
        DEFINE_LOAD_PRIMITIVE_TYPE(unsigned int)
        DEFINE_LOAD_PRIMITIVE_TYPE(unsigned long)
        DEFINE_LOAD_PRIMITIVE_TYPE(unsigned long long)
        DEFINE_LOAD_PRIMITIVE_TYPE(signed char)
        DEFINE_LOAD_PRIMITIVE_TYPE(signed short)
        DEFINE_LOAD_PRIMITIVE_TYPE(signed int)
        DEFINE_LOAD_PRIMITIVE_TYPE(signed long)
        DEFINE_LOAD_PRIMITIVE_TYPE(signed long long)
        DEFINE_LOAD_PRIMITIVE_TYPE(bool)
        DEFINE_LOAD_PRIMITIVE_TYPE(char)

        /// �����ж���batch_sequence
        template<class Sequence>
        Stream & operator >> (
            batch_sequence<Sequence> & t)
        {
            SizeType len = 0;
            (*this->This()) >> len;
            if (state_ == 0) {
                t.reserve(len);
            }
            while (len-- > 0) {
                (*this->This()) >> t.current();
                if (state_ == 0)
                    t.next();
                else
                    break;
            }
            return *this->This();
        }

        /// �����ж�����׼��vector
        template<class T>
        Stream & operator >> (
            std::vector<T> & t)
        {
            SizeType len;
            (*this->This()) >> len;
            if (state_ == 0) 
                t.clear();
            while (state_ == 0 && len-- > 0) {
                t.push_back(T());
                (*this->This()) >> t.back();
            }
            return *this->This();
        }

        /// �����ж�����׼��map
        template<class K, class T>
        Stream & operator >> (
            std::map<K, T> & m)
        {
            SizeType len;
            (*this->This()) >> len;
            if (state_ == 0) 
                m.clear();
            while (state_ == 0 && len-- > 0) {
                K k;
                T t;
                (*this->This()) >> k >> t;
                if (state_ == 0)
                    m[k] = t;
            }
            return *this->This();
        }

        /// �����ж�����׼���ַ���
        Stream & operator >> (
            std::string & t)
        {
            SizeType len;
            (*this->This()) >> len;
            if (state_ == 0) {
                if (in_avail() >= len) {
                    t.resize(len);
                    load_binary(&t[0], len);
                } else {
                    state_ = 1;
                }
            }
            return *this->This();
        }

        /// �����ж��������ַ���
        Stream & operator >> (
            qstr & t)
        {
            SizeType len;
            (*this->This()) >> len;
            if (len < 1)
                state_ = 1;
            if (state_ == 0) {
                if (in_avail() < len
                    || gptr_[len - 1] != 0) { // ���һ���ֽڱ����ǽ�������0��
                    state_ = 1;
                } else {
                    t = qstr(gptr_, len - 1);
                    gptr_ += len;
                }
            }
            return *this->This();
        }

        /// �����ж������ٶ���������
        Stream & operator >> (
            qdata & t)
        {
            SizeType len;
            (*this->This()) >> len;
            if (state_ == 0) {
                if (in_avail() < len)
                    state_ = 1;
                else
                    t = qdata(gptr_, len);
            }
            return *this->This();
        }

        /// �����ж������д����
        template <typename T>
        Stream & operator >> (
            mark<T> & t)
        {
            if (t.ptr() == 0) {
                t.ptr(gptr_);
                (*this->This()) >> t.data();
            } else {
                char * gptr_save = gptr_;
                gptr_ = t.ptr();
                this->This()->rewind_load(t.data());
                gptr_ = gptr_save;
            }
            return *this->This();
        }

        operator bool ()
        {
            return state_ == 0;
        }

        bool operator ! ()
        {
            return state_ != 0;
        }

        char const * in_ptr()
        {
            return gptr_;
        }

        std::size_t in_avail()
        {
            return (std::size_t)(egptr_ - gptr_);
        }

        void skip(std::size_t n)
        {
            if (in_avail() < n)
                state_ = 1;
            else
                gptr_ += n;
        }

        void fail()
        {
            state_ = 2;
        }

    protected:
        void load_binary(char * data, std::size_t size)
        {
            if (in_avail() >= size) {
                memcpy(data, gptr_, size);
                gptr_ += size;
            } else
                state_ = 1;
        }

    private:
        /// ��ȡ�������ָ��
        Stream * This()
        {
            return static_cast<Stream *>(this);
        }

    protected:
        char * buf_;
        char * gptr_;
        char * egptr_;
        int state_;
    };

} // namespace utils

#endif // BASIC_ISTREAM_H
