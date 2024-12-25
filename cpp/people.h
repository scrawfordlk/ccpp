#include "Person.h"
#include <memory>
#include <vector>

/**
 * returns unique_ptr to a sorted vector of unique_ptr's to all the Person's in the specified file
 * */
std::unique_ptr<std::vector<std::unique_ptr<Person>>> readPeople(const char *fileName);
