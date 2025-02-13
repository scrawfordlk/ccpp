#include "People.h"
#include "Identity.h"
#include "Person.h"
#include <algorithm>
#include <array>
#include <fstream>
#include <memory>
#include <string>

using std::ifstream;
using std::shared_ptr, std::make_shared, std::unique_ptr, std::make_unique;
using std::string;

// ------------------- public ---------------------

void People::sort() {
    std::sort(people.begin(), people.end(),
              [](shared_ptr<Person> p1, shared_ptr<Person> p2) { return *p1 < *p2; });
}

unique_ptr<People> People::getRelatives(const string &firstName, const string &lastName,
                                        const string &birthyear) {
    sort();
    Identity id = Identity(firstName, lastName, birthyear);
    shared_ptr<Person> person = findPerson(id);
    if (person == nullptr) {
        throw "This person does not exist: " + firstName + " " + lastName + ", born " + birthyear;
    }

    assignParents();
    markAncestors(*person);
    markDescendants();
    return extractMarkedPeople();
}

void People::readFile(const string &fileName) {
    ifstream file = ifstream(fileName);
    if (!file.is_open()) {
        throw "Invalid file name: " + fileName;
    }

    std::array<string, 11> input;
    while (!file.eof()) {

        for (int i = 0; i < input.size(); i++) {
            file >> input[i];
        }

        Identity id = Identity(input[0], input[1], input[3]);
        Identity fatherId = Identity(input[5], input[6], input[7]);
        Identity motherId = Identity(input[8], input[9], input[10]);
        push(make_shared<Person>(id, fatherId, motherId));
    }
    file.close();

    // remove last person who was added twice
    pop();
}

// --------------------- private ----------------------

shared_ptr<Person> People::findPerson(const Identity &identity) {
    auto dummy = make_shared<Person>(identity);
    shared_ptr<Person> person =
        *std::lower_bound(people.begin(), people.end(), dummy,
                          [](shared_ptr<Person> p1, shared_ptr<Person> p2) { return *p1 < *p2; });
    return *person == *dummy ? person : nullptr;
}

void People::assignParents() {
    for (shared_ptr<Person> person : people) {
        person->setFather(findPerson(person->getFatherId()));
        person->setMother(findPerson(person->getMotherId()));
    }
}

void People::markAncestors(const Person &person) {
    if (person.getFather() != nullptr) {
        person.getFather()->mark();
        markAncestors(*person.getFather());
    }

    if (person.getMother() != nullptr) {
        person.getMother()->mark();
        markAncestors(*person.getMother());
    }
}

void People::markDescendants() {
    bool markedMore = true;
    while (markedMore) {
        markedMore = false;

        for (shared_ptr<Person> child : people) {
            if (child->parentIsMarked() && !child->isMarked()) {
                child->mark();
                markedMore = true;
            }
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

// ----------------------- (friend) functions ---------------------------------

std::ostream &operator<<(std::ostream &stream, const People &people) {
    for (std::shared_ptr<Person> person : people.people) {
        stream << *person << '\n';
    }

    return stream;
}
