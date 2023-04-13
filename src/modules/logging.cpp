#include "logging.h"

void Logging::threadLoop(){
    while(deviceActive){
        if(flagChanged == true){
            //Log flagChanged
            //log face detection, eye detect and/or action
            flagChanged = false;
        }
    }
}

Logging::start_log(){
    
}

Logging::write_to_log(flag){
    std::ofstream logfile("log.txt", std::ios::app);
    if (!logfile.is_open()) {
        std::cerr << "Error: Failed to open log file!" << std::endl;
        return 1;
    }

    // Get the current time
    std::time_t now = std::time(nullptr);
    std::tm* tm = std::localtime(&now);

    // Write the log message to the file
    std::string message = "Data_to_be_logged";
    logfile << tm->tm_year + 1900 << '-' << tm->tm_mon + 1 << '-' << tm->tm_mday << ' ' << tm->tm_hour << ':' << tm->tm_min << ':' << tm->tm_sec << " - " << message << std::endl;

    // Close the file
    logfile.close();
}