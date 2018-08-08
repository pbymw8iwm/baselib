/// @file string.h

#ifndef SERIALIZATION_STRING_H
#define SERIALIZATION_STRING_H

#include "serialization/serialization.h"

#include <string>

namespace utils
{
    namespace serialization
    {

        template <>
        struct is_primitive_type<std::string>
        {
            static const bool value = true;
        };

    } // namespace serialization

} // namespace utils

#endif // SERIALIZATION_STRING_H
