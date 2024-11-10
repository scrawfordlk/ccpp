#include "relatives.h"
#include <stdio.h>
#include <stdlib.h>

static People *extractRelatives(People *people);
static void markRelatives(People *people, Person *person);
static void markChildren(People *people, Person *person);
static int isParentOf(People *people, Person *potentialParent, Person *potentialChild);
static int isFatherOf(People *people, Person *potentFather, Person *potentChild);
static int isMotherOf(People *people, Person *potentMother, Person *potentChild);

/**
 *  returns a People struct with all Person structs who are relatives of the given Person
 */
People *getRelatives(People *people, char *firstName, char *lastName, char *birthyear) {
    Person *person = getPerson(people, firstName, lastName, birthyear);
    if (person == NULL) {
        fprintf(stderr, "The person \"%s %s\" born \"%s\" doesn't exist\n", firstName, lastName,
                birthyear);
        exit(1);
    }

    markRelatives(people, person);
    return extractRelatives(people);
}

/**
 * returns a new People struct with all Person structs who were marked (attribute marked == 1)
 * it does this by copying the wanted Person structs
 * */
static People *extractRelatives(People *people) {
    People *relatives = newPeople();
    for (int i = 0; i < people->size; i++) {
        if (people->list[i]->marked) {
            addToPeople(relatives, people->list[i]);
        }
    }
    return relatives;
}

/**
 * marks all relatives of a Person
 * */
static void markRelatives(People *people, Person *person) {
    Person *father = getPerson(people, person->fatherId->firstName, person->fatherId->lastName,
                               person->fatherId->birthyear);
    if (father != NULL) {
        father->marked = 1;
        markRelatives(people, father);
    }

    Person *mother = getPerson(people, person->motherId->firstName, person->motherId->lastName,
                               person->motherId->birthyear);
    if (mother != NULL) {
        mother->marked = 1;
        markRelatives(people, mother);
    }

    markChildren(people, person);
}

/**
 * marks all descendants of this Person
 * */
static void markChildren(People *people, Person *person) {
    for (int i = 0; i < people->size; i++) {
        if (isParentOf(people, person, people->list[i])) {
            people->list[i]->marked = 1;
            markChildren(people, people->list[i]);
        }
    }
}

/**
 * return 1 if potentParent is a parent of potentChild otherwise 0
 * */
static int isParentOf(People *people, Person *potentParent, Person *potentChild) {
    return isFatherOf(people, potentParent, potentChild) ||
           isMotherOf(people, potentParent, potentChild);
}

/**
 * return 1 if potentFather is father of potentChild otherwise 0
 * */
static int isFatherOf(People *people, Person *potentFather, Person *potentChild) {
    return isThisPerson(potentFather, potentChild->fatherId->firstName,
                        potentChild->fatherId->lastName, potentChild->fatherId->birthyear);
}

/**
 * return 1 if potentMother is mother of potentChild otherwise 0
 * */
static int isMotherOf(People *people, Person *potentMother, Person *potentChild) {
    return isThisPerson(potentMother, potentChild->motherId->firstName,
                        potentChild->motherId->lastName, potentChild->motherId->birthyear);
}

/**
 * frees relatives pointer with assumption that the pointers to each Person struct has been freed
 * (but not the array containing them)
 * */
void freeRelatives(People *relatives) {
    free(relatives->list);
    free(relatives);
}
