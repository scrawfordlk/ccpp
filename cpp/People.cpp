#include "People.h"
#include "Identity.h"
#include "Person.h"
#include <algorithm>
#include <iostream>
#include <memory>
#include <vector>

using std::string, std::vector, std::ostream;
using std::unique_ptr, std::make_unique, std::make_shared, std::shared_ptr, std::weak_ptr;

People::People() : people(make_unique<vector<shared_ptr<Person>>>()) {}

int People::size() const {
    return people->size();
}

void People::push(std::shared_ptr<Person> person) {
    people->push_back(person);
}

weak_ptr<Person> People::at(int index) const {
    return index < people->size() ? people->at(index) : weak_ptr<Person>();
}

weak_ptr<Person> People::findPerson(string firstName, string lastName, string birthyear) const {
    auto targetId =
        make_unique<Identity>(make_unique<string>(firstName), make_unique<string>(lastName),
                              make_unique<string>(birthyear));
    auto target = make_shared<Person>(std::move(targetId));

    if (!exists(target)) {
        return weak_ptr<Person>();
    }

    return getPerson(target);
}

bool People::exists(shared_ptr<Person> person) const {
    return std::binary_search(
        people->begin(), people->end(), person,
        [](const shared_ptr<Person> p1, const shared_ptr<Person> p2) { return *p1 < *p2; });
}
e weak_ptr<Person> People::getPerson(shared_ptr<Person> person) const {
    return *std::lower_bound(
        people->begin(), people->end(), person,
        [](const shared_ptr<Person> p1, const shared_ptr<Person> p2) { return *p1 < *p2; });
}

void People::sort() {
    std::sort(people->begin(), people->end(),
              [](shared_ptr<Person> p1, shared_ptr<Person> p2) { return *p1 < *p2; });
}

std::unique_ptr<People> People::findRelatives(std::shared_ptr<Person> person) {
    sort();
    markRelatives(person);
    return std::move(extractMarked());
}

void People::markRelatives(std::shared_ptr<Person> person){
    weak_ptr<Person> father = findPerson(person.unique, string lastName, string birthyear)}

unique_ptr<People> People::extractMarked() {
    auto markedPeople = make_unique<People>();
    for (vector<shared_ptr<Person>>::iterator p = people->begin(); p != people->end(); p++) {
        if ((*p)->isMarked()) {
            markedPeople->push(*p);
        }
    }

    return std::move(markedPeople);
}

ostream &operator<<(ostream &stream, const People &people) {
    for (vector<shared_ptr<Person>>::iterator p = people.people->begin(); p != people.people->end();
         p++) {
        stream << **p;
    }

    return stream;
}
