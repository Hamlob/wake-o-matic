#include <boost/log/core.hpp>
#include <boost/log/trivial.hpp>
#include <boost/log/expressions.hpp>
#include <boost/log/utility/setup/file.hpp>
#include <boost/log/utility/setup/common_attributes.hpp>
#include <string>

/**
 * @brief Initialise log file using Boost
 * Configured to write to log file "logger.log" in build directory.
 * 
 * See https://www.boost.org/ for more information on Boost
 * 
 * ### Usage
 * 
 *      BOOST_LOG_TRIVIAL(SEVERITY) << "This is a log message"
 * 
 * SEVERITY levels include: `trace`, `debug`, `info`, `warning`, `error`, `fatal`.
 */
void init_logging();

void logMessage(severity_level severity, const char* msg);