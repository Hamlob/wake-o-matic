//test program for filter class
//generates a data representing a random variation in a value, similarly to the variation of the coordinates of eye detection
// inputs the data into filter

#include "include/filter.h"
#include <random>


//global vars for data generation
float randomWeight = 0.3;			// decides how much is the random contribution to the dcValue (x100%)
int dcValue = 1500;
float randomScaler = (randomWeight * dcValue) / RAND_MAX;
int data[100];
int sumData = 0;
double cumDevData = 0; 	//cummulative deviation of raw data


//global vars for filtering
float alpha = 0.1;				//multiplier for the moving average
int filteredData[100];
int sumFilteredData = 0;
double cumDevFilteredData = 0; // cummulative deviation of filtered data

int main() {

	int value = dcValue;
	int randValue;

	Filter filter1;
	filter1.setAlpha(alpha);

	for (int i = 0; i < 100; i++) {
		// generating and saving the dummy data
		randValue = (rand() - RAND_MAX / 2) * randomScaler; //shifts the range so that it goes from -RAND_MAX/2 to RAND_MAX/2, then normalizes by RAND_MAX. Finally scales depending on our dcValue and weighting assigned.
		value += roundf(randValue);
		data[i] = value;

		//filtering the data and saving it
		filteredData[i] = filter1.doFilter(value); 

		sumData += data[i];
		sumFilteredData += filteredData[i];

		// printf("%d;   ", data[i]);
		// printf("%d\n", filteredData[i]);
	}

	for (int i = 0; i < 100; i++){
		cumDevData += abs(data[i] - sumData/100.0);
		cumDevFilteredData += abs(filteredData[i] - sumFilteredData/100.0);
	}
	
	//check cummulative deviations
	//printf("%f,%f", cumDevData, cumDevFilteredData);

	//in the worst case the filter should have the same cummulative deviation compared to raw data, for example if raw data is DC value. 
	//in other cases it should have lower cummulative deviation.
	if (cumDevData < cumDevFilteredData){
		printf("The filter does not work properly");
	}

	printf("Filter works properly");


	return 0;
}