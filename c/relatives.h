#ifndef RELATIVES_H
#define RELATIVES_H
#include "people.h"

People *getRelatives(People *people, char *firstName, char *lastName, char *birthyear);
static People *extractRelatives(People *people);

static void markRelatives(People *people, Person *person);
static void markChildren(People *people, Person *person);
static int isParentOf(People *people, Person *potentialParent, Person *potentialChild);
static int isFatherOf(People *people, Person *potentFather, Person *potentChild);
static int isMotherOf(People *people, Person *potentMother, Person *potentChild);

void freeRelatives(People *relatives);

#endif
