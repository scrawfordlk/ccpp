#ifndef IDENTITY
#define IDENTITY

#include <iostream>
#include <memory>
#include <string>

/**
 * Class that stores the first name, last name and birthyear of a Person, which in combination are
 * uniquely identifiable. All comparison operators are overloaded.
 * << is also overloaded.
 * */
class Identity {
  private:
    std::unique_ptr<std::string> firstName;
    std::unique_ptr<std::string> lastName;
    std::unique_ptr<std::string> birthyear;

  public:
    /**
     * Constructs an Identity object with the specified first name, last name and birthyear.
     * */
    Identity(std::unique_ptr<std::string> firstName, std::unique_ptr<std::string> lastName,
             std::unique_ptr<std::string> birthyear);

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
