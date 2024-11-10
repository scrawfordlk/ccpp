#include "person.h"
#include <stdlib.h>

/**
 * compares a Person A to a Person B and returns integer <, == or > than 0 if Person A is smaller,
 * equal or larger than Person B where a Person is sorted according to (in order) their birthyear,
 * last name, first name
 */
int comparePerson(Person *personA, Person *personB) {
    return compareId(personA->id, personB->id);
}

/**
 * returns true if this Person is this person as specified by their first name, last name and
 * birthyear
 */
int isThisPerson(Person *person, char *firstName, char *lastName, char *birthyear) {
    return isIdOf(person->id, firstName, lastName, birthyear);
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
    free(person->id);
    free(person->fatherId);
    free(person->motherId);
    free(person);
}
