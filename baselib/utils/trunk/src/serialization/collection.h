/// @file collection.h

#ifndef SERIALIZATION_COLLECTION_H
#define SERIALIZATION_COLLECTION_H

#include "serialization/serialization.h"
#include "serialization/nvp.h"

namespace utils
{
    namespace serialization
    {

        template<class Archive, class Container>
        inline void save_collection(
            Archive & ar, 
            Container const & s)
        {
            std::size_t const count(s.size());
            ar <<  SERIALIZATION_NVP(count);
            typename Container::const_iterator it = s.begin();
            std::size_t c = count;
            while(c-- > 0){
                ar << make_nvp("item", *it++);
            }
        }

        template<class Archive, class Container>
        inline void load_collection(
            Archive & ar, 
            Container & s)
        {
            s.clear();
            std::size_t count;
            ar >>  SERIALIZATION_NVP(count);
            std::size_t c = count;
            while(c-- > 0){
                typename Container::value_type v;
                ar >> make_nvp("item", v);
                s.insert(s.end(), v);
            }
        }

    } // namespace serialization

} // namespace utils

#endif // SERIALIZATION_COLLECTION_H
