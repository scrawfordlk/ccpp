#include "person.h"
#include <stdio.h>

/**
 * struct that stores array of Person pointers and its length
 */
typedef struct People {
    int len;
    Person **list;
} People;

People *readPeople(char *fileName);
static char *getWord(FILE *filePointer);
void sortPeople(People *people);
static int isSorted(People *people);
People *newPeople(int len, Person **list);
void freePeople(People *people);
