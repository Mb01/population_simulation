/*
 * main.cpp
 *
 *  Created on: Jan 5, 2014
 *      Author: mark
 */

#include <iostream>

#include "stdlib.h"
#include "time.h"

#include "Simulation.h"


int main(int arv, char** argc){
	std::cout << "Begin program" << '\n';
	std::cout.flush();
	//init random number generator
	int t = time(NULL);
	srand(t);

	Simulation sim;
    sim.set_initial_people(100);
    sim.set_years_to_simulate(100);
    sim.do_simulation();
    std::cout << "took " << time(NULL) - t << " seconds";
	return 0;
}

