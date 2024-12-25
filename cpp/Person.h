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
    std::unique_ptr<Identity> self;
    std::unique_ptr<Identity> father;
    std::unique_ptr<Identity> mother;
    bool marked;

  public:
    // ------------ constructors ----------------

    /**
     * Person with both father and mother
     * */
    Person(std::unique_ptr<Identity> self, std::unique_ptr<Identity> father,
           std::unique_ptr<Identity> mother);

    /*
     * if this Person has no known parents
     * */
    Person(std::unique_ptr<Identity> self);

    // --------------- methods -----------------

    /**
     * returns true if this Person is the child of the given reference to another person
     * */
    bool isChildOf(const Person &person) const;

    /**
     * */
    bool isParentOf(const Person &person) const;
    void setMark();
    bool isMarked();

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
