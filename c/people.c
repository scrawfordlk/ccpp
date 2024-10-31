#include "people.h"
#include "person.h"
#include "string.h"
#include <stdlib.h>

// TODO: refactor the reallocation and change implementation details
// to reduce number of realloc calls by setting a standard size for the array
// and then resizing it by factor 2 whenever it is full
/**
 * returns a pointer to a People structure of all people in the given file
 */
People *readPeople(char *fileName) {

    FILE *filePointer = fopen(fileName, "r");
    if (filePointer == NULL) {
        fprintf(stderr, "couldn't open %s\n", fileName);
        exit(1);
    }

    People *people = newPeople();

    Id *personId, *fatherId, *motherId;
    char c, *firstName, *lastName, *birthday;
    while ((c = getc(filePointer)) != EOF) {
        ungetc(c, filePointer);

        // person
        firstName = getWord(filePointer);
        lastName = getWord(filePointer);
        getWord(filePointer); // skip gender
        birthday = getWord(filePointer);
        getWord(filePointer); // skip year of death
        personId = newId(firstName, lastName, birthday);

        // father
        firstName = getWord(filePointer);
        lastName = getWord(filePointer);
        birthday = getWord(filePointer);
        fatherId = newId(firstName, lastName, birthday);

        // mother
        firstName = getWord(filePointer);
        lastName = getWord(filePointer);
        birthday = getWord(filePointer);
        motherId = newId(firstName, lastName, birthday);

        addToPeople(people, newPerson(personId, fatherId, motherId));
    }

    fclose(filePointer);
    return people;
}

/**
 * returns next word from the part where filePointer is pointing to
 */
static char *getWord(FILE *filePointer) {
    int len = 0;
    char *word = malloc(sizeof(char) * len);

    char currentChar;
    while ((currentChar = fgetc(filePointer)) != EOF && currentChar != ' ' && currentChar != '\n') {

        len++;
        word = realloc(word, sizeof(char) * len);
        if (word == NULL) {
            exit(1);
        }

        word[len - 1] = currentChar;
        word[len] = '\0';
    }

    return word;
}

/**
 * receives pointer to sorted People struct, the unique identification of a Person (first name, last
 * name and birthday) and returns a pointer to this person.
 *
 * Returns NULL, if this Person doesn't exist
 */
Person *getPerson(People *people, char *firstName, char *lastName, char *birthday) {
    for (int i = 0; i < people->currentLen; i++) {
        if (strcmp(people->list[i]->id->firstName, firstName) == 0 &&
            strcmp(people->list[i]->id->lastName, lastName) == 0 &&
            strcmp(people->list[i]->id->birthday, birthday) == 0) {
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

        for (int i = 0; i < people->currentLen - 1; i++) {
            if (comparePerson(people->list[i], people->list[i + 1]) > 0) {
                isSorted = 0;
                swapPerson(people, i, i + 1);
            }
        }
    }
}

/**
 * swaps pointers of two Person structs
 */
void swapPerson(People *people, int i, int j) {
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
    people->currentLen = 0;
    people->capacity = 10;
    people->list = malloc(sizeof(Person *) * people->capacity);
    return people;
}

static void addToPeople(People *people, Person *person) {
    if (people->currentLen == people->capacity) {
        people->capacity *= 2;
        people->list = realloc(people->list, sizeof(Person *) * people->capacity);
        if (people->list == NULL) {
            exit(1);
        }
    }
    people->list[people->currentLen++] = person;
}

// TODO: test
/**
 * frees memory from a People struct
 */
void freePeople(People *people) {
    for (int i = 0; i < people->currentLen; i++) {
        freePerson(people->list[i]);
    }
    free(people->list);
    free(people);
}
