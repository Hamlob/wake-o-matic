#include "filter.h"
#include <math.h>

void Filter::setAlpha(float value) {
	alpha = value;
}

int Filter::doFilter(int input) {
	accumulator = input * alpha + accumulator * (1 - alpha);
	return roundf(accumulator);
}
