#pragma once

#ifdef USE_LOGGING
#include <boost/log/core.hpp>
#include <boost/log/trivial.hpp>
#include <boost/log/expressions.hpp>
#include <boost/log/utility/setup/file.hpp>
#include <boost/log/utility/setup/common_attributes.hpp>
#endif
#include <string>
#include <iostream>

/**
 * @brief Class to handle log file using Boost
 * When setting up cmake, set custom flag `-DSAVE_LOG`:
 *      cmake .. -DSAVE_LOG=true
 * 
 * If this flag is not set, Logger will not use boost and will print any log messages.
 * 
 * If flag set:
 * Configured to write to log file "logger.log" in build directory.
 * 
 * See https://www.boost.org/ for more information on Boost
 * 
<<<<<<< HEAD
 * ### USAGE:
=======
 * ### Usage
>>>>>>> origin/capture_and_detect
 *      Logger myLogger;
 *      myLogger.logMessage(SEVERITY, MSG)
 * 
 * `SEVERITY` levels include: `trace`, `debug`, `info`, `warning`, `error`, `fatal`.
 */
class Logger{
    public:
        Logger(){
            #ifdef USE_LOGGING
            BOOST_LOG_ATTRIBUTE_KEYWORD(severity, "Severity", custom_severity_level); // link enum to boost severity_level
            
            logging::add_file_log
            (
                keywords::file_name = "logger.log",
                keywords::format = "[%TimeStamp%] [%ThreadID%] [%Severity%] %Message%"
            );

            logging::core::get()->set_filter
            (
                logging::trivial::severity >= logging::trivial::info
            );

            logging::add_common_attributes();
            #endif
        }

        /// @brief Custom enum that corresponds to boost severity levels. Can also be used without using boost
        enum custom_severity_level{
            info,
            error,
            warning
        };

        /**
         * @brief Write a message to log file if USE_LOGGING flag is enabled.
         * Prints message to console if logging disabled
         * 
         * @param severity Logger::custom_severity_level
         * @param msg 
         */
        static void logMessage(custom_severity_level severity, const char* msg);
};
