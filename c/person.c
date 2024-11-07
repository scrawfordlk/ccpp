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
    int cmp = strncmp(personA->id->birthday, personB->id->birthday, 100);
    if (cmp != 0) {
        return cmp;
    }

    cmp = strncmp(personA->id->lastName, personB->id->lastName, 100);
    if (cmp != 0) {
        return cmp;
    }

    return strncmp(personA->id->firstName, personB->id->firstName, 100);
}

/**
 * returns true if this Person is this Person as specified by their first name, last name and
 * birthday
 */
int isThisPerson(Person *person, char *firstName, char *lastName, char *birthday) {
    if (strncmp(person->id->firstName, firstName, 100) == 0 &&
        strncmp(person->id->lastName, lastName, 100) == 0 &&
        strncmp(person->id->birthday, birthday, 100) == 0) {
        return 1;
    }
    return 0;
}

/**
 * create a new Person and return pointer to it
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
