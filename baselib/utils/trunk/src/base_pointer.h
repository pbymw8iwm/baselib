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
        һ����¼��Ի���ַ�ľ�̬��

        �������û���ַʱ����Ƿ��Ѿ���ʹ�ã���ֹʹ�Ѿ�ʵ������base_pointerʧЧ
     */
    struct base_address
    {
        /// �������û���ַ
        static void set_address(void * p)
        {
            // ��鱻ʹ�ñ�־����release��������
            assert(__used == 0);
            __p = (intptr_t)p;
        }

        /// ��ȡ����ַ
        static intptr_t get_address()
        {
            // ���ñ�ʹ�ñ�־����release��������
            assert(__used = 1);
            return __p ;
        }

    private:
        static intptr_t __p; //< ����ַ
        static int __used; /// ��¼�Ƿ��Ѿ���ʹ��
    };

    /**
        ���ָ���࣬�Ƕ�__based�ؼ��ֵ�һ��ʵ�֣��ǿ���̵Ĺ���ȫָ�롣
        
        �ڲ���¼�����ַ�����ƫ�ƣ�ֻҪ��ȷ���û���ַbase_address���Ϳ����ڹ����ڴ��а�ȫʹ��ָ�롣
     */
    template <typename Type>
    struct base_pointer
    {
        /// �չ���
        base_pointer(){}

        /// ����ָͨ�빹��
        base_pointer(Type * p)
            : p_((intptr_t)p - base_address::get_address())
        {
        }

        /// ͨ����ָͨ�븳ֵ
        base_pointer & operator = (Type * p)
        {
            p_ = (intptr_t)p - base_address::get_address();
            return *this;
        }

        /// ������ͨ��ʽ��ָ��
        Type * operator -> ()
        {
            return (Type *)(*this);
        }

        /// ת��Ϊ��ͨ��ʽ��ָ��
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
        intptr_t p_; //< �����ַ�����ƫ��
    };

    /// ��������Type��ָ�����ͣ�ʹ�����ָ��
    struct pointer_base
    {
        template <typename Type>
        struct apply
        {
            typedef base_pointer<Type> type;
        };
    };

    /// ��������Type��ָ�����ͣ�ʹ����ָͨ��
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

