/// @file binary_stream.h

#ifndef BINARY_STREAM_H
#define BINARY_STREAM_H

#include "stream/basic_istream.h"

namespace utils
{

    class binary_istream
        : public basic_istream<binary_istream>
    {
        typedef basic_istream<binary_istream> super;
        friend class basic_istream<binary_istream>;

    public:
        binary_istream(char * buf, std::size_t size)
            : super(buf, size)
        {
        }

        template<class T>
        void load(T & t)
        {
            super::load_binary((char *)&t, sizeof(T));
        }

    };

    template<class T>
    void rewind_load(T const & t)
    {
        load(t);
    }

} // namespace utils

#endif // BINARY_STREAM_H
