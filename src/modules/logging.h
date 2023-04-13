#pragma once

#include <stdlib.h>
#include <thread>
#include <iostream>
#include <fstream>
#include <string>
#include <ctime>

using namespace std;

/// @brief Logging class used to keep a record of what has happened
class Logging{
    public:
        Logging() = default; 

        void start_log();

        void write_to_log();

        void stop_log();

        void setloggingFlag(bool newVal);

        void getLoggingFlag(){
            return loggingFlag;
        }

    private:

        // Internal flags
        bool loggingFlag = false;

        bool flagChanged = false;
        bool deviceActive = false;
};