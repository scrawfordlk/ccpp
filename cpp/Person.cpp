#include "Identity.cpp"
#include <memory>
#include <ostream>

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

    Person(unique_ptr<Identity> self, unique_ptr<Identity> father, unique_ptr<Identity> mother)
        : self(std::move(self)), father(std::move(father)), mother(std::move(mother)),
          marked(false) {}

    /*
     * if this Person has no known parents
     * */
    Person(unique_ptr<Identity> self) : self(std::move(self)) {
        this->father = nullptr;
        this->mother = nullptr;
        this->marked = false;
    }

    // --------------- methods -----------------

    bool isChildOf(const Person &person) const {
        return (father != nullptr && *father == *person.self) ||
               (mother != nullptr && *mother == *person.self);
    }

    bool isParentOf(const Person &person) const {
        return (person.father != nullptr && *person.father == *self) ||
               (person.mother != nullptr && *person.mother == *self);
    }

    void setMark() {
        marked = true;
    }

    // ---------- overloaded operators -------------

    bool operator==(const Person &other) const {
        return *self == *other.self;
    }

    bool operator!=(const Person &other) const {
        return *self != *other.self;
    }

    bool operator<(const Person &other) const {
        return *self < *other.self;
    }

    bool operator>(const Person &other) const {
        return *self > *other.self;
    }

    bool operator<=(const Person &other) const {
        return *self <= *other.self;
    }

    bool operator>=(const Person &other) const {
        return *self >= *other.self;
    }

    friend ostream &operator<<(ostream &stream, Person &person);
};

ostream &operator<<(ostream &stream, Person &person) {
    return stream << *person.self;
}
