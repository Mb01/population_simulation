/*
 * statistics_helpers.cpp
 *
 *  Created on: Jan 7, 2014
 *      Author: mark
 */

#include "statistics_helpers.h"
#include "stdlib.h"

//Check to see that srand is called with some variable seed if you want different results each time.
//Calling it with the same value can aid debugging because it should result in the same
//numbers being generated.

// helper to get a random integer min inclusive max exclusive
float rand_int(int min, int max){
	float r =  rand() % (max - min) + min;
		return r;
}

//get a random number between 0 and 1
float rand_zero_one(){
	float r = static_cast <float> (rand()) / static_cast <float> (RAND_MAX);
	return r;
}
