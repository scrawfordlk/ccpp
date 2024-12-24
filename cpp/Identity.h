#ifndef IDENTITY
#define IDENTITY

#include <memory>

class Identity {
  private:
    std::unique_ptr<std::string> firstName;
    std::unique_ptr<std::string> lastName;
    std::unique_ptr<std::string> birthyear;

  public:
    Identity(const char *firstName, const char *lastName, const char *birthyear);

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
