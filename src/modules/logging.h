#include <boost/log/core.hpp>
#include <boost/log/trivial.hpp>
#include <boost/log/expressions.hpp>
#include <boost/log/utility/setup/file.hpp>
#include <boost/log/utility/setup/common_attributes.hpp>

/**
 * @brief Initialise log file using Boost
 * Configured to write to log file "logger.log" in build directory
 * See https://www.boost.org/ for more information on Boost
 *
 * \section Usage:
 * @example BOOST_LOG_TRIVIAL(trace) << "This is a trace severity message"
 * severity levels include: trace, debug, info, warning, error, fatal.
 */
void init_logging();