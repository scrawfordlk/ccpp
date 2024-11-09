#include "people.h"
#include "id.h"
#include "person.h"
#include "string.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * reads and stores people from the specified file in a People struct and returns a pointer to it
 * */
People *readPeople(char *fileName) {
    FILE *filePointer = fopen(fileName, "r");
    if (filePointer == NULL) {
        fprintf(stderr, "couldn't open %s\n", fileName);
        exit(1);
    }

    People *people = newPeople();

    Id *personId, *fatherId, *motherId;
    char firstName[21], lastName[21], birthyear[5], garbage[21];

    char status;
    while ((status = getc(filePointer)) != EOF) {
        ungetc(status, filePointer);

        fscanf(filePointer, "%20s %20s ", firstName, lastName);
        fscanf(filePointer, "%1s ", garbage); // skip gender
        fscanf(filePointer, "%4s ", birthyear);
        Id *personId = newId(firstName, lastName, birthyear);

        fscanf(filePointer, "%4s ", garbage); // skip year of death

        fscanf(filePointer, "%20s %20s %4s ", firstName, lastName, birthyear);
        Id *fatherId = newId(firstName, lastName, birthyear);

        fscanf(filePointer, "%20s %20s %4s\n", firstName, lastName, birthyear);
        Id *motherId = newId(firstName, lastName, birthyear);

        addToPeople(people, newPerson(personId, fatherId, motherId));
    }

    fclose(filePointer);
    return people;
}

/**
 * writes a People struct to the specified file
 */
void writePeople(People *people, char *fileName) {
    FILE *filePointer = fopen(fileName, "w");
    if (filePointer == NULL) {
        printf("couldn't open %s", fileName);
        exit(1);
    }

    Id *id;
    for (int i = 0; i < people->size; i++) {
        id = people->list[i]->id;
        fprintf(filePointer, "%s %s %s\n", id->birthyear, id->lastName, id->firstName);
    }

    fclose(filePointer);
}

/**
 * receives unique id of a Person (in the form of 3 Strings) and returns a pointer to this person.
 *
 * Returns NULL, if this Person doesn't exist
 */
Person *getPerson(People *people, char *firstName, char *lastName, char *birthyear) {
    for (int i = 0; i < people->size; i++) {
        if (isThisPerson(people->list[i], firstName, lastName, birthyear)) {
            return people->list[i];
        }
    }

    return NULL;
}

// TODO: Use qsort
/*
 * sorts the People struct that people points to
 */
void sortPeople(People *people) {
    int isSorted = 0;

    while (!isSorted) {
        isSorted = 1;

        for (int i = 0; i < people->size - 1; i++) {
            if (comparePerson(people->list[i], people->list[i + 1]) > 0) {
                isSorted = 0;
                swapPerson(people, i, i + 1);
            }
        }
    }
}

/**
 * swaps pointers of two Person structs in a People struct
 */
static void swapPerson(People *people, int i, int j) {
    Person *tmp = people->list[i];
    people->list[i] = people->list[j];
    people->list[j] = tmp;
}

/**
 * create a new People struct and return pointer to it
 */
People *newPeople() {
    People *people = malloc(sizeof(People));
    if (people == NULL) {
        exit(1);
    }

    people->capacity = 10;
    people->list = malloc(sizeof(Person *) * people->capacity);
    if (people->list == NULL) {
        exit(1);
    }

    people->size = 0;
    return people;
}

/**
 * adds a new Person pointer to a People struct
 * returns 1 if successful, 0 if reallocation fails
 * */
void addToPeople(People *people, Person *person) {
    if (people->size == people->capacity) {
        people->capacity *= 2;
        people->list = realloc(people->list, sizeof(Person *) * people->capacity);
        if (people->list == NULL) {
            exit(1);
        }
    }

    people->list[people->size++] = person;
}

/**
 * frees memory from a People struct
 */
void freePeople(People *people) {
    for (int i = 0; i < people->size; i++) {
        freePerson(people->list[i]);
    }
    free(people->list);
    free(people);
}
