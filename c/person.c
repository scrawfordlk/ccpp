#include "person.h"
#include <stdlib.h>
#include <string.h>

// for testing purposes
void printPeople(People *people) {
    for (int i = 0; i < people->len; i++) {
        Person *person = people->list[i];
        printf("%p %s %s %s %s %s %s %s %s %s\n", person, person->id->firstName,
               person->id->lastName, person->id->birthday, person->fatherId->firstName,
               person->fatherId->lastName, person->fatherId->birthday, person->motherId->firstName,
               person->motherId->lastName, person->motherId->birthday);
    }
}

// for testing purposes
int main(void) {
    People *people = readPeople("personen.dat");
    printPeople(people);
    puts("----------------");
    puts("----------------");
    sortPeople(people);
    printPeople(people);
    printf("%i", isSorted(people));
    writePeople(people, "verwandte.dat");
}

/**
 * receives pointer to People struct, the unique identification of a Person (first name, last
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

/**
 * compares a Person A to a Person B and returns integer <, == or > than 0 if Person A is smaller,
 * equal or larger than Person B where a Person is sorted according to (in order) their birthday,
 * last name, first name
 */
static int comparePerson(Person *personA, Person *personB) {
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
 * swaps pointers of two Person structs
 */
static void swapPerson(People *people, int i, int j) {
    Person *tmp = people->list[i];
    people->list[i] = people->list[j];
    people->list[j] = tmp;
}

/**
 * create a new Id and return a pointer to it
 */
Id *newId(char *firstName, char *lastName, char *birthday) {
    Id *id = malloc(sizeof(Id));
    if (id == NULL) {
        exit(1);
    }
    id->firstName = firstName;
    id->lastName = lastName;
    id->birthday = birthday;
    return id;
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

