#include "People.h"
#include "Person.h"
#include <algorithm>
#include <iostream>
#include <memory>
#include <vector>

using std::ostream;
using std::shared_ptr;
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

ostream &operator<<(ostream &stream, const People &people) {
    for (const shared_ptr<Person> &person : people.people) {
        stream << *person << '\n';
    }

    return stream;
}
