#ifndef PERSON
#define PERSON

#include "Identity.h"
#include <memory>

using std::ostream;
using std::unique_ptr;

class Person {
  private:
    unique_ptr<Identity> self;
    unique_ptr<Identity> father;
    unique_ptr<Identity> mother;
    bool marked;

  public:
    // ------------ constructors ----------------

    Person(unique_ptr<Identity> self, unique_ptr<Identity> father, unique_ptr<Identity> mother);

    /*
     * if this Person has no known parents
     * */
    Person(unique_ptr<Identity> self);

    // --------------- methods -----------------

    bool isChildOf(const Person &person) const;
    bool isParentOf(const Person &person) const;
    void setMark();

    // ---------- overloaded operators -------------

    bool operator==(const Person &other) const;
    bool operator!=(const Person &other) const;
    bool operator<(const Person &other) const;
    bool operator>(const Person &other) const;
    bool operator<=(const Person &other) const;
    bool operator>=(const Person &other) const;

    friend ostream &operator<<(ostream &stream, Person &person);
};

ostream &operator<<(ostream &stream, Person &person);

#endif
