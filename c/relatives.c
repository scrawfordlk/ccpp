#include "relatives.h"
#include "people.h"
#include "person.h"
#include "stdio.h"
#include <stdlib.h>
#include <string.h>

/**
 *  returns a People struct with all Person structs who are relatives of the given Person
 */
People *getRelatives(People *people, char *firstName, char *lastName, char *birthday) {
    Person *person = getPerson(people, firstName, lastName, birthday);
    if (person == NULL) {
        fprintf(stderr, "The person \"%s %s\" born in \"%s\" doesn't exist", firstName, lastName,
                birthday);
        exit(1);
    }

    markRelatives(people, person);
    return extractRelatives(people);
}

/**
 * returns a new People struct with all Person structs who were marked (attribute marked == 1)
 * */
People *extractRelatives(People *people) {
    People *relatives = newPeople();
    for (int i = 0; i < people->currentLen; i++) {
        if (people->list[i]->marked == 1) {
            addToPeople(relatives, people->list[i]);
        }
    }
    return relatives;
}
/**
 * marks all relatives of a Person
 * */
void markRelatives(People *people, Person *person) {
    Person *father = getPerson(people, person->fatherId->firstName, person->fatherId->lastName,
                               person->fatherId->birthday);
    if (father != NULL) {
        father->marked = 1;
        markRelatives(people, father);
    }

    Person *mother = getPerson(people, person->motherId->firstName, person->motherId->lastName,
                               person->motherId->birthday);
    if (mother != NULL) {
        mother->marked = 1;
        markRelatives(people, mother);
    }

    markChildren(people, person);
}

/**
 * marks all descendants of this Person
 * */
void markChildren(People *people, Person *person) {
    for (int i = 0; i < people->currentLen; i++) {
        if (isParentOf(people, person, people->list[i])) {
            people->list[i]->marked = 1;
            markChildren(people, people->list[i]);
        }
    }
}

/**
 * return 1 if potentParent is a parent of potentChild otherwise 0
 * */
int isParentOf(People *people, Person *potentParent, Person *potentChild) {
    if (isFatherOf(people, potentParent, potentChild) ||
        isMotherOf(people, potentParent, potentChild)) {
        return 1;
    }

    return 0;
}

/**
 * return 1 if potentFather is father of potentChild
 * */
int isFatherOf(People *people, Person *potentFather, Person *potentChild) {
    return isThisPerson(potentFather, potentChild->fatherId->firstName,
                        potentChild->fatherId->lastName, potentChild->fatherId->birthday);
}

/**
 * return 1 if potentMother is mother of potentChild
 * */
int isMotherOf(People *people, Person *potentMother, Person *potentChild) {
    return isThisPerson(potentMother, potentChild->motherId->firstName,
                        potentChild->motherId->lastName, potentChild->motherId->birthday);
}

/**
 * frees relatives pointer with assumption that the people pointer it's based off was already
 * freed
 * */
void freeRelatives(People *relatives) {
    free(relatives);
}
