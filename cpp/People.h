#ifndef PEOPLE_H
#define PEOPLE_H

#include "Person.h"
#include <memory>
#include <ostream>
#include <string>
#include <vector>

class People {
  private:
    std::unique_ptr<std::vector<std::shared_ptr<Person>>> people;

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
     * Returns a weak_ptr to the Person at the specified index, if the index is out of bounds
     * then a nullptr is returned
     * */
    std::weak_ptr<Person> at(int index) const;

    /**
     * Finds and returns a weak_ptr to the person matching the given arguments, if not found,
     * returns default constructed weak_ptr
     * */
    std::weak_ptr<Person> findPerson(std::string firstName, std::string lastName,
                                     std::string birthyear) const;

    /**
     * Sorts this People collection by birthyear, last name, first name
     * */
    void sort();

    /**
     * Returns new People collection with all relatives of the specified person
     * */
    std::unique_ptr<People> findRelatives(std::shared_ptr<Person> person);

    /**
     * Returns true if this person is contained in this people collection
     * */
    bool exists(std::shared_ptr<Person> person) const;

  private:
    /**
     * Gets a person in the People collection.
     * It is assumed that the person does exist.
     * */
    std::weak_ptr<Person> getPerson(std::shared_ptr<Person> person) const;

    /**
     * Marks all relatives of this person. It also sorts the collection as a side effect
     * */
    void markRelatives(std::shared_ptr<Person> person);

    /**
     * Returns a new Person collection with all Person's who are marked
     * */
    std::unique_ptr<People> extractMarked();

    friend std::ostream &operator<<(std::ostream &stream, const People &people);
};

std::ostream &operator<<(std::ostream &stream, const People &people);
#endif
