#include "id.h"
#include <stdlib.h>
#include <string.h>

/**
 * compares an Id A to an Id B and returns integer <, == or > than 0 if Id A is smaller,
 * equal or larger than Id B where a Id is sorted according to (in order) their birthyear,
 * last name, first name
 */
int compareId(Id *idA, Id *idB) {
    int cmp = strncmp(idA->birthyear, idB->birthyear, 4);
    if (cmp != 0) {
        return cmp;
    }

    cmp = strncmp(idA->lastName, idB->lastName, 20);
    if (cmp != 0) {
        return cmp;
    }

    return strncmp(idA->firstName, idB->firstName, 20);
}

/**
 * returns true if this Id is someone's Id as specified by their first name, last name and
 * birthyear
 */
int isIdOf(Id *id, char *firstName, char *lastName, char *birthyear) {
    return strncmp(id->firstName, firstName, 20) == 0 && strncmp(id->lastName, lastName, 20) == 0 &&
           strncmp(id->birthyear, birthyear, 4) == 0;
}

/**
 * create a new Id struct and return a pointer to it
 */
Id *newId(char *firstName, char *lastName, char *birthyear) {
    Id *id = malloc(sizeof(Id));
    if (id == NULL) {
        exit(1);
    }

    strcpy(id->firstName, firstName);
    strcpy(id->lastName, lastName);
    strcpy(id->birthyear, birthyear);
    return id;
}
