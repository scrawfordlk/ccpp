#ifndef PEOPLE_H
#define PEOPLE_H

#include "People.h"
#include "Person.h"
#include <memory>
#include <vector>

// Das ist komisch.  Wieso nochmal ein people.h/c mit kleinem Anfangsbuchstaben?  Diese zwei Funktionen wäre besser als Methoden von People aufgehoben.  Rade

/**
 * Returns a unique_ptr to a People object which is based off of the specified file.
 * */
std::unique_ptr<People> readPeople(const std::string &fileName);

/**
 * (Over)Writes the contents of the People object into the specified file.
 * */
void writePeople(const People &people, const std::string &fileName);

#endif
