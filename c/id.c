#include "id.h"
#include <stdlib.h>
#include <string.h>

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
