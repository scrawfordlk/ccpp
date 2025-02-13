#include "People.h"
#include <iostream>
#include <string>

using std::string;

int main(int argc, char *argv[]) {

    if (argc != 6) {
        std::cerr << "Usage: programm <personen.dat> <stand.dat> <vorname> <nachname> <geburt>"
                  << std::endl;
        return 1;
    }

    string inputName = argv[1];
    string outputName = "verwandte.dat";
    string firstName = argv[3];
    string lastName = argv[4];
    string birthyear = argv[5];

    People people = People();
    try {
        people.readFile(inputName);
        people.getRelatives(firstName, lastName, birthyear)->writeFile(outputName);
    } catch (string errorMessage) {
        std::cerr << errorMessage << std::endl;
        return 1;
    }
}
