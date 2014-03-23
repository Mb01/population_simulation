
#include "stdlib.h"
#include "ourstatistics.h"


float rand_zero_one(){
	float r = static_cast <float> (rand()) / static_cast <float> (RAND_MAX);
	return r;
}

float rand_int(int min, int max){
	float r =  rand() % (max - min) + min;
		return r;
}
