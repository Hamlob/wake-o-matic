#pragma once

//Filter class that implements exponential moving average on input
class Filter{
public:

	/**
	 * @brief Sets alpha, the multiplier for exponential moving average
	 * 
	 * @param value a float that specifies the multiplier
	 */
	void setAlpha(float value);

	/**
	 * @brief Takes the most recent input and returns the filtered value
	 * 
	 * @param input Most recent eye state
	 * @return int filtered value
	 */
	int doFilter(int input);

private:
	float accumulator = 0;
	float alpha = 0.5;

};

