#include "Person.h"
#include "Identity.h"
#include <iostream>

using std::ostream;

Person::Person(const Identity &self, const Identity &father, const Identity &mother)
    : self(self), father(father), mother(mother), marked(false) {}

Person::Person(const Identity &self) : self(self), marked(false), hasKnownParents(false) {}

const Identity *Person::getFather() const {
    return hasKnownParents ? &father : nullptr;
}

const Identity *Person::getMother() const {
    return hasKnownParents ? &mother : nullptr;
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
