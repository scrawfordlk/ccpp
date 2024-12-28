#include "Identity.h"
#include <iostream>
#include <string>

using std::ostream;
using std::string;

// -------------------- public ---------------------

Identity::Identity(const string &firstName, const string &lastName, const string &birthyear)
    : firstName(firstName), lastName(lastName), birthyear(birthyear) {}

Identity::Identity() {}

// ------------ comparison operators ---------------

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

// ----------------- private -----------------------

int Identity::compareTo(const Identity &other) const {
    if (birthyear != other.birthyear) {
        return birthyear.compare(other.birthyear);
    }

    if (lastName != other.lastName) {
        return lastName.compare(other.lastName);
    }

    return firstName.compare(other.firstName);
}

// --------------- non member functions ------------------

ostream &operator<<(ostream &stream, const Identity &identity) {
    return stream << identity.firstName << " " << identity.lastName << " " << identity.birthyear;
}
