#include "person.h"
#include "id.h"
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
