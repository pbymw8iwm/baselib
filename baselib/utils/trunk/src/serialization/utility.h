/// @file utility.h

#ifndef SERIALIZATION_UTILITY_H
#define SERIALIZATION_UTILITY_H

#include "serialization/serialization.h"
#include "template/template_type_check.h"

#include <utility>

namespace utils
{
    namespace serialization
    {

        // pair
        template<class Archive, class _Ty1, class _Ty2>
        inline void serialize(
            Archive & ar,
            std::pair<_Ty1, _Ty2> & p)
        {
                typedef typename remove_const<_Ty1>::type typef;
                ar & make_nvp("first", const_cast<typef &>(p.first));
                ar & make_nvp("second", p.second);
        }

    } // namespace serialization

} // namespace utils

#endif // SERIALIZATION_UTILITY_H
