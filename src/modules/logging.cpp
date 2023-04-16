#include "logging.h"

namespace logging = boost::log;
namespace keywords = boost::log::keywords;

void init_logging()
{
    logging::register_simple_formatter_factory<logging::trivial::severity_level, char>("Severity");

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
}

void logMessage(severity_level severity, const char* msg){
    BOOST_LOG_TRIVIAL(severity) << "Alarm Error";
}