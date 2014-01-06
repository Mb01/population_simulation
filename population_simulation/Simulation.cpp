/*
 * Simulation.cpp
 *
 *  Created on: Jan 5, 2014
 *      Author: mark
 */

#include "Simulation.h"

//HERE BE MAGIC TEST NUMBERS
//TODO implement other ways

//defaults
const int MAX_AGE = 80;
const int HAVE_FROM = 20;
const int HAVE_TO = 40;
const float FERTILITY = 0.1;

Simulation::Simulation() {
	population = new Population();
	initial_pop = 0;
	num_years = 0;
}

Simulation::~Simulation(){
    //should I free this?
	delete population;
}

// how many people are there initially
void Simulation::set_initial_people(int num_people){
	initial_pop = num_people;
}

// how long is the simulation
void Simulation::set_years_to_simulate(int n_years){
	num_years = n_years;
}

void Simulation::do_simulation(){
	// build our initial population
	population->add_people(this->initial_pop,  MAX_AGE, FERTILITY, HAVE_FROM, HAVE_TO);
	// run for as many years as needed
	for(int x = 0; x < this->num_years; x++){
	    this->population->do_year();
	}
}
