#include "People.h"
#include "people.h"
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

    string fileName = argv[1];
    string firstName = argv[3];
    string lastName = argv[4];
    string birthyear = argv[5];

    unique_ptr<People> people;
    try {
        people = readPeople(fileName);
    } catch (string errorMessage) {
        std::cerr << errorMessage << std::endl;
        return 1;
    }

    std::cout << *people << std::endl;
}
