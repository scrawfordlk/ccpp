#ifndef PEOPLE_H
#define PEOPLE_H

#include "People.h"
#include "Person.h"
#include <memory>
#include <vector>

/**
 * Returns unique_ptr to a sorted vector of unique_ptr's to all the Person's in the specified file.
 * */
std::unique_ptr<People> readPeople(std::string &fileName);

#endif
