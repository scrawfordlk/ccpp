#include "people.h"
#include "Identity.h"
#include "Person.h"
#include <algorithm>
#include <array>
#include <fstream>
#include <memory>
#include <string>

using std::array;
using std::ifstream;
using std::string;
using std::unique_ptr, std::make_unique, std::shared_ptr;
using std::vector;

/**
 * Returns a unique_ptr to a new Person assembled from the given array of information.
 * */
static std::unique_ptr<Person> constructPerson(const array<string, 11> &personInfo);

/**
 * Sorts the vector of unique_ptr's to Person using std::sort().
 * */
static void sort(vector<shared_ptr<Person>> *people);

unique_ptr<vector<shared_ptr<Person>>> readPeople(string &fileName) {
    ifstream file = ifstream(fileName);
    if (!file.is_open()) {
        throw "Invalid file name: " + fileName + '\n';
    }

    auto people = make_unique<vector<shared_ptr<Person>>>();
    array<string, 11> input;
    while (!file.eof()) {

        for (int i = 0; i < 11; i++) {
            file >> input[i];
        }

        shared_ptr<Person> person = constructPerson(input);
        people->push_back(person);
    }
    file.close();

    // remove last person who was added twice
    people->pop_back();

    sort(people.get());
    return std::move(people);
}

static std::unique_ptr<Person> constructPerson(const array<string, 11> &personFragments) {
    Identity id = Identity(personFragments[0], personFragments[1], personFragments[3]);

    // case parents and no parents
    if (personFragments[5] != "-" && personFragments[8] != "-") {
        Identity fatherId = Identity(personFragments[5], personFragments[6], personFragments[7]);
        Identity motherId = Identity(personFragments[8], personFragments[9], personFragments[10]);
        return make_unique<Person>(id, fatherId, motherId);
    } else {
        return make_unique<Person>(id);
    }
}

// FRAGE zu std::sort: Wird beim Sortieren die Elemente per Kopie oder per Referenz getauscht? Oder
// ist das nicht klar definiert?
static void sort(vector<shared_ptr<Person>> *people) {
    std::sort(people->begin(), people->end(),
              [](shared_ptr<Person> p1, shared_ptr<Person> p2) { return *p1 < *p2; });
}
