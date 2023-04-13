#pragma once

#include <stdlib.h>
#include <thread>
#include <iostream>
#include <chrono>
#include <fstream>
#include "logging.h"

/// @brief Action class used to calculate and incur an audio output
class Action {
    public:
        /// @brief default constructor for action object
        Action() = default;

        /**
         * @brief Create a looping thread to listen to the sleeping and warning flags. 
         * This thread automatically completes the appropriate action if either
         * setSleepingFlag(bool) or setWarningFlag(bool) are called.
         * @see deactivate()
         */
        void activate();

        /**
         * @brief Close the looping thread called by activate().
         * @see activate()
         */
        void deactivate();
        
        /**
         * @brief Set the SleepTimeBetweenActions ms object
         * 
         * @param newTime_ms 
         */
        void setSleepTimeBetweenActions_ms(long newTime_ms);

        /**
         * @brief Set the value of the Sleeping flag
         * 
         * @param newVal The new value of the sleeping flag
         */
        void setSleepingFlag(bool newVal);

        /**
         * @brief Set the value of the Warning flag
         * 
         * @param newVal The new value of the warning flag
         */
        void setWarningFlag(bool newVal);

        /**
         * @brief Get the Sleeping flag value
         * 
         * @return Sleeping flag value
         */
        bool getSleepingFlag(){
            return sleepingFlag;
        };

        /**
         * @brief Get the Warning Flag value
         * 
         * @return Warning flag value
         */
        bool getWarningFlag(){
            return warningFlag;
        };

        /// @brief Result code used for reporting the output after a state change
        enum ActionResult { error, none, warning, alarm };

    private:
        /// @brief Unmute device and play the alarm sound
        void outputAlarm();

        /// @brief Unmute device and play the warning sound
        void outputWarning();

        /// @brief Function that the action thread runs, includes a while loop that is cancelled by calling deactivate().
        void threadLoop();

        /**
         * @brief Function called when a flag change is detected
         * Determines the type of output to 
         * 
         * @return ActionResult Result code of the action. 0 = no action
         */
        ActionResult completeAction();

        /// @brief Handle for the thread spawned by activate()
        std::thread actionThread;

        std::chrono::duration<double, std::milli> sleepTimeBetweenActions_ms = std::chrono::milliseconds(8000);

        // Internal flags

        bool warningFlag = false;
        bool sleepingFlag = false;
        
        bool flagChanged = false;
        bool deviceActive = false;
};