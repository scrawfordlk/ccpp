#include "relatives.h"
#include <stdio.h>

static void printPeople(People *people) {
    for (int i = 0; i < people->size; i++) {
        Person *person = people->list[i];
        printf("%p %s %s %s %s %s %s %s %s %s\n", person, person->id->firstName,
               person->id->lastName, person->id->birthyear, person->fatherId->firstName,
               person->fatherId->lastName, person->fatherId->birthyear, person->motherId->firstName,
               person->motherId->lastName, person->motherId->birthyear);
    }
    printf("printed %d people", people->size);
}

int main(int argc, char *argv[]) {

    if (argc != 6) {
        fputs("Usage: programm <personen.dat> <stand.dat> <vorname> <nachname> <geburt>\n", stderr);
        return 1;
    }

    char *fileName = argv[1];
    char *firstName = argv[3];
    char *lastName = argv[4];
    char *birthyear = argv[5];

    People *people = readPeople(fileName);
    People *relatives = getRelatives(people, firstName, lastName, birthyear);
    sortPeople(relatives);
    printPeople(relatives);
    writePeople(relatives, "verwandte.dat");
    freePeople(people);
    freeRelatives(relatives);
}
