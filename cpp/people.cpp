#include "people.h"
#include "Identity.h"
#include "Person.h"
#include <algorithm>
#include <array>
#include <fstream>
#include <memory>
#include <string>

using std::array, std::vector, std::string, std::unique_ptr, std::make_unique;

/**
 * returns a unique_ptr to a new Person assembled from the given array of information
 * */
static unique_ptr<Person> constructPerson(const array<string, 11> &personInfo);

/**
 * sorts the vector of unique_ptr's to Person using std::sort()
 * */
static void sort(unique_ptr<vector<unique_ptr<Person>>> &people);

unique_ptr<vector<unique_ptr<Person>>> readPeople(const char *fileName) {
    std::ifstream file = std::ifstream(fileName);
    if (!file.is_open()) {
        throw string("Invalid file name: " + string(fileName) + '\n');
    }

    auto people = make_unique<vector<unique_ptr<Person>>>();
    array<string, 11> input;
    while (!file.eof()) {

        for (int i = 0; i < 11; i++) {
            file >> input[i];
        }

        unique_ptr<Person> person = constructPerson(input);
        people->push_back(std::move(person));
    }
    file.close();

    // remove last person who was added twice
    people->pop_back();

    sort(people);
    return std::move(people);
}

static unique_ptr<Person> constructPerson(const array<string, 11> &personFragments) {
    auto firstName = make_unique<string>(personFragments[0]);
    auto lastName = make_unique<string>(personFragments[1]);
    auto birthyear = make_unique<string>(personFragments[3]);
    auto id =
        make_unique<Identity>(std::move(firstName), std::move(lastName), std::move(birthyear));

    auto fFirstName = make_unique<string>(personFragments[5]);
    auto fLastName = make_unique<string>(personFragments[6]);
    auto fBirthyear = make_unique<string>(personFragments[7]);

    auto mFirstName = make_unique<string>(personFragments[8]);
    auto mLastName = make_unique<string>(personFragments[9]);
    auto mBirthyear = make_unique<string>(personFragments[10]);

    // case parents and no parents
    if (*fFirstName != "-" && *mFirstName != "-") {
        auto fId = make_unique<Identity>(std::move(fFirstName), std::move(fLastName),
                                         std::move(fBirthyear));
        auto mId = make_unique<Identity>(std::move(mFirstName), std::move(mLastName),
                                         std::move(mBirthyear));
        return make_unique<Person>(std::move(id), std::move(fId), std::move(mId));
    } else {
        return make_unique<Person>(std::move(id));
    }
}

static void sort(unique_ptr<vector<unique_ptr<Person>>> &people) {
    std::sort(people->begin(), people->end(),
              [](unique_ptr<Person> &p1, unique_ptr<Person> &p2) { return *p1 < *p2; });
}
