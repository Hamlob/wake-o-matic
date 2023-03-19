#include "../include/filter.h"
#include <math.h>

void Filter::setAlpha(float value) {
	alpha = value;
}

int Filter::doFilter(int input) {
	if(init){
		accumulator = input;
		init = 0;
		return accumulator;
	}
	accumulator = input * alpha + accumulator * (1 - alpha);
	return roundf(accumulator);
}