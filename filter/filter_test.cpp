//test program for filter class
//generates a data representing a random variation in a value, similarly to the variation of the coordinates of eye detection
// inputs the data into filter

#include "filter.h"
#include <random>


//global vars for data generation
float randomWeight = 0.3;			// decides how much is the random contribution to the dcValue (x100%)
int dcValue = 1500;
float randomScaler = (randomWeight * dcValue) / RAND_MAX;
int data[100];

//global vars for filtering
float alpha = 0.1;				//multiplier for the moving average
int filteredData[100];

int main() {

	int value = dcValue;
	int randValue;

	Filter filter1;
	filter1.setAlpha(alpha);

	printf("raw   |  filtered \n");

	for (int i = 0; i < 100; i++) {
		// generating and saving the dummy data
		randValue = (rand() - RAND_MAX / 2) * randomScaler; //shifts the range so that it goes from -RAND_MAX/2 to RAND_MAX/2, then normalizes by RAND_MAX. Finally scales depending on our dcValue and weighting assigned.
		value += roundf(randValue);
		data[i] = value;

		//filtering the data and saving it
		filteredData[i] = filter1.doFilter(value);

		printf("%d;   ", data[i]);
		printf("%d\n", filteredData[i]);
	}


	return 0;
}
