#ifndef PERSON_CLASS_H
#define PERSON_CLASS_H

#include "Identity.h"
#include <iostream>

/**
 * Class that stores the identification of the person, their father and mother.
 * Each Person can be set to be marked.
 * All comparison operators are overloaded.
 * << is overloaded.
 * */
class Person {
  private:
    Identity self;
    Identity father;
    Identity mother;
    bool marked;

  public:
    /**
     * Constructs the Person with the specified parameters.
     * */
    Person(const Identity &self, const Identity &father, const Identity &mother)
        : self(self), father(father), mother(mother), marked(false) {}

    /**
     * Create a person without specifying any parents.
     * */
    Person(const Identity &self) : self(self), marked(false) {}

    /**
     * Returns a constant reference to the father of this Person.
     * */
    const Identity &getFather() const {
        return father;
    }

    /**
     * Returns a constant reference to the mother of this Person.
     * */
    const Identity &getMother() const {
        return mother;
    }

    /**
     * Returns true if this person is the parent of the other person.
     * */
    bool isParentOf(const Person &other) const {
        return isFatherOf(other) || isMotherOf(other);
    }

    /**
     * Sets the member variable 'marked' to true.
     * */
    void mark() {
        marked = true;
    }

    /**
     * Returns true if member variable 'marked' has been set to true.
     * */
    bool isMarked() const {
        return marked;
    }

    // ---------- comparison operators -------------

    bool operator==(const Person &other) const {
        return self == other.self;
    }

    bool operator!=(const Person &other) const {
        return self != other.self;
    }

    bool operator<(const Person &other) const {
        return self < other.self;
    }

    bool operator>(const Person &other) const {
        return self > other.self;
    }

    bool operator<=(const Person &other) const {
        return self <= other.self;
    }

    bool operator>=(const Person &other) const {
        return self >= other.self;
    }

  private:
    /**
     * Returns true if this person is the father of the other person.
     * */
    bool isFatherOf(const Person &other) const {
        return self == other.father;
    }

    /**
     * Returns true if this person is the mother of the other person.
     * */
    bool isMotherOf(const Person &other) const {
        return self == other.mother;
    }

    friend std::ostream &operator<<(std::ostream &stream, const Person &person);
};

inline std::ostream &operator<<(std::ostream &stream, const Person &person) {
    return stream << person.self;
}

#endif
