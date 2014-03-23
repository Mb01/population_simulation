/*
 * Person.cpp
 *
 *  Created on: Jan 5, 2014
 *      Author: mark
 */

#include "Person.h"
#include "stdlib.h"
#include "statistics_helpers.h"
#include <iostream>

Person::Person(){
	age = 0;
	fertility = 0.0;
	had_child = false;
	child = NULL;
	alive = true;
	have_child_from = 0;
	have_child_to = 0;
}

//death
Person::~Person(){
	//goodbye world
}

//things we want to do once a year like get older and check for births/deaths
void Person::age_year(){
	//at the start of each year we haven't had a child yet
	//although we could be still dead
	child = NULL;
	had_child = false;
	//calls the code that decides if we have a child
	decide_had_child();
	//calls the code that decides if we are dead
	decide_if_dead();
	//at the end of the year we're one year older
	age++;
}

//*getters*

int Person::get_age(){
	return age;
}

bool Person::get_had_child(){
	return had_child;
}

Person* Person::get_child(){
	return child;
}
bool Person::get_alive(){
	return alive;
}


//*setters*

void Person::set_when_fertile(int from, int to){
	have_child_from = from;
	have_child_to = to;
}

void Person::set_fertility(float fertility){
	this->fertility = fertility;
}

void Person::set_age(int age){
    this->age = age;
}
//*private funtions*

//decide whether to have a child and have it now!
void Person::decide_had_child(){
	if ( !(age >= have_child_from && age <= have_child_to) )
		return;
	if(rand_zero_one() < fertility){
	    have_child();
		had_child = true;
	}
}
void Person::have_child(){
	this->child = new Person();
	this->child->set_fertility(this->fertility);
	this->child->set_when_fertile(this->have_child_from, this->have_child_to);
}
//TODO model death better
void Person::decide_if_dead(){
	int magically_die_at = 80;
	if( age >= magically_die_at){
		alive = false;
	}
}
