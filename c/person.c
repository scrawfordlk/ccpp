#include "person.h"
#include <stdlib.h>
#include <string.h>

// TODO: refactor the reallocation and change implementation details
// to reduce number of realloc calls by setting a standard size for the array
// and then resizing it by factor 2 whenever it is full
/**
 * returns a pointer to a People structure of all people in the given file
 */
People *readPeople(char *fileName) {

    FILE *filePointer = fopen(fileName, "r");
    if (filePointer == NULL) {
        fprintf(stderr, "couldn't open %s\n", fileName);
        exit(1);
    }

    // TODO: change this
    int len = 0;
    Person **personList = malloc(sizeof(Person *) * len); // dynamic array of Person pointers
    if (personList == NULL) {
        exit(1);
    }

    Id *personId, *fatherId, *motherId;
    char c, *firstName, *lastName, *birthday;
    while ((c = getc(filePointer)) != EOF) {
        ungetc(c, filePointer);

        // person
        firstName = getWord(filePointer);
        lastName = getWord(filePointer);
        getWord(filePointer); // skip gender
        birthday = getWord(filePointer);
        personId = newId(firstName, lastName, birthday);
        getWord(filePointer); // skip year of death

        // father
        firstName = getWord(filePointer);
        lastName = getWord(filePointer);
        birthday = getWord(filePointer);
        fatherId = newId(firstName, lastName, birthday);

        // mother
        firstName = getWord(filePointer);
        lastName = getWord(filePointer);
        birthday = getWord(filePointer);
        motherId = newId(firstName, lastName, birthday);

        // TODO: change this
        // resize array and add new Person
        len++;
        personList = realloc(personList, sizeof(Person *) * len);
        if (personList == NULL) {
            exit(1);
        }
        personList[len - 1] = newPerson(personId, fatherId, motherId);
    }

    fclose(filePointer);
    return newPeople(len, personList);
}

/**
 * returns next word from the part where filePointer is pointing to
 */
static char *getWord(FILE *filePointer) {
    int len = 0;
    char *word = malloc(sizeof(char) * len);

    char currentChar;
    while ((currentChar = fgetc(filePointer)) != EOF && currentChar != ' ' && currentChar != '\n') {

        len++;
        word = realloc(word, sizeof(char) * len);
        if (word == NULL) {
            exit(1);
        }

        word[len - 1] = currentChar;
        word[len] = '\0';
    }

    return word;
}

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
    Person *someone = getPerson(people, "Cynthia", "Hohlbichler", "1875");
    Person *someone2 = getPerson(people, "Karl", "Ranseier", "1925");
    printf("%p %s %s\n", someone, someone->id->firstName, someone->id->lastName);
    printf("%p %s %s\n", someone2, someone2->id->firstName, someone2->id->lastName);
    puts("----------------");

    swapPerson(&people->list[2], &people->list[3]);
    printf("%p %s %s\n", someone, someone->id->firstName, someone->id->lastName);
    printf("%p %s %s\n", someone2, someone2->id->firstName, someone2->id->lastName);

    puts("----------------");
    puts("----------------");
    printPeople(people);
}

/**
 * receives pointer to sorted People struct, the unique identification of a Person (first name, last
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

// TODO: implement
/*
 * sorts the People struct that people points to
 */
void sortPeople(People *people) {}

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

// TODO: Works, but is too complicated to use.
// rewrite it so that you only need the indexes in the People struct
/**
 * swaps pointers of two Person structs
 */
static void swapPerson(Person **personA, Person **personB) {
    Person *tmp = *personA;
    *personA = *personB;
    *personB = tmp;
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

/**
 * create a new People struct and return pointer to it
 */
People *newPeople(int len, Person **list) {
    People *people = malloc(sizeof(People));
    if (people == NULL) {
        exit(1);
    }
    people->len = len;
    people->list = list;
    return people;
}

// TODO: test
/**
 * frees memory from a People struct
 */
void freePeople(People *people) {
    for (int i = 0; i < people->len; i++) {

        free(people->list[i]->id->firstName);
        free(people->list[i]->id->lastName);
        free(people->list[i]->id->birthday);
        free(people->list[i]->id);

        free(people->list[i]->fatherId->firstName);
        free(people->list[i]->fatherId->lastName);
        free(people->list[i]->fatherId->birthday);
        free(people->list[i]->fatherId);

        free(people->list[i]->motherId->firstName);
        free(people->list[i]->motherId->lastName);
        free(people->list[i]->motherId->birthday);
        free(people->list[i]->motherId);

        free(people->list[i]);
    }
    free(people);
}
