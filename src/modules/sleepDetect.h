#pragma once
#include <vector>

#define SLEEPING 0
#define AWAKE 1
#define NOFACE -1


/** @brief Class that takes history of eyeStatus values and decides whether the person is awake, sleeping or not detected.
 * Currently, its only looking at the most prevalent value in the buffer holding the history.  
 * 
 * ### USAGE:
 * Firstly, load the eye status values one by one using @see load(), then call @see detect(), which returns status of the driver.
 * 	
*/
class SleepDetect
{
public:
	/** @brief Returns the size of the buffer holding eye status history.
	 * 
	 * @return number of eye status values currently stored in the class.
	 */
	int bufferSize();

	/**
	 * @brief Loads a value of eye status into the buffer.
	 * 
	 * @param val An eye status value: 1 for eyes open, 0 for eyes closed, -1 for no face
	 */
	void load(int val);

	/**
	 * @brief Processes the buffer to decide whether the driver is asleep, awake or not detected.
	 * Currently, the algorithm decides only according to the most frequent value in the buffer.
	 * @return int; 1 for awake, 0 for asleep, -1 for not detected.
	 */
	int detect();
	
	SleepDetect() = default;

private:
	std::vector<int> buffer;

};

