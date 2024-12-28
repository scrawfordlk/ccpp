#include "people.h"
#include "Identity.h"
#include "People.h"
#include "Person.h"
#include <array>
#include <fstream>
#include <memory>
#include <string>

using std::array;
using std::ifstream, std::ofstream;
using std::string;
using std::unique_ptr, std::make_unique;

/**
 * Returns a unique_ptr to a new Person assembled from the given array of information.
 * */
static std::unique_ptr<Person> constructPerson(const array<string, 11> &personInfo);

unique_ptr<People> readPeople(const string &fileName) {
    ifstream file = ifstream(fileName);
    if (!file.is_open()) {
        throw "Invalid file name: " + fileName;
    }

    auto people = make_unique<People>();
    array<string, 11> input;
    while (!file.eof()) {

        for (int i = 0; i < 11; i++) {
            file >> input[i];
        }

        people->push(constructPerson(input));
    }
    file.close();

    // remove last person who was added twice
    people->pop();

    return people;
}

void writePeople(const People &people, const std::string &fileName) {
    ofstream file = ofstream(fileName);
    file << people;
    file.close();
}

static std::unique_ptr<Person> constructPerson(const array<string, 11> &personFragments) {
    Identity id = Identity(personFragments[0], personFragments[1], personFragments[3]);
    Identity fatherId = Identity(personFragments[5], personFragments[6], personFragments[7]);
    Identity motherId = Identity(personFragments[8], personFragments[9], personFragments[10]);
    return make_unique<Person>(id, fatherId, motherId);
}
