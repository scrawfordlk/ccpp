#include "Person.h"
#include "Identity.h"
#include <iostream>

using std::ostream;

// -------------------- public -----------------------

Person::Person(const Identity &self, const Identity &father, const Identity &mother)
    : self(self), father(father), mother(mother), marked(false) {}

Person::Person(const Identity &self) : self(self), marked(false) {}

bool Person::isParentOf(const Person &other) const {
    return isFatherOf(other) || isMotherOf(other);
}

const Identity *Person::getFather() const {
    return &father;
}

const Identity *Person::getMother() const {
    return &mother;
}

void Person::mark() {
    marked = true;
}

bool Person::isMarked() const {
    return marked;
}

// ------------- comparison operators ---------------

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

// --------------- private ------------------

bool Person::isFatherOf(const Person &other) const {
    return self == other.father;
}

bool Person::isMotherOf(const Person &other) const {
    return self == other.mother;
}

// --------------- non member functions ----------------

ostream &operator<<(ostream &stream, const Person &person) {
    return stream << person.self;
}
