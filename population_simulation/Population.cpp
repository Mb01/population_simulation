/*
 * Population.cpp
 *
 *  Created on: Jan 5, 2014
 *      Author: mark
 */

#include <iostream>
#include "Population.h"
#include "stdlib.h"

// helper to get a random integer min inclusive max exclusive
float rand_int(int min, int max){
	float r =  rand() % (max - min) + min;
		return r;
}

Population::Population() {
	//nothing to initialize yet
}

Population::~Population() {

}

//run one year of the simulation
void Population::do_year(){
	//run age year on every person in population
	for(std::vector<Person*>::iterator it = people.begin(); it < people.end(); it++){
		(*it)->age_year();
		//check to see if they had any children and add them to population
		if((*it)->get_had_child()){
			//add them to the population
			temp.push_back(((*it)->get_child()));
		}
		//keep people still alive in the population
		if((*it)->get_alive()){
			temp.push_back(*it);
		}else{
			//they die (but there pointed child lives)
			delete (*it);
		}
	}
	//set people to next years people
	people = temp;
	//reset temp
	temp.clear();

	std::cout << people.size() << " people\n";
}

//build a base population with randomly distributed age and identical everything else
void Population::add_people(int n, int max_age, float fertility, int children_from, int children_to){
    //add n people
    for(int x = 0; x < n; x++){
    Person* person = new Person();
    person->set_fertility(fertility);
    person->set_when_fertile(children_from, children_to);
    person->set_age(rand_int(0,max_age));
    this->people.push_back(person);
    }
}
//use this for setting up the population
void Population::add_person(int age, float fertility, int have_child_from, int have_child_to){
	Person* person = new Person();
	person->set_age(age);
	person->set_fertility(fertility);
	person->set_when_fertile(have_child_from,have_child_to);
	people.push_back(person);
}
