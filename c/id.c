#include "id.h"
#include <stdlib.h>

/**
 * create a new Id and return a pointer to it
 */
Id *newId(char *firstName, char *lastName, char *birthday) {
    Id *id = malloc(sizeof(Id));
    if (id == NULL) {
        exit(1);
    }
    id->firstName = firstName;
    id->lastName = lastName;
    id->birthday = birthday;
    return id;
}

/**
 * frees memory from an Id struct
 */
void freeId(Id *id) {
    free(id->firstName);
    free(id->lastName);
    free(id->birthday);
    free(id);
}
