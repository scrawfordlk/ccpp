#include "people.h"
#include <stdio.h>
#include <stdlib.h>

void printPeople(People *people) {
    for (int i = 0; i < people->len; i++) {
        Person *person = people->list[i];
        printf("%p %s %s %s %s %s %s %s %s %s\n", person, person->id->firstName,
               person->id->lastName, person->id->birthday, person->fatherId->firstName,
               person->fatherId->lastName, person->fatherId->birthday, person->motherId->firstName,
               person->motherId->lastName, person->motherId->birthday);
    }
}

int main(int argc, char *argv[]) {

    // if (argc != 6) {
    //     fputs("Usage: programm <personen.dat> <stand.dat> <vorname> <nachname> <geburt>\n",
    //     stderr); exit(1);
    // }

    People *people = readPeople("personen.dat");
    printPeople(people);
    sortPeople(people);
    puts("----------------");
    printPeople(people);
}
