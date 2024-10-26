#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {

    if (argc != 6) {
        fputs("Usage: programm <personen.dat> <stand.dat> <vorname> <nachname> <geburt>\n", stderr);
        exit(1);
    }
}
