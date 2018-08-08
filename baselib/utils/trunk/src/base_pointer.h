/// @file base_pointer.h

#ifndef BASE_POINTER_H
#define BASE_POINTER_H

#include <cstddef>
#ifdef WIN32
#include <crtdefs.h>
#else
#include <stdint.h>
#endif

#include <assert.h>

namespace utils {

    /**
        一个记录相对基地址的静态类

        重新设置基地址时检查是否已经被使用，防止使已经实例化的base_pointer失效
     */
    struct base_address
    {
        /// 重新设置基地址
        static void set_address(void * p)
        {
            // 检查被使用标志，在release版中跳过
            assert(__used == 0);
            __p = (intptr_t)p;
        }

        /// 获取基地址
        static intptr_t get_address()
        {
            // 设置被使用标志，在release版中跳过
            assert(__used = 1);
            return __p ;
        }

    private:
        static intptr_t __p; //< 基地址
        static int __used; /// 记录是否已经被使用
    };

    /**
        相对指针类，是对__based关键字的一种实现，是跨进程的共享安全指针。
        
        内部记录与基地址的相对偏移，只要正确设置基地址base_address，就可以在共享内存中安全使用指针。
     */
    template <typename Type>
    struct base_pointer
    {
        /// 空构造
        base_pointer(){}

        /// 从普通指针构造
        base_pointer(Type * p)
            : p_((intptr_t)p - base_address::get_address())
        {
        }

        /// 通过普通指针赋值
        base_pointer & operator = (Type * p)
        {
            p_ = (intptr_t)p - base_address::get_address();
            return *this;
        }

        /// 析出普通形式的指针
        Type * operator -> ()
        {
            return (Type *)(*this);
        }

        /// 转换为普通形式的指针
        operator Type * ()
        {
            return reinterpret_cast<Type *>(p_ + base_address::get_address());
        }

        friend bool operator == (const base_pointer & l, const base_pointer & r)
        {
            return l.p_ == r.p_;
        }

        friend bool operator != (const base_pointer & l, const base_pointer & r)
        {
            return l.p_ != r.p_;
        }

    private:
        intptr_t p_; //< 与基地址的相对偏移
    };

    /// 定义类型Type的指针类型，使用相对指针
    struct pointer_base
    {
        template <typename Type>
        struct apply
        {
            typedef base_pointer<Type> type;
        };
    };

    /// 定义类型Type的指针类型，使用普通指针
    struct pointer_raw
    {
        template <typename Type>
        struct apply
        {
            typedef Type * type;
        };
    };

} // namespace utils

#endif //  BASE_POINTER_H

