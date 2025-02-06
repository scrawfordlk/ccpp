#include "Person.h"

bool Person::parentIsMarked() const {
    bool marked = false;

    if (father != nullptr) {
        marked = marked || father->isMarked();
    }

    if (mother != nullptr) {
        marked = marked || mother->isMarked();
    }

    return marked;
}
