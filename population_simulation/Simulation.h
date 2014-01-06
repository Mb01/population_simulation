/*
 * Simulation.h
 *
 *  Created on: Jan 5, 2014
 *      Author: mark
 */

#ifndef SIMULATION_H_
#define SIMULATION_H_

#include "Population.h"

class Simulation {
public:
	Simulation();
	virtual ~Simulation();
	void set_initial_people(int);
	void set_years_to_simulate(int);
	void do_simulation();
private:
	Population* population;
	int initial_pop;
	int num_years;
	//TODO some more parameters to simulate like models for lifespan, average fertility
	//     more complicated statistics
};

#endif /* SIMULATION_H_ */
