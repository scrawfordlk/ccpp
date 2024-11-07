#include "person.h"
#include "id.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * compares a Person A to a Person B and returns integer <, == or > than 0 if Person A is smaller,
 * equal or larger than Person B where a Person is sorted according to (in order) their birthday,
 * last name, first name
 */
int comparePerson(Person *personA, Person *personB) {
    int cmp = strcmp(personA->id->birthday, personB->id->birthday);
    if (cmp != 0) {
        return cmp;
    }

    cmp = strcmp(personA->id->lastName, personB->id->lastName);
    if (cmp != 0) {
        return cmp;
    }

    return strcmp(personA->id->firstName, personB->id->firstName);
}

/**
 * returns true if this Person is this Person as specified by their first name, last name and
 * birthday
 */
int isThisPerson(Person *person, char *firstName, char *lastName, char *birthday) {
    if (strcmp(person->id->firstName, firstName) == 0 &&
        strcmp(person->id->lastName, lastName) == 0 &&
        strcmp(person->id->birthday, birthday) == 0) {
        return 1;
    }

    return 0;
}

/**
 * created a new Person and return pointer to it
 */
Person *newPerson(Id *id, Id *fatherId, Id *motherId) {
    Person *person = malloc(sizeof(Person));
    if (person == NULL) {
        exit(1);
    }
    person->id = id;
    person->fatherId = fatherId;
    person->motherId = motherId;
    person->marked = 0;
    return person;
}

/**
 * frees memory from a Person struct
 */
void freePerson(Person *person) {
    freeId(person->id);
    freeId(person->fatherId);
    freeId(person->motherId);
    free(person);
}
