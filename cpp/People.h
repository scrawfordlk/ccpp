#ifndef PEOPLE_CLASS_H
#define PEOPLE_CLASS_H

#include "Person.h"
#include <memory>
#include <vector>

class People {
  private:
    std::vector<std::shared_ptr<Person>> people;

  public:
    /**
     * Creates a new empty People collection.
     * */
    People();

    /**
     * Creates a new People collection with all Person's who are marked in the other people.
     * */
    People(People &people);

    /**
     * Adds another Person to the People collection.
     * */
    void push(std::shared_ptr<Person> person);

    /**
     * Removes the last Person in the People collection. (In most cases the last Person added)
     * */
    void pop();

    /**
     * Sorts the People collection.
     * */
    void sort();

    friend std::ostream &operator<<(std::ostream &stream, const People &people);
};

/**
 * Prints each Person seperated with a newline.
 * */
std::ostream &operator<<(std::ostream &stream, const People &people);

#endif
