#include "people.h"
#include "Identity.h"
#include "Person.h"
#include <algorithm>
#include <array>
#include <fstream>
#include <memory>
#include <string>

using std::array, std::vector, std::string, std::unique_ptr, std::make_unique, std::shared_ptr;

/**
 * returns a unique_ptr to a new Person assembled from the given array of information
 * */
static std::unique_ptr<Person> constructPerson(const array<string, 11> &personInfo);

/**
 * sorts the vector of unique_ptr's to Person using std::sort()
 * */
static void sort(unique_ptr<vector<unique_ptr<Person>>> &people);

unique_ptr<vector<shared_ptr<Person>>> readPeople(const char *fileName) {
    std::ifstream file = std::ifstream(fileName);
    if (!file.is_open()) {
        throw string("Invalid file name: " + string(fileName) + '\n');
    }

    auto people = make_unique<vector<shared_ptr<Person>>>();
    array<string, 11> input;
    while (!file.eof()) {

        for (int i = 0; i < 11; i++) {
            file >> input[i];
        }

        shared_ptr<Person> person = constructPerson(input);
        people->push_back(std::move(person));
    }
    file.close();

    // remove last person who was added twice
    people->pop_back();

    sort(people);
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

static void sort(unique_ptr<vector<shared_ptr<Person>>> people) {
    std::sort(people->begin(), people->end(),
              [](unique_ptr<Person> &p1, unique_ptr<Person> &p2) { return *p1 < *p2; });
}
