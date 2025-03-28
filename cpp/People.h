#ifndef PEOPLE_CLASS_H
#define PEOPLE_CLASS_H

#include "Person.h"
#include <fstream>
#include <memory>
#include <vector>

/**
 * Class that stores a collection of Person objects.
 * << is overloaded.
 * */
class People {
  private:
    std::vector<std::shared_ptr<Person>> people;

  public:
    /**
     * Constructs an empty People collection.
     * */
    People() : people(std::vector<std::shared_ptr<Person>>()) {
        people.reserve(32);
    }

    /**
     * Adds the specified Person to the People collection.
     * */
    void push(std::shared_ptr<Person> person) {
        people.push_back(person);
    }

    /**
     * Removes the last Person in the People collection. (In most cases the last Person added)
     * */
    void pop() {
        if (people.size() >= 1) {
            people.pop_back();
        }
    }

    /**
     * Sorts the People collection.
     * */
    void sort();

    /**
     * Returns all relatives of the specified person in this People collection.
     * Side effect: sorts the People collection
     * */
    std::unique_ptr<People> getRelatives(const std::string &firstName, const std::string &lastName,
                                         const std::string &birthyear);

    /**
     * Adds all people in the specified file to this People collection
     * */
    void readFile(const std::string &fileName);

    /**
     * (Over)Writes the file with the contents of the People object.
     * */
    void writeFile(const std::string &fileName) const {
        auto file = std::ofstream(fileName);
        file << *this;
        file.close();
    }

  private:
    /**
     * Assumes that this collection is sorted
     *
     * Tries to find a Person via an Identity. If the Person exists, then a shared_ptr to that
     * Person is returned. Otherwise returns a nullptr.
     * */
    std::shared_ptr<Person> findPerson(const Identity &identity);

    /**
     * Finds and assigns pointers to parents for each Person.
     **/
    void assignParents();

    /**
     * Marks ancestors of specified person.
     * */
    void markAncestors(const Person &person);

    /**
     * Marks all descendants of marked people.
     * */
    void markDescendants();

    /**
     * Returns a unique_ptr to a new People collection with all marked people.
     * */
    std::unique_ptr<People> extractMarkedPeople() const;

    friend std::ostream &operator<<(std::ostream &stream, const People &people);
};

/**
 * Prints each Person seperated with a newline.
 * */
std::ostream &operator<<(std::ostream &stream, const People &people);

#endif
