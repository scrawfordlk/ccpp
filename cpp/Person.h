#ifndef PERSON_CLASS_H
#define PERSON_CLASS_H

#include "Identity.h"
#include <iostream>
#include <memory>

/**
 * Class that stores the identification of the person, their father and mother.
 * Each Person can be set to be marked.
 * All comparison operators are overloaded.
 * << is overloaded.
 * */
class Person {
  private:
    Identity self;
    Identity fatherId;
    Identity motherId;
    std::shared_ptr<Person> father;
    std::shared_ptr<Person> mother;
    bool marked;

  public:
    /**
     * Constructs the Person with the specified parameters.
     * */
    Person(const Identity &self, const Identity &father, const Identity &mother)
        : self(self), fatherId(father), motherId(mother), marked(false) {}

    /**
     * Create a person without specifying any parents.
     * */
    Person(const Identity &self) : self(self), marked(false) {}

    /*
     * Returns reference to the id of the father of this Person
     **/
    Identity &getFatherId() {
        return fatherId;
    }

    /*
     * Returns reference to the id of the mother of this Person
     **/
    Identity &getMotherId() {
        return motherId;
    }

    /**
     * Sets a pointer to the father
     **/
    void setFather(std::shared_ptr<Person> person) {
        father = person;
    }

    /**
     * Sets a pointer to the mother
     **/
    void setMother(std::shared_ptr<Person> person) {
        mother = person;
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

    /**
     * Returns true if member variable 'marked' has been set to true for a parent
     * */
    bool parentIsMarked() const;

    /**
     * Returns true if the id corresponds to the id of this Person
     */
    bool isId(const Identity &identity) {
        return self == identity;
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

    friend std::ostream &operator<<(std::ostream &stream, const Person &person);
};

inline std::ostream &operator<<(std::ostream &stream, const Person &person) {
    return stream << person.self;
}

#endif
