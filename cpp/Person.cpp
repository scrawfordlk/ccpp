#include "Person.h"
#include "Identity.h"
#include <iostream>

using std::ostream;

Person::Person(const Identity &self, const Identity &father, const Identity &mother) : self(self) {
    *this->father = father;
    *this->mother = mother;
    this->marked = false;
}

Person::Person(const Identity &self) : self(self) {
    this->father = nullptr;
    this->mother = nullptr;
    this->marked = false;
}

bool Person::isChildOf(const Person &person) const {
    return (father != nullptr && *father == person.self) ||
           (mother != nullptr && *mother == person.self);
}

bool Person::isParentOf(const Person &person) const {
    return (person.father != nullptr && *person.father == self) ||
           (person.mother != nullptr && *person.mother == self);
}

void Person::mark() {
    marked = true;
}

bool Person::isMarked() const {
    return marked;
}

bool Person::operator==(const Person &other) const {
    return self == other.self;
}

bool Person::operator!=(const Person &other) const {
    return self != other.self;
}

bool Person::operator<(const Person &other) const {
    return self < other.self;
}

bool Person::operator>(const Person &other) const {
    return self > other.self;
}

bool Person::operator<=(const Person &other) const {
    return self <= other.self;
}

bool Person::operator>=(const Person &other) const {
    return self >= other.self;
}

ostream &operator<<(ostream &stream, const Person &person) {
    return stream << person.self;
}
