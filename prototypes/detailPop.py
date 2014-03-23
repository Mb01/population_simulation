#!/usr/bin/env python


# so our prototype suggests a Person object, a population container, and a Simulation object
# population generation/modeling
# room for genetics -> has a genome object
# statistically meaningful distributions -> fertility changes over time differently for each person

# note: defualt values are arbitrary
import random

# enumerate these critical stats
MALE = 0
FEMALE = 1
WILL_HAVE_CHILD = 2
WILL_DIE = 3

#don't access these from object, use ENUMS
male = []
female = []
will_have_child = []
will_die = []

population = [male,female, will_have_child, will_die]


# let's say people die at a certain age to approx average for now
# (they won't have any more children in the sim anyway)
DIEAT = 80

class Person:
    """more flexible person simulator for population simulation"""
    def __init__(self, start_fertile, end_fertile, fertility, container=None ):
        self.age = 0
        self.start_fertile = start_fertile
        # for now the sexes don't get seperate fertility
        self.end_fertile = end_fertile 
        # fertility is chance per year of having a child while fertile
        self.fertility = fertility
        # determine sex
        if random.random() > 0.5:
            self.sex = FEMALE
        else:
            self.sex = MALE
        # add self to the appropriate container, it would be better if Person didn't have manage container
        if container:
            self.container = container
            container[self.sex].append(self)

    def give_birth(self):
        """wrapped so something more complicated code could go here if needed"""
        assert self.age >= self.start_fertile
        assert self.age <= self.end_fertile 
        assert self.sex == FEMALE
        Person(self.start_fertile, self.end_fertile, self.fertility, container=self.container)
        
    def die(self):
        """remove self from the population container"""
        self.container[self.sex].remove(self)
     
    def age_year(self):
        """simulate a year in the life of the person"""
        if self.sex == FEMALE and self.age >= self.start_fertile and self.age <= self.end_fertile:
            if random.random() < self.fertility:
                self.container[WILL_HAVE_CHILD].append(self)
        if self.age > DIEAT:
                self.container[WILL_DIE].append(self)
        self.age += 1


for person in xrange(100):
    # hard code in 100 clones
    Person(20,40,0.10, population)
    
   # hard code a test simulation, should have object, or function that takes years and runs this
for year in xrange(100):
    for man in male:
        man.age_year()
    for woman in female:
        woman.age_year()
    for person in will_die:
        person.die()
    # remove all the objects without breaking the connection to population
    del will_die[:]
    for woman in will_have_child:
        # rollback the age and put it back after
        woman.age -= 1
        woman.give_birth()
        woman.age += 1
    del will_have_child[:]
    
    if year%10 == 0:
        print year, len(population[MALE]), len(population[FEMALE])
        
print len(population[MALE]), len(population[FEMALE])

