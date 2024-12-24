#ifndef PERSON
#define PERSON

#include "Identity.h"

class Person {
  private:
    std::unique_ptr<Identity> self;
    std::unique_ptr<Identity> father;
    std::unique_ptr<Identity> mother;
    bool marked;

  public:
    // ------------ constructors ----------------

    Person(std::unique_ptr<Identity> self, std::unique_ptr<Identity> father,
           std::unique_ptr<Identity> mother);

    /*
     * if this Person has no known parents
     * */
    Person(std::unique_ptr<Identity> self);

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

    friend std::ostream &operator<<(std::ostream &stream, Person &person);
};

std::ostream &operator<<(std::ostream &stream, Person &person);

#endif
