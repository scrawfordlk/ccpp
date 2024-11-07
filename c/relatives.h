#ifndef RELATIVES_H
#define RELATIVES_H
#include "people.h"

People *getRelatives(People *people, char *firstName, char *lastName, char *birthday);
People *extractRelatives(People *people);
void markRelatives(People *people, Person *person);
void markChildren(People *people, Person *person);
int isParentOf(People *people, Person *potentialParent, Person *potentialChild);
int isFatherOf(People *people, Person *potentFather, Person *potentChild);
int isMotherOf(People *people, Person *potentMother, Person *potentChild);

void freeRelatives(People *relatives);

#endif
