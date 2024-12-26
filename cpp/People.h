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

    /**
     * Returns all relatives of the specified person in this People collection.
     * */
    std::unique_ptr<People> getRelatives(std::string &firstName, std::string &lastName,
                                         std::string &birthyear);

    std::shared_ptr<Person> findPerson(std::string &firstName, std::string &lastName,
                                       std::string &birthyear);

  private:
    /**
     * Finds and returns the (pointer to) person who is equal to the given person.
     * Returns nullptr if the person does not exist.
     * Side effect: People collection is going to be sorted.
     * */

    /**
     * Returns a unique_ptr to a new People collection with all People, who were marked
     * */
    std::unique_ptr<People> extractMarkedPeople() const;

    friend std::ostream &operator<<(std::ostream &stream, const People &people);
};

/**
 * Prints each Person seperated with a newline.
 * */
std::ostream &operator<<(std::ostream &stream, const People &people);

#endif
