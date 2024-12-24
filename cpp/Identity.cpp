#include "Identity.h"
#include <iostream>

using std::make_unique;
using std::ostream;
using std::string;

Identity::Identity(const char *firstName, const char *lastName, const char *birthyear)
    : firstName(make_unique<string>(firstName)), lastName(make_unique<string>(lastName)),
      birthyear(make_unique<string>(birthyear)) {}

bool Identity::operator==(const Identity &other) const {
    return compareTo(other) == 0;
}

bool Identity::operator!=(const Identity &other) const {
    return compareTo(other) != 0;
}

bool Identity::operator<(const Identity &other) const {
    return compareTo(other) < 0;
}

bool Identity::operator>(const Identity &other) const {
    return compareTo(other) > 0;
}

bool Identity::operator<=(const Identity &other) const {
    return compareTo(other) <= 0;
}

bool Identity::operator>=(const Identity &other) const {
    return compareTo(other) >= 0;
}

int Identity::compareTo(const Identity &other) const {
    if (*birthyear != *other.birthyear) {
        return birthyear->compare(*other.birthyear);
    }

    if (*lastName != *other.lastName) {
        return lastName->compare(*other.birthyear);
    }

    return firstName->compare(*other.firstName);
}

ostream &operator<<(ostream &stream, const Identity &identity) {
    return stream << *identity.firstName << " " << *identity.lastName << " " << *identity.birthyear;
}
