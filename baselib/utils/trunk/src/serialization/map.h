/// @file map.h

#ifndef SERIALIZATION_MAP_H
#define SERIALIZATION_MAP_H

#include "serialization/serialization.h"
#include "serialization/collection.h"
#include "serialization/utility.h"

#include <map>

namespace utils
{
    namespace serialization
    {

        template<class Archive, class _Kty, class _Ty, class _Pr, class _Alloc>
        inline void save(
            Archive & ar,
            std::map<_Kty, _Ty, _Pr, _Alloc> const & t)
        {
            save_collection<Archive, std::map<_Kty, _Ty, _Pr, _Alloc> >(ar, t);
        }

        template<class Archive, class _Kty, class _Ty, class _Pr, class _Alloc>
        inline void load(
            Archive & ar,
            std::map<_Kty, _Ty, _Pr, _Alloc> & t)
        {
            load_collection<Archive, std::map<_Kty, _Ty, _Pr, _Alloc> >(ar, t);
        }

        // split non-intrusive serialization function member into separate
        // non intrusive save/load member functions
        template<class Archive, class _Kty, class _Ty, class _Pr, class _Alloc>
        inline void serialize(
            Archive & ar,
            std::map<_Kty, _Ty, _Pr, _Alloc> & t)
        {
            split_free(ar, t);
        }

    } // namespace serialization

} // namespace utils

#endif // SERIALIZATION_MAP_H
