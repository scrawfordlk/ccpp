#include <iostream>
#include <memory>
#include <string>

using std::ostream;
using std::string;
using std::unique_ptr, std::make_unique;

class Identity {
  private:
    unique_ptr<string> firstName;
    unique_ptr<string> lastName;
    unique_ptr<string> birthyear;

  public:
    Identity(const char *firstName, const char *lastName, const char *birthyear)
        : firstName(make_unique<string>(firstName)), lastName(make_unique<string>(lastName)),
          birthyear(make_unique<string>(birthyear)) {}

    /*
     * ----------- overloaded operators ---------------
     */

    bool operator==(const Identity &other) const {
        return compareTo(other) == 0;
    }

    bool operator!=(const Identity &other) const {
        return compareTo(other) != 0;
    }

    bool operator<(const Identity &other) const {
        return compareTo(other) < 0;
    }

    bool operator>(const Identity &other) const {
        return compareTo(other) > 0;
    }

    bool operator<=(const Identity &other) const {
        return compareTo(other) <= 0;
    }

    bool operator>=(const Identity &other) const {
        return compareTo(other) >= 0;
    }

  private:
    int compareTo(const Identity &other) const {
        if (*birthyear != *other.birthyear) {
            return birthyear->compare(*other.birthyear);
        }

        if (*lastName != *other.lastName) {
            return lastName->compare(*other.birthyear);
        }

        return firstName->compare(*other.firstName);
    }

    friend ostream &operator<<(ostream &stream, const Identity &identity);
};

ostream &operator<<(ostream &stream, const Identity &identity) {
    return stream << *identity.firstName << " " << *identity.lastName << " " << *identity.birthyear;
}
