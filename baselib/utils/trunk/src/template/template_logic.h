/// @file template_logic.h

#ifndef TEMPLATE_LOGIC_H
#define TEMPLATE_LOGIC_H

namespace utils
{

    // type stand for true 
    struct true_type
    {
    };

    // type stand for false 
    struct false_type
    {
    };

    // if
    template <bool c, typename T1, typename T2>
    struct if_c
    {
        typedef T1 type;
    };

    template <typename T1, typename T2>
    struct if_c<false, T1, T2>
    {
        typedef T2 type;
    };

    template <typename Container, typename T1, typename T2>
    struct if_
    {
        typedef typename if_c<(bool)Container::value, T1, T2>::type type;
    };

    // type with value equal to true 
    struct true_value
    {
        static const bool value = true;
    };

    // type with value equal to false 
    struct false_value
    {
        static const bool value = false;
    };

    // or
    template <bool b1, bool b2, bool b3 = false, bool b4 = false>
    struct or_c;

    template <bool b1, bool b2, bool b3, bool b4>
    struct or_c
    {
        static const bool value = true;
    };

    template <>
    struct or_c<false, false, false, false>
    {
        static const bool value = false;
    };

    template <typename B1, typename B2, typename B3 = false_value, typename B4 = false_value>
    struct or_
    {
        static const bool value = (bool)or_c<(bool)B1::value, (bool)B2::value, (bool)B3::value, (bool)B4::value>::value;
    };

    // and
    template <bool b1, bool b2, bool b3 = true, bool b4 = true>
    struct and_c;

    template <bool b1, bool b2, bool b3, bool b4>
    struct and_c
    {
        static const bool value = false;
    };

    template <>
    struct and_c<true, true, true, true>
    {
        static const bool value = true;
    };

    template <typename B1, typename B2, typename B3 = true_value, typename B4 = true_value>
    struct and_
    {
        static const bool value = (bool)and_c<(bool)B1::value, (bool)B2::value, (bool)B3::value, (bool)B4::value>::value;
    };

    // not
    template <bool b>
    struct not_c;

    template <bool b>
    struct not_c
    {
        static const bool value = false;
    };

    template <>
    struct not_c<false>
    {
        static const bool value = true;
    };

    template <typename B>
    struct not_
    {
        static const bool value = (bool)not_c<(bool)B::value>::value;
    };


    template <bool b>
    struct assert_;

    template <>
    struct assert_<true>
    {
    };

    template <int n>
    struct assert_test {};

#define STATIC_ASSERT(B) typedef assert_test<sizeof(assert_<(bool)B::value>)> assert_test_type;

}

#endif //TEMPLATE_LOGIC_H
