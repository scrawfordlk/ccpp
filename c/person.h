#ifndef PERSON_H
#define PERSON_H

#include "id.h"

/**
 * defines a Person struct that stores its Id (= first name, last name and birthyear) as well as the
 * id's of their father/mother
 */
typedef struct {
    Id *id;
    Id *fatherId;
    Id *motherId;
    int marked;
} Person;

int comparePerson(Person *personA, Person *personB);
int isThisPerson(Person *person, char *firstName, char *lastName, char *birthyear);
Person *newPerson(Id *id, Id *fatherId, Id *motherId);
void freePerson(Person *person);

#endif
