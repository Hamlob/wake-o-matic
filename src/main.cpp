#include <iostream>
#include "modules/logging.h"

int main()
{
    init_logging();
    BOOST_LOG_TRIVIAL(info) << "Logging Started";

    std::cout << "Hello, World!" << std::endl; //"hello world" test line - remove when adding real code
    return 0;
}