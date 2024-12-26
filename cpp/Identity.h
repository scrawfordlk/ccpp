#ifndef IDENTITY_H
#define IDENTITY_H

#include <iostream>
#include <string>

/**
 * Class that stores the first name, last name and birthyear of a Person, which in combination are
 * uniquely identifiable. All comparison operators are overloaded.
 * << is also overloaded.
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
             const std::string &birthyear);

    /*
     * ----------- overloaded operators ---------------
     */
    bool operator==(const Identity &other) const;
    bool operator!=(const Identity &other) const;
    bool operator<(const Identity &other) const;
    bool operator>(const Identity &other) const;
    bool operator<=(const Identity &other) const;
    bool operator>=(const Identity &other) const;

  private:
    /**
     * Returns an integer <, =, > 0 if this Identity is smaller, equal, larger than the other
     * Identity
     * Ordering is as follows: birthyear, lastName, firstName
     * */
    int compareTo(const Identity &other) const;

    friend std::ostream &operator<<(std::ostream &stream, const Identity &identity);
};

std::ostream &operator<<(std::ostream &stream, const Identity &identity);

#endif
