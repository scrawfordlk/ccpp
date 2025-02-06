#include "People.h"
#include <iostream>
#include <memory>
#include <string>

using std::string;

int main(int argc, char *argv[]) {

    if (argc != 6) {
        std::cerr << "Usage: programm <personen.dat> <stand.dat> <vorname> <nachname> <geburt>"
                  << std::endl;
        return 1;
    }

    string inFileName = argv[1];
    string outFileName = "verwandte.dat";
    string firstName = argv[3];
    string lastName = argv[4];
    string birthyear = argv[5];

    People people = People();
    try {
        people.readPeople(inFileName);
        people.getRelatives(firstName, lastName, birthyear)->writePeople(outFileName);
    } catch (string errorMessage) {
        std::cerr << errorMessage << std::endl;
        return 1;
    }
}
