#include "relatives.h"
#include <stdio.h>
#include <stdlib.h>

static People *extractRelatives(People *people);
static void markRelatives(People *people, Person *person);
static void markChildren(People *people, Person *parent);
static int isParentOf(People *people, Person *parent, Person *child);
static int isFatherOf(People *people, Person *father, Person *child);
static int isMotherOf(People *people, Person *mother, Person *child);

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
static void markChildren(People *people, Person *parent) {
    Person *child;

    for (int i = 0; i < people->size; i++) {
        child = people->list[i];
        if (isParentOf(people, parent, child) && !child->marked) {
            child->marked = 1;
            markChildren(people, child);
        }
    }
}

/**
 * return 1 if 'parent' is a parent of 'child' otherwise 0
 * */
static int isParentOf(People *people, Person *parent, Person *child) {
    return isFatherOf(people, parent, child) || isMotherOf(people, parent, child);
}

/**
 * return 1 if 'father' is father of 'child' otherwise 0
 * */
static int isFatherOf(People *people, Person *father, Person *child) {
    return isThisPerson(father, child->fatherId->firstName, child->fatherId->lastName,
                        child->fatherId->birthyear);
}

/**
 * return 1 if 'mother' is mother of 'child' otherwise 0
 * */
static int isMotherOf(People *people, Person *mother, Person *child) {
    return isThisPerson(mother, child->motherId->firstName, child->motherId->lastName,
                        child->motherId->birthyear);
}

/**
 * frees relatives pointer with assumption that the pointers to each Person struct has been freed
 * (but not the array containing them)
 * */
void freeRelatives(People *relatives) {
    free(relatives->list);
    free(relatives);
}
