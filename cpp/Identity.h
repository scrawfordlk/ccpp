#ifndef IDENTITY
#define IDENTITY

#include <memory>

using std::ostream;
using std::string;
using std::unique_ptr;

class Identity {
  private:
    unique_ptr<string> firstName;
    unique_ptr<string> lastName;
    unique_ptr<string> birthyear;

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

    friend ostream &operator<<(ostream &stream, const Identity &identity);
};

ostream &operator<<(ostream &stream, const Identity &identity);

#endif
