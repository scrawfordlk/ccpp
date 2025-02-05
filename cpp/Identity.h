#ifndef IDENTITY_CLASS_H
#define IDENTITY_CLASS_H

#include <iostream>
#include <string>

/**
 * Class that stores the first name, last name and birthyear of a Person, which in combination are
 * uniquely identifiable.
 * All comparison operators are overloaded.
 * << is overloaded.
 * */
class Identity {
  private:
    std::string firstName;
    std::string lastName;
    std::string birthyear;

  public:
    /**
     * Constructs an Identity object with the specified first name, last name and birthyear.
     * */
    Identity(const std::string &firstName, const std::string &lastName,
             const std::string &birthyear)
        : firstName(firstName), lastName(lastName), birthyear(birthyear) {}

    /**
     * Default constructor for an invalid Identity.
     * */
    Identity() {}

    /*
     * ----------- comparison operators ---------------
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
    /**
     * Returns an integer <, =, > 0 if this Identity is smaller, equal, larger than the other
     * Identity
     * Ordering is as follows: birthyear, lastName, firstName
     * */
    int compareTo(const Identity &other) const;

    friend std::ostream &operator<<(std::ostream &stream, const Identity &identity);
};

inline std::ostream &operator<<(std::ostream &stream, const Identity &identity) {
    return stream << identity.firstName << " " << identity.lastName << " " << identity.birthyear;
}

#endif
