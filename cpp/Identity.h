#ifndef IDENTITY
#define IDENTITY

#include <iostream>
#include <memory>
#include <string>

class Identity {
  private:
    std::unique_ptr<std::string> firstName;
    std::unique_ptr<std::string> lastName;
    std::unique_ptr<std::string> birthyear;

  public:
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
    int compareTo(const Identity &other) const;

    friend std::ostream &operator<<(std::ostream &stream, const Identity &identity);
};

std::ostream &operator<<(std::ostream &stream, const Identity &identity);

#endif
