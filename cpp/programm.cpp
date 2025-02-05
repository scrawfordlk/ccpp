#include "People.h"
#include <iostream>
#include <memory>
#include <string>

using std::string;
using std::unique_ptr;

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

    People people;
    unique_ptr<People> relatives;
    try {
        people.readPeople(inFileName);
        relatives = people.getRelatives(firstName, lastName, birthyear);
    } catch (string errorMessage) {
        std::cerr << errorMessage << std::endl;
        return 1;
    }

    relatives->sort();
    relatives->writePeople(outFileName);
}
