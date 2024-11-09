#ifndef PEOPLE_H
#define PEOPLE_H

#include "person.h"

/**
 * struct that stores array of Person pointers and its length
 */
typedef struct {
    int capacity;
    int size;
    Person **list;
} People;

People *readPeople(char *fileName);
void writePeople(People *people, char *fileName);

Person *getPerson(People *people, char *firstName, char *lastName, char *birthyear);

void sortPeople(People *people);

People *newPeople();
void addToPeople(People *people, Person *person);
void freePeople(People *people);

#endif
