#!/usr/bin/env python
                                            # how many people living after x years given initial arguments and probabilities?                                            
                                            # considering from female only perspective
                                            # note: defualt values are arbitrary 
import random

population = []

num_people = 100                            # how many people to add at the beginning
longevity = 80                              # when to remove people from population
num_years = 1000                            # how long to simulate

                                            # values (start 20, end 40, chance 0.05) give average of one girl per woman per life
start_fertile = 20                          # when do births start
end_fertile = 40                            # when do births end,
chance_girl = 0.07                          # chance, in parts of one, of having a girl in one year,


class Person:
    def __init__(self):                     # be born
        self.age = 0                        # everyone is 0 at birth
        population.append(self)             # everyone born joins the population

    def age_year(self):                     # get one year older
        if  self.age >= start_fertile \
        and self.age <= end_fertile   \
        and random.random() < chance_girl:  # chance of random number between 0.0 and 1.0 being less == chance of having a girl
            Person()                        # give birth

        if self.age > longevity:            # average is good enough here over long enough time becuase it doesn't compound
            population.remove(self)         # die

        self.age += 1                       # become one year older


for x in xrange(num_people):                # add num_people people to the population with random integer age between 0 and longevity
    Person().age = (int(longevity * random.random()))# should have used randrange
for x in xrange(num_years):                 # for the number of years to simulate
    if x % 50 == 0: 
        print "year:", x,"population",len(population) 
    for person in population:               # ...
        person.age_year()                   # ...

print len(population)                       # length of the populatoin list is size of population

        
