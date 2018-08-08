/// @file vector.h

#ifndef SERIALIZATION_VECTOR_H
#define SERIALIZATION_VECTOR_H

#include "serialization/serialization.h"
#include "serialization/collection.h"
#include "serialization/array.h"

#include <vector>

namespace utils
{
    namespace serialization
    {

        // the default versions

        template<class Archive, class T, class Allocator>
        inline void save(
            Archive & ar,
            const std::vector<T, Allocator> & t,
            false_type)
        {
            save_collection<Archive, std::vector<T, Allocator> >(ar, t);
        }

        template<class Archive, class T, class Allocator>
        inline void load(
            Archive & ar,
            std::vector<T, Allocator> &t,
            false_type)
        {
            load_collection<Archive, std::vector<T, Allocator> >(ar, t);
        }

        // the optimized versions

        template<class Archive, class T, class Allocator>
        inline void save(
            Archive & ar,
            const std::vector<T, Allocator> & t,
            true_type)
        {
            std::size_t const count(t.size());
            ar << SERIALIZATION_NVP(count);
            if (!t.empty())
                ar << make_array(&t[0], t.size());
        }

        template<class Archive, class T, class Allocator>
        inline void load(
            Archive & ar,
            std::vector<T, Allocator> &t,
            true_type)
        {
            std::size_t count(t.size());
            ar >> SERIALIZATION_NVP(count);
            t.resize(count);
            if (!t.empty())
                ar >> make_array(&t[0], t.size());
        }

        // dispatch to either default or optimized versions

        template<class Archive, class T, class Allocator>
        inline void save(
            Archive & ar,
            std::vector<T, Allocator> const & t)
        {
            typedef typename if_c<(bool)use_array_optimization<Archive, T>::value, true_type, false_type>::type use_optimized;
            save(ar, t, use_optimized());
        }

        template<class Archive, class T, class Allocator>
        inline void load(
            Archive & ar,
            std::vector<T, Allocator> & t)
        {
            typedef typename if_c<(bool)use_array_optimization<Archive, T>::value, true_type, false_type>::type use_optimized;
            load(ar, t, use_optimized());
        }

        // split non-intrusive serialization function member into separate
        // non intrusive save/load member functions
        template<class Archive, class T, class Allocator>
        inline void serialize(
            Archive & ar,
            std::vector<T, Allocator> & t)
        {
            split_free(ar, t);
        }

    } // namespace serialization

} // namespace utils

#endif // SERIALIZATION_VECTOR_H
