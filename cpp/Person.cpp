#include "Person.h"
#include "Identity.h"
#include <iostream>
#include <memory>

using std::ostream, std::unique_ptr;

Person::Person(unique_ptr<Identity> self, unique_ptr<Identity> father, unique_ptr<Identity> mother)
    : self(std::move(self)), father(std::move(father)), mother(std::move(mother)), marked(false) {}

Person::Person(unique_ptr<Identity> self) : self(std::move(self)) {
    this->father = nullptr;
    this->mother = nullptr;
    this->marked = false;
}

bool Person::isChildOf(const Person &person) const {
    return (father != nullptr && *father == *person.self) ||
           (mother != nullptr && *mother == *person.self);
}

bool Person::isParentOf(const Person &person) const {
    return (person.father != nullptr && *person.father == *self) ||
           (person.mother != nullptr && *person.mother == *self);
}

void Person::setMark() {
    marked = true;
}

bool Person::operator==(const Person &other) const {
    return *self == *other.self;
}

bool Person::operator!=(const Person &other) const {
    return *self != *other.self;
}

bool Person::operator<(const Person &other) const {
    return *self < *other.self;
}

bool Person::operator>(const Person &other) const {
    return *self > *other.self;
}

bool Person::operator<=(const Person &other) const {
    return *self <= *other.self;
}

bool Person::operator>=(const Person &other) const {
    return *self >= *other.self;
}

ostream &operator<<(ostream &stream, const Person &person) {
    return stream << *person.self;
}
