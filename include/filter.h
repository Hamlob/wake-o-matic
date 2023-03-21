#pragma once

//Filter class that implements exponential moving average on input
class Filter{
public:

	//sets the multiplier for exponential moving average
	void setAlpha(float value);

	//takes the most recent input and returns the filtered value
	int doFilter(int input);

private:
	float accumulator;
	float alpha = 0.5;
	bool init = 1; 	//flag saying that the filter was not used before

};

