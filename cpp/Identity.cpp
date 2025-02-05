#include "Identity.h"

int Identity::compareTo(const Identity &other) const {
    if (birthyear != other.birthyear) {
        return birthyear.compare(other.birthyear);
    }

    if (lastName != other.lastName) {
        return lastName.compare(other.lastName);
    }

    return firstName.compare(other.firstName);
}
