#include <stdio.h>

/**
 * unique identification for a Person
 */
typedef struct Id {
    char *firstName;
    char *lastName;
    char *birthday;
} Id;

/**
 * defines a Person struct that stores its Id (= first name, last name and birthday) as well as the
 * id's of their father/mother
 */
typedef struct Person {
    Id *id;
    Id *fatherId;
    Id *motherId;
} Person;

/**
 * struct that stores array of Person pointers and its length
 */
typedef struct People {
    int len;
    Person **list;
} People;

Id *newId(char *firstName, char *lastName, char *birthday);
Person *newPerson(Id *id, Id *fatherId, Id *motherId);
People *newPeople(int len, Person **list);
void freePeople(People *people);

static char *getWord(FILE *filePointer);
People *readPeople(char *fileName);

static int comparePerson(Person *personA, Person *personB);
