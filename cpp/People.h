#ifndef PEOPLE_CLASS_H
#define PEOPLE_CLASS_H

#include "Person.h"
#include <memory>
#include <vector>

/**
 * Class that stores a collection of Person's.
 * << is overloaded.
 * */
class People {
  private:
    std::vector<std::shared_ptr<Person>> people;

  public:
    /**
     * Constructs an empty People collection.
     * */
    People();

    /**
     * Adds the specified Person to the People collection.
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
    std::unique_ptr<People> getRelatives(const std::string &firstName, const std::string &lastName,
                                         const std::string &birthyear);

  private:
    /**
     * Tries to find a Person via an Identity. If the Person exists, then a share_ptr to that Person
     * is returned. Otherwise returns a nullptr.
     * */
    std::shared_ptr<Person> findPerson(const Identity &identity);

    /**
     * Marks all relatives of the specified person.
     * */
    void markRelatives(std::shared_ptr<Person> person);

    /**
     * Marks all the children of the specified person.
     * */
    void markChildren(std::shared_ptr<Person> person);

    /**
     * Returns a unique_ptr to a new People collection with all marked People.
     * */
    std::unique_ptr<People> extractMarkedPeople() const;

    friend std::ostream &operator<<(std::ostream &stream, const People &people);
};

/**
 * Prints each Person seperated with a newline.
 * */
std::ostream &operator<<(std::ostream &stream, const People &people);

#endif
