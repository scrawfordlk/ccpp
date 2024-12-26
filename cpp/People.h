#ifndef PEOPLE_H
#define PEOPLE_H

#include "Person.h"
#include <algorithm>
#include <memory>
#include <ostream>
#include <string>
#include <vector>

class People {
  private:
    std::vector<std::shared_ptr<Person>> people;

  public:
    /**
     * Creates a new empty People object
     * */
    People();

    /**
     * Returns the number of Person's in this People collection.
     * */
    int size() const;

    /**
     * Inserts the given person into the end of the People collection.
     * */
    void push(std::shared_ptr<Person> person);

    /**
     * Sorts this People collection by birthyear, last name, first name
     * */
    void sort();

    /**
     * Returns new People collection with all relatives of the specified person.
     * */
    std::unique_ptr<People> getRelatives(std::string &firstName, std::string &lastName,
                                         std::string &birthyear);

  private:
    /**
     * Returns a unique_ptr to a new People collection of all Person's who are marked.
     * */
    std::unique_ptr<People> extractMarkedPeople() const;

    /**
     * Undos the marks of all marked Person's.
     * */
    void unmarkAll();

    friend std::ostream &operator<<(std::ostream &stream, const People &people);
};

std::ostream &operator<<(std::ostream &stream, const People &people);
#endif
