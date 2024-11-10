#ifndef RELATIVES_H
#define RELATIVES_H

#include "people.h"

People *getRelatives(People *people, char *firstName, char *lastName, char *birthyear);
void freeRelatives(People *relatives);

#endif
