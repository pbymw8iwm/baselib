/// @file basic_ostream.h

#ifndef BASIC_OSTREAM_H
#define BASIC_OSTREAM_H

#include "stream/qstr.h"
#include "stream/qdata.h"
#include "stream/batch_sequence.h"
#include "stream/mark.h"

#include <cstddef>
#include <string>
#include <vector>

namespace utils
{

    template <typename Stream, typename SizeType = std::size_t>
    class basic_ostream
    {
    public:
        basic_ostream(
            char * buf, 
            std::size_t size)
            : buf_(buf)
            , pptr_(buf)
            , epptr_(buf + size)
            , state_(0)
        {
            last_ptr_ = NULL;
        }

    public:
        /// 重载操作符“<<”
        /// 向流中写入变量
        template<class T>
        Stream & operator << (
            T const & t)
        {
            T & t1 = const_cast<T&>(t);
            t1.serialize(*this->This());
            return *this->This();
        }

        /// 重载操作符“&”
        template<class T>
        Stream & operator & (
            T & t)
        {
            (*this) << t;
            return *this->This();
        }

#define DEFINE_SAVE_PRIMITIVE_TYPE(T) \
        Stream & operator << ( \
            T const & t) \
        { \
            this->This()->save(t); \
            return *this->This(); \
        }

        DEFINE_SAVE_PRIMITIVE_TYPE(unsigned char)
        DEFINE_SAVE_PRIMITIVE_TYPE(unsigned short)
        DEFINE_SAVE_PRIMITIVE_TYPE(unsigned int)
        DEFINE_SAVE_PRIMITIVE_TYPE(unsigned long)
        DEFINE_SAVE_PRIMITIVE_TYPE(unsigned long long)
        DEFINE_SAVE_PRIMITIVE_TYPE(signed char)
        DEFINE_SAVE_PRIMITIVE_TYPE(signed short)
        DEFINE_SAVE_PRIMITIVE_TYPE(signed int)
        DEFINE_SAVE_PRIMITIVE_TYPE(signed long)
        DEFINE_SAVE_PRIMITIVE_TYPE(signed long long)
        DEFINE_SAVE_PRIMITIVE_TYPE(bool)
        DEFINE_SAVE_PRIMITIVE_TYPE(char)

        /// 向流中写入batch_sequence
        template<class Sequence>
        Stream & operator << (
            batch_sequence<Sequence> const & t)
        {
            SizeType num = (SizeType)t.remain();
            mark<SizeType> mark_num(num);
            (*this->This()) << mark_num;
            if (state_ == 0) {
                for (SizeType i = 0; i < num;) {
                    (*this->This()) << t.current();
                    if (state_ == 0) {
                        t.next();
                        i++;
						last_ptr_ = pptr_;	//记录本次的地址
                    } else {
                    	pptr_ = (last_ptr_ == NULL ? pptr_:last_ptr_);	//回退到上一个成功的位置
                        break;
                    }
                }
                state_ = 0; // 清除错误标识
                num -= (SizeType)t.remain();
                (*this->This()) << mark_num;
            }
            return *this->This();
        }

        /// 向流中写入标准库vector
        template<class T>
        Stream & operator << (
            std::vector<T> const & t)
        {
            (*this->This()) << (SizeType)t.size();
            for (SizeType i = 0; state_ == 0 && i < (SizeType)t.size(); i++) {
                (*this->This()) << t[i];
            }
            return *this->This();
        }

        /// 向流中写入标准库map
        template<class K, class T>
        Stream & operator << (
            std::map<K, T> const & m)
        {
            (*this->This()) << (SizeType)m.size();
            for (typename std::map<K, T>::const_iterator i = m.begin(); state_ == 0 && i != m.end(); ++i) {
                (*this->This()) << i->first << i->second;
            }
            return *this->This();
        }

        /// 向流中写入标准库字符串
        Stream & operator << (
            std::string const & t)
        {
            (*this->This()) << (SizeType)t.size();
            if (state_ == 0)
                save_binary(&t[0], t.size());
            return *this->This();
        }

        /// 向流中写入快速字符串
        Stream & operator << (
            qstr const & t)
        {
            SizeType len = (SizeType)t.size() + 1; // 长度包含最后一个结束符“0”,但不要求最后qstr的缓存中包含结束符“0”
            (*this->This()) << len;
            if (state_ == 0 && out_avail() >= t.size() + 1) {
                memcpy(pptr_, t.ptr(), t.size());
                pptr_ += t.size();
                *pptr_++ = 0;
            }
            return *this->This();
        }

        /// 向流中写入快速二进制数据
        Stream & operator << (
            qdata const & t)
        {
            SizeType len = t.size();
            (*this->This()) << len;
            if (state_ == 0)
                save_binary(&t[0], t.size());
            return *this->This();
        }

        /// 向流中写入随机写入标记
        template <typename T>
        Stream & operator << (mark<T> const & t)
        {
            if (t.ptr() == 0) {
                t.ptr(pptr_);
                (*this->This()) << t.data();
            } else {
                char * pptr_save = pptr_;
                pptr_ = t.ptr();
                this->This()->rewind_save(t.data());
                pptr_ = pptr_save;
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

        char * out_ptr()
        {
            return pptr_;
        }

        std::size_t out_avail()
        {
            return (std::size_t)(epptr_ - pptr_);
        }

        void skip(std::size_t n)
        {
            if (out_avail() < n)
                state_ = 1;
            else
                pptr_ += n;
        }

        void fail()
        {
            state_ = 2;
        }

    protected:
        void save_binary(char const * data, std::size_t size)
        {
            if (out_avail() >= size) {
                memcpy(pptr_, data, size);
                pptr_ += size;
            } else
                state_ = 1;
        }

    private:
        /// 获取派生类的指针
        Stream * This()
        {
            return static_cast<Stream *>(this);
        }

    protected:
        char * buf_;
        char * pptr_;
	char * last_ptr_;	//用于写入向量数据时，记录上一个记录的位置，如果下一个记录写入失败，则回退到上一个
		
        char * epptr_;
        int state_;
    };


} // namespace utils

#endif // BASIC_OSTREAM_H
