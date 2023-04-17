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
 * @brief Initialise log file using Boost
 * Configured to write to log file "logger.log" in build directory.
 * 
 * See https://www.boost.org/ for more information on Boost
 * 
 * ### Usage
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

        static void logMessage(custom_severity_level severity, const char* msg);
};
