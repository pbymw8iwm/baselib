/// @file stream_types.h

#ifndef SERIALIZATION_STREAM_TYPES_H
#define SERIALIZATION_STREAM_TYPES_H

#include "serialization/serialization.h"
#include "serialization/nvp.h"
#include "stream/qstr.h"
#include "stream/mark.h"
#include "stream/batch_sequence.h"

#include <string>

namespace utils
{
    namespace serialization
    {

        extern qstr_buffer global_qstr_buffer;

        // qstr
        template <typename Archive>
        void save(
            Archive & ar, 
            utils::qstr const & t)
        {
            ar << t.str();
        }

        template <typename Archive>
        void load(
            Archive & ar, 
            utils::qstr & t)
        {
            std::string str;
            ar >> str;
            t = global_qstr_buffer.put(str);
        }

        template <typename Archive>
        void serialize(
            Archive & ar, 
            utils::qstr & t)
        {
            split_free(ar, t);
        }

        template <>
        struct is_sigle_unit<qstr>
            : true_value
        {
        };

        // mark
        template <typename Archive, typename T>
        void serialize(
            Archive & ar, 
            utils::mark<T> & t)
        {
            if (NULL == t.ptr()) {
                ar & t.data();
                t.ptr((char *)1);
            }
        }

        template <typename T>
        struct is_sigle_unit<mark<T> >
            : true_value
        {
        };

        // batch_sequence
        template <typename Archive, typename Sequence>
        void serialize(
            Archive & ar, 
            utils::batch_sequence<Sequence> & t)
        {
            std::size_t count = t.remain();
            ar & SERIALIZATION_NVP(count);
            if (!ar)
                return;
            t.reserve(count);
            while (count-- > 0) {
                ar & make_nvp("item", t.current());
                if (ar)
                    t.next();
                else
                    break;
            }
        }


    } // namespace serialization

} // namespace utils

#endif // SERIALIZATION_STREAM_TYPES_H
