#include "people.h"
#include "relatives.h"
#include <stdio.h>
#include <stdlib.h>

void printPeople(People *people) {
    for (int i = 0; i < people->currentLen; i++) {
        Person *person = people->list[i];
        printf("%p %s %s %s %s %s %s %s %s %s\n", person, person->id->firstName,
               person->id->lastName, person->id->birthday, person->fatherId->firstName,
               person->fatherId->lastName, person->fatherId->birthday, person->motherId->firstName,
               person->motherId->lastName, person->motherId->birthday);
    }
    printf("printed %d people", people->currentLen);
}

int main(int argc, char *argv[]) {

    if (argc != 6) {
        fputs("Usage: programm <personen.dat> <stand.dat> <vorname> <nachname> <geburt>\n", stderr);
        exit(1);
    }

    char *fileName = argv[1];
    char *firstName = argv[3];
    char *lastName = argv[4];
    char *birthday = argv[5];

    People *people = readPeople(fileName);
    People *relatives = getRelatives(people, firstName, lastName, birthday);
    sortPeople(relatives);
    printPeople(relatives);
    writePeople(relatives, "garbo.dat");
    freePeople(people);
    freeRelatives(relatives);
}
