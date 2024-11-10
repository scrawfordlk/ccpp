#include "people.h"
#include <stdio.h>
#include <stdlib.h>

static void swapPerson(People *people, int i, int j);

/**
 * reads and stores people from the specified file in a People struct and returns a pointer to it
 * */
People *readPeople(char *fileName) {
    FILE *pFile = fopen(fileName, "r");
    if (pFile == NULL) {
        fprintf(stderr, "couldn't open %s\n", fileName);
        exit(1);
    }

    People *people = newPeople();

    char firstName[21], lastName[21], birthyear[5], garbage[21];
    Id *personId, *fatherId, *motherId;

    while (fscanf(pFile, "%20s %20s %1s %4s", firstName, lastName, garbage, birthyear) != EOF) {
        personId = newId(firstName, lastName, birthyear);

        fscanf(pFile, "%4s ", garbage); // skip year of death

        fscanf(pFile, "%20s %20s %4s ", firstName, lastName, birthyear);
        fatherId = newId(firstName, lastName, birthyear);

        fscanf(pFile, "%20s %20s %4s\n", firstName, lastName, birthyear);
        motherId = newId(firstName, lastName, birthyear);

        addToPeople(people, newPerson(personId, fatherId, motherId));
    }

    fclose(pFile);
    return people;
}

/**
 * writes a People struct to the specified file
 */
void writePeople(People *people, char *fileName) {
    FILE *pFile = fopen(fileName, "w");
    if (pFile == NULL) {
        printf("couldn't open %s", fileName);
        exit(1);
    }

    Id *id;
    for (int i = 0; i < people->size; i++) {
        id = people->list[i]->id;
        fprintf(pFile, "%s %s %s\n", id->firstName, id->lastName, id->birthyear);
    }

    fclose(pFile);
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
