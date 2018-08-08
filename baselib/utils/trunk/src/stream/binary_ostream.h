/// @file binary_ostream.h

#ifndef BINARY_OSTREAM_H
#define BINARY_OSTREAM_H

#include "stream/basic_ostream.h"

namespace utils
{

    class binary_ostream
        : public basic_ostream<binary_ostream>
    {
        typedef basic_ostream<binary_ostream> super;
        friend class basic_ostream<binary_ostream>;

    public:
        binary_ostream(char * buf, std::size_t size)
            : super(buf, size)
        {
        }

        template<class T>
        void save(T const & t)
        {
            super::save_binary((char const *)&t, sizeof(T));
        }

    };

    template<class T>
    void rewind_save(T const & t)
    {
        save(t);
    }

} // namespace utils

#endif // BINARY_OSTREAM_H
