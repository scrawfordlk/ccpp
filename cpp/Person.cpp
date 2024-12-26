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

const Identity &Person::getFather() const {
    return *father;
}

const Identity &Person::getMother() const {
    return *mother;
}

void Person::mark() {
    marked = true;
}

bool Person::isMarked() const {
    return marked;
}

// ------------- overloaded operators ---------------

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
