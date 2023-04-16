#include "logging.h"

#ifdef USE_LOGGING
namespace logging = boost::log;
namespace keywords = boost::log::keywords;
#endif

void Logger::logMessage(Logger::custom_severity_level severity, const char* msg){
    #ifdef USE_LOGGING
    BOOST_LOG_TRIVIAL(severity) << msg;
    #else
    std::cout << msg << std::endl;
    #endif
}