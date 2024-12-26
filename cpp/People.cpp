#include "People.h"
#include "Identity.h"
#include "Person.h"
#include <algorithm>
#include <iostream>
#include <memory>
#include <string>
#include <vector>

using std::ostream;
using std::shared_ptr, std::make_shared, std::unique_ptr, std::make_unique;
using std::string;
using std::vector;

People::People() : people(vector<shared_ptr<Person>>()) {}

void People::push(shared_ptr<Person> person) {
    people.push_back(person);
}

void People::pop() {
    if (people.size() >= 1) {
        people.pop_back();
    }
}

void People::sort() {
    std::sort(people.begin(), people.end(),
              [](shared_ptr<Person> p1, shared_ptr<Person> p2) { return *p1 < *p2; });
}

/*unique_ptr<People> People::getRelatives(string &firstName, string &lastName, string &birthyear)
 * {*/
/*    if (person == nullptr) {*/
/*        throw "This person does not exist: " + firstName + " " + lastName + ", born " +
 * birthyear;*/
/*    }*/
/**/
/*    markRelatives(person);*/
/*    return extractMarkedPeople();*/
/*}*/

shared_ptr<Person> People::findPerson(string &firstName, string &lastName, string &birthyear) {
    sort();
    auto dummy = make_shared<Person>(Identity(firstName, lastName, birthyear));

    if (!std::binary_search(
            people.begin(), people.end(), dummy,
            [](shared_ptr<Person> p1, shared_ptr<Person> p2) { return *p1 < *p2; })) {
        return nullptr;
    }

    return *std::lower_bound(
        people.begin(), people.end(), dummy,
        [](shared_ptr<Person> p1, shared_ptr<Person> p2) { return *p1 < *p2; });
}

unique_ptr<People> People::extractMarkedPeople() const {
    auto markedPeople = make_unique<People>();
    for (shared_ptr<Person> person : people) {
        if (person->isMarked()) {
            markedPeople->push(person);
        }
    }
    return std::move(markedPeople);
}

// --------------- overloaded operators --------------------
ostream &operator<<(ostream &stream, const People &people) {
    for (const shared_ptr<Person> person : people.people) {
        stream << *person << '\n';
    }

    return stream;
}
