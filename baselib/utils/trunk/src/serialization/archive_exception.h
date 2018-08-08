/// @file archive_exception

#ifndef ARCHIVE_EXCEPTION_H
#define ARCHIVE_EXCEPTION_H

#include <exception>
#include <cassert>

namespace utils
{

    namespace serialization
    {

        /// ���л��쳣��
        class archive_exception
            : public std::exception
        {
        public:
            typedef enum
            {
                incompatible_native_format, ///< ��ʽ����
                stream_error, ///< ����/���������
            } exception_code;

            exception_code code;

            archive_exception(exception_code c)
                : code(c)
            {
            }

            /// ��ȡ����������Ϣ
            virtual const char *what( ) const throw( )
            {
                const char *msg = "programming error";
                switch(code)
                {
                case incompatible_native_format:
                    msg = "incompatible native format";
                    break;
                case stream_error:
                    msg = "stream error";
                    break;
                default:
                    assert(false);
                    break;
                }
                return msg;
            }
        };

    } // namespace archive

}// namespace utils

#endif //ARCHIVE_EXCEPTION_H
