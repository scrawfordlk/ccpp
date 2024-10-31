#ifndef PEOPLE_H
#define PEOPLE_H

#include "person.h"
#include <stdio.h>

/**
 * struct that stores array of Person pointers and its length
 */
typedef struct {
    int capacity;
    int currentLen;
    Person **list;
} People;

People *newPeople();
void freePeople(People *people);

static char *getWord(FILE *filePointer);
People *readPeople(char *fileName);
static void addToPeople(People *people, Person *person);

Person *getPerson(People *people, char *firstName, char *lastName, char *birthday);
void sortPeople(People *people);
void swapPerson(People *people, int i, int j);

#endif
