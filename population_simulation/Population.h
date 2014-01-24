/*
 * Population.h
 *
 *  Created on: Jan 5, 2014
 *      Author: mark
 */

#ifndef POPULATION_H_
#define POPULATION_H_

#include "Person.h"
#include <vector>
// has container for "Person" class people

class Population {
public:
	Population();
	virtual ~Population();
	//does one year of simulation
	void do_year();
	//initialization helper for Simulation
	//adds n people to the population
	//sets age, fertility
	//have child from/to and
	void add_people(int n, int max_age, float fertility, int children_from, int children_to);
private:
	//the base container
	std::vector<Person*> people;
	//container to hold people who survive 
	std::vector<Person*> temp;
	//helper function for setting up used by add_people
	void add_person(int, float, int, int);
};




#endif /* POPULATION_H_ */
