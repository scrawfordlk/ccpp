#include "relatives.h"
#include <stdio.h>

// Passt sonst.  Rade
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
    writePeople(relatives, "verwandte.dat");
    freePeople(people);
    freeRelatives(relatives);
}
