#include "Identity.h"
#include <iostream>
#include <memory>
#include <string>

using std::ostream, std::string, std::unique_ptr;

Identity::Identity(unique_ptr<string> firstName, unique_ptr<string> lastName,
                   unique_ptr<string> birthyear)
    : firstName(std::move(firstName)), lastName(std::move(lastName)),
      birthyear(std::move(birthyear)) {}

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
