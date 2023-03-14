#include "filter.h"
#include <math.h>

void Filter::setAlpha(float value) {
	alpha = value;
}

int Filter::doFilter(int input) {
	return roundf(input * alpha + accumulator * (1 - alpha));
}