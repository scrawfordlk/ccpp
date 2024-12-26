#ifndef PERSON
#define PERSON

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
    Identity *father;
    Identity *mother;
    bool marked;

  public:
    /**
     * Person with both father and mother.
     * */
    Person(const Identity &self, const Identity &father, const Identity &mother);

    /*
     * Person with no known parents.
     * */
    Person(const Identity &self);

    // --------------- methods -----------------

    /**
     * Returns true if this Person is the child of the given reference to another person, otherwise
     * returns false.
     * */
    bool isChildOf(const Person &person) const;

    /**
     * Returns true if this person is a parent of the other person, otherwise returns false
     * */
    bool isParentOf(const Person &person) const;

    /**
     * Sets the member variable 'marked' to true.
     * */
    void mark();

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
