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
    Person(const Identity &self, const Identity &father, const Identity &mother);

    /**
     * Create a person without specifying any parents.
     * */
    Person(const Identity &self);

    /**
     * Returns a constant reference to the father of this Person.
     * */
    const Identity &getFather() const;

    /**
     * Returns a constant reference to the mother of this Person.
     * */
    const Identity &getMother() const;

    /**
     * Returns true if this person is the parent of the other person.
     * */
    bool isParentOf(const Person &other) const;

    /**
     * Sets the member variable 'marked' to true.
     * */
    void mark();

    /**
     * Returns true if member variable 'marked' has been set to true.
     * */
    bool isMarked() const;

    // ---------- comparison operators -------------

    bool operator==(const Person &other) const;
    bool operator!=(const Person &other) const;
    bool operator<(const Person &other) const;
    bool operator>(const Person &other) const;
    bool operator<=(const Person &other) const;
    bool operator>=(const Person &other) const;

  private:
    /**
     * Returns true if this person is the father of the other person.
     * */
    bool isFatherOf(const Person &other) const;

    /**
     * Returns true if this person is the mother of the other person.
     * */
    bool isMotherOf(const Person &other) const;

    friend std::ostream &operator<<(std::ostream &stream, const Person &person);
};

std::ostream &operator<<(std::ostream &stream, const Person &person);

#endif
