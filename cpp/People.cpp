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

/**
 * Evaluates the operation < for two shared_ptr's to a Person each.
 * */
static bool comparePerson(shared_ptr<Person> p1, shared_ptr<Person> p2);

// ------------------- public ---------------------

People::People() : people(vector<shared_ptr<Person>>()) {
    people.reserve(20);
}

void People::push(shared_ptr<Person> person) {
    people.push_back(person);
}

void People::pop() {
    if (people.size() >= 1) {
        people.pop_back();
    }
}

void People::sort() {
    std::sort(people.begin(), people.end(), comparePerson);
}

unique_ptr<People> People::getRelatives(const string &firstName, const string &lastName,
                                        const string &birthyear) {
    Identity id = Identity(firstName, lastName, birthyear);
    shared_ptr<Person> person = findPerson(id);
    if (person == nullptr) {
        throw "This person does not exist: " + firstName + " " + lastName + ", born " + birthyear;
    }

    markRelatives(person);
    return extractMarkedPeople();
}

// --------------------- private ----------------------

shared_ptr<Person> People::findPerson(const Identity &identity) {
    sort();
    auto dummy = make_shared<Person>(identity);

    if (!std::binary_search(people.begin(), people.end(), dummy, comparePerson)) {
        return nullptr;
    }

    return *std::lower_bound(people.begin(), people.end(), dummy, comparePerson);
}

void People::markRelatives(shared_ptr<Person> person) {
    Identity fatherId = person->getFather();
    shared_ptr<Person> father = findPerson(fatherId);
    if (father != nullptr) {
        father->mark();
        markRelatives(father);
    }

    Identity motherId = person->getMother();
    shared_ptr<Person> mother = findPerson(motherId);
    if (mother != nullptr) {
        mother->mark();
        markRelatives(mother);
    }

    markChildren(person);
}

void People::markChildren(shared_ptr<Person> person) {
    shared_ptr<Person> child;
    for (shared_ptr<Person> child : people) {
        if (person->isParentOf(*child) && !child->isMarked()) {
            child->mark();
            markChildren(child);
        }
    }
}

unique_ptr<People> People::extractMarkedPeople() const {
    auto markedPeople = make_unique<People>();
    for (shared_ptr<Person> person : people) {
        if (person->isMarked()) {
            markedPeople->push(person);
        }
    }
    return markedPeople;
}

// ---------------- non member functions --------------------

ostream &operator<<(ostream &stream, const People &people) {
    for (shared_ptr<Person> person : people.people) {
        stream << *person << '\n';
    }

    return stream;
}

// ---------------- static functions ---------------------

static bool comparePerson(shared_ptr<Person> p1, shared_ptr<Person> p2) {
    return *p1 < *p2;
}
