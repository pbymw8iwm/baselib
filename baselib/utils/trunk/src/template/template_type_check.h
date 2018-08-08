/// @file template_type_check.h

#ifndef TEMPLATE_TYPE_CHECK_H
#define TEMPLATE_TYPE_CHECK_H

#include "template_logic.h"

#define MAKE_CHECK_TEMPLATE(checker_name, default_value) \
template <typename T> \
struct checker_name \
{ \
    static const bool value = (default_value); \
};

#define MAKE_CHECK_TEMPLATE_SPECIAL(checker_name, special_type, special_value) \
template <> \
struct checker_name<special_type> \
{ \
    static const bool value = (special_value); \
};

namespace utils
{
    // is_void
    MAKE_CHECK_TEMPLATE(is_void, false)
    MAKE_CHECK_TEMPLATE_SPECIAL(is_void, void, true)

    // integral
    MAKE_CHECK_TEMPLATE(is_integral, false)
    MAKE_CHECK_TEMPLATE_SPECIAL(is_integral, unsigned char, true)
    MAKE_CHECK_TEMPLATE_SPECIAL(is_integral, unsigned short, true)
    MAKE_CHECK_TEMPLATE_SPECIAL(is_integral, unsigned int, true)
    MAKE_CHECK_TEMPLATE_SPECIAL(is_integral, unsigned long, true)
    MAKE_CHECK_TEMPLATE_SPECIAL(is_integral, unsigned long long, true)
    MAKE_CHECK_TEMPLATE_SPECIAL(is_integral, signed char, true)
    MAKE_CHECK_TEMPLATE_SPECIAL(is_integral, signed short, true)
    MAKE_CHECK_TEMPLATE_SPECIAL(is_integral, signed int, true)
    MAKE_CHECK_TEMPLATE_SPECIAL(is_integral, signed long, true)
    MAKE_CHECK_TEMPLATE_SPECIAL(is_integral, signed long long, true)
    MAKE_CHECK_TEMPLATE_SPECIAL(is_integral, bool, true)
    MAKE_CHECK_TEMPLATE_SPECIAL(is_integral, char, true)

    // float
    MAKE_CHECK_TEMPLATE(is_float, false)
    MAKE_CHECK_TEMPLATE_SPECIAL(is_float, float, true)
    MAKE_CHECK_TEMPLATE_SPECIAL(is_float, double, true)
    MAKE_CHECK_TEMPLATE_SPECIAL(is_float, long double, true)

    template <typename T> 
    struct is_arithmetic
        : or_<is_integral<T>, is_float<T> >
    {
    };

    template <typename T> 
    struct is_fundamental
        : or_<is_arithmetic<T>, is_void<T> >
    {
    };

    template<class T1, class T2>
    struct is_type
        : false_value
    {
    };

    template<class T1>
    struct is_type<T1, T1>
        : true_value
    {
    };

    typedef char yes_type;
    struct no_type
    {
        char padding[8];
    };

    template <typename T>
    struct remove_const
    {
    };

    template <typename T>
    struct remove_const<T const>
    {
        typedef T type;
    };

    //template <typename T>
    //struct remove_cv
    //{
    //};

    //template <>
    //struct remove_cv
    //{
    //};

    //// is_class
    //template <class U>
    //yes_type is_class_tester(void(U::*)(void));
    //template <class U>
    //no_type is_class_tester(...);

    //template <typename T>
    //struct is_class
    //{
    //    static const bool value = 
    //        (bool)and_c<
    //            sizeof(is_class_tester<T>(0)) == sizeof(yes_type),
    //            not_<is_union<T> >::value
    //        >::value
    //};

}

#endif // TEMPLATE_TYPE_CHECK_H
