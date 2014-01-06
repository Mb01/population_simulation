/*
 * Person.h
 *
 *  Created on: Jan 5, 2014
 *      Author: mark
 */

#ifndef PERSON_H_
#define PERSON_H_

//for simulating population growth
//TODO give some inheritable traits
class Person{
	public:
		Person();
		~Person();
		//simulate one year for the person, adds a year to age *will* do a simulation later
		void age_year();

		//gets age of person
		int get_age();
		//gets had child
		bool get_had_child();
		//gets child pointer
		Person* get_child();
		//gets alive
		bool get_alive();
        
        //sets age
        void set_age(int);
		//sets have_child_from, have_child_to
		void set_when_fertile(int,int);
		//sets fertility 0 to 1
		void set_fertility(float);
        

	private:
		//age in years
		int age;
		//when can women have children
		int have_child_from;
		int have_child_to;
		//chance of having child in given year while can have children
		float fertility;
		//flags for events
		//did the person have a child
		bool had_child;
		//this makes a new person object!
		//TODO for now just a clone
		void have_child();
		//is the person alive
		bool alive;
		//helpers for age_year
		void decide_had_child();
		void decide_if_dead();
		//holds the child until the start of next year
		Person* child;

	};

#endif
