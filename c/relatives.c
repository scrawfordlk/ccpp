#include "people.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * writes a sorted People struct to a file
 */
void writePeople(People *people, char *fileName) {
    FILE *filePointer = fopen(fileName, "w");
    if (filePointer == NULL) {
        printf("couldn't open %s", fileName);
        exit(1);
    }

    Id *id;
    for (int i = 0; i < people->len; i++) {
        id = people->list[i]->id;
        fprintf(filePointer, "%s %s %s\n", id->birthday, id->lastName, id->firstName);
    }

    fclose(filePointer);
}
