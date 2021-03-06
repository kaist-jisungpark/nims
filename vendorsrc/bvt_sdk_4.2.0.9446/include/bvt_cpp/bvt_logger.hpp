/*
    This file has been generated by bvtidl.pl. DO NOT MODIFY!
*/

#ifndef __CPP_BVTLOGGER_HPP__
#define __CPP_BVTLOGGER_HPP__

#include "bvt_loglevel.hpp"
#include <string>
#ifdef _WIN32
#   include <memory>
#else
#   include <cstddef>
#   if defined (__GLIBCXX__) && __cplusplus <= 199711L
#      include <tr1/memory>
       namespace std {
          using std::tr1::shared_ptr;
       }
#   else
#       include <memory>
#   endif
#endif
#include <bvt_cpp/bvt_retval.hpp>
#include <bvt_cpp/bvt_error.hpp>

namespace BVTSDK
{

    /// <summary>
    /// The SDK is capable of producing a significant amount of debugging 
    /// output.  The Logger object exists to allow the user to control 
    /// (or disable) the output.  Users can also use Logger to add their
    /// own custom log messages.
    /// <summary>
    class Logger
    {
    public:
    public:
        //
        // Set the log threshold level.  Events above level
        // will be logged to the target.
        //
        // @param level Log level       
        static void SetLevel(enum LogLevel::Enum level)
        {
            BVTLogger_SetLevel(((int) level));
        }

        //
        // The log target can be a filename, "stdout", "stderr", or "null".
        // If null is specified, log output is disabled.
        //
        // @param target File/device to log output to       
        static void SetTarget(const std::string & target)
        {
            int error_code = BVTLogger_SetTarget(target.c_str());
            if (0 != error_code)
                throw SdkException(error_code);
        }

        //
        // Write a message to the log.
        //
        // @param level The log level of the message 
        // @param message A string to log       
        static void Write(enum LogLevel::Enum level, const std::string & message)
        {
            BVTLogger_Write(((int) level), message.c_str());
        }

    };

}

#endif
