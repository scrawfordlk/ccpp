#include "people.h"
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

    // TODO: change this
    int len = 0;
    Person **personList = malloc(sizeof(Person *) * len); // dynamic array of Person pointers
    if (personList == NULL) {
        exit(1);
    }

    Id *personId, *fatherId, *motherId;
    char c, *firstName, *lastName, *birthday;
    while ((c = getc(filePointer)) != EOF) {
        ungetc(c, filePointer);

        // person
        firstName = getWord(filePointer);
        lastName = getWord(filePointer);
        getWord(filePointer); // skip gender
        birthday = getWord(filePointer);
        personId = newId(firstName, lastName, birthday);
        getWord(filePointer); // skip year of death

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

        // TODO: change this
        // resize array and add new Person
        len++;
        personList = realloc(personList, sizeof(Person *) * len);
        if (personList == NULL) {
            exit(1);
        }
        personList[len - 1] = newPerson(personId, fatherId, motherId);
    }

    fclose(filePointer);
    return newPeople(len, personList);
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
    for (int i = 0; i < people->len; i++) {
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

        for (int i = 0; i < people->len - 1; i++) {
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
People *newPeople(int len, Person **list) {
    People *people = malloc(sizeof(People));
    if (people == NULL) {
        exit(1);
    }
    people->len = len;
    people->list = list;
    return people;
}

// TODO: test
/**
 * frees memory from a People struct
 */
void freePeople(People *people) {
    for (int i = 0; i < people->len; i++) {
        freePerson(people->list[i]);
    }
    free(people->list);
    free(people);
}
