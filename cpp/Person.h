#ifndef PERSON_H
#define PERSON_H

#include "Identity.h"
#include <iostream>
#include <memory>

/**
 * Class that stores the identification of the person, their father and mother.
 * Also contains a member variable 'marked' that can be set to be marked.
 * All comparison operators are overloaded.
 * */
class Person {
  private:
    Identity self;
    Identity father;
    Identity mother;
    bool marked;
    bool hasKnownParents;

  public:
    /**
     * Person with both father and mother.
     * */
    Person(const Identity &self, const Identity &father, const Identity &mother);

    /*
     * Person with no known parents.
     * */
    Person(const Identity &self);

    /**
     * Returns a weak_ptr to the Identity of the father.
     * If there is no father, then a default weak_ptr
     * */
    const Identity *getFather() const;

    /**
     * Returns a weak_ptr to the Identity of the mother.
     * If there is no mother, then a default weak_ptr.
     * */
    const Identity *getMother() const;

    /**
     * Sets the member variable 'marked' to true.
     * */
    void mark();

    /**
     * Sets the member variable 'marked' to false.
     * */
    void removeMark();

    /**
     * Returns true if member variable 'marked' has been set to true.
     * */
    bool isMarked() const;

    // ---------- overloaded operators -------------

    bool operator==(const Person &other) const;
    bool operator!=(const Person &other) const;
    bool operator<(const Person &other) const;
    bool operator>(const Person &other) const;
    bool operator<=(const Person &other) const;
    bool operator>=(const Person &other) const;

    friend std::ostream &operator<<(std::ostream &stream, const Person &person);
};

std::ostream &operator<<(std::ostream &stream, const Person &person);

#endif
