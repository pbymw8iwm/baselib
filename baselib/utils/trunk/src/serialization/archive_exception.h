/// @file archive_exception

#ifndef ARCHIVE_EXCEPTION_H
#define ARCHIVE_EXCEPTION_H

#include <exception>
#include <cassert>

namespace utils
{

    namespace serialization
    {

        /// 序列化异常类
        class archive_exception
            : public std::exception
        {
        public:
            typedef enum
            {
                incompatible_native_format, ///< 格式不对
                stream_error, ///< 输入/输出流错误
            } exception_code;

            exception_code code;

            archive_exception(exception_code c)
                : code(c)
            {
            }

            /// 获取错误描述信息
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
