#pragma once
#include <vector>

#define SLEEPING 0
#define AWAKE 1
#define NOFACE -1

class SleepDetect
{
public:

	int bufferSize();

	void load(int val);

	int detect();
	
	SleepDetect() = default;

private:
	std::vector<int> buffer;

};

