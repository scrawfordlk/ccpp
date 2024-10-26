/**
 * file that manages everything relating to the person struct
 */

typedef struct Name {
    char *firstName;
    char *lastName;
} Name;

/**
 * defines a Person struct which contains the Name (first and last), birthday and pointers to their
 * parents
 */
typedef struct Person {
    Name *name;
    char *birthday;
    struct Person *father;
    struct Person *mother;
} Person;

/**
 * struct that stores an array of Person (i.e. People). memory allocation is done by
 * malloc(sizeof(People) + sizeof(Person) * len) due to flexible array member
 */
typedef struct People {
    int len;
    Person *list;
} People;

/**
 * returns a pointer to a People structure of all people in the given file
 */
People *readPeople(char *fileName) {
    return 0;
}

/**
 * receives pointer to sorted People struct, the unique identification of a Person (first name, last
 * name and birthday) and returns a pointer to this person. Returns NULL, if this Person doesn't
 * exist
 */
Person *getPerson(People *people, char *firstName, char *lastName, char *birthday) {
    return 0;
}

/*
 * sorts the People struct that people points to
 */
void sortPeople(People *people) {}

/**
 * compares a Person A to a Person B and returns -1, 0 or 1 if Person A is smaller, equal or larger
 * than Person B
 * where a Person is sorted according to (in order) their birthday, last name, first name
 */
int comparePerson(Person *personA, Person *personB) {
    return 0;
}

/**
 * swaps pointers of two different Person structs
 */
void swapPerson(Person **personA, Person **personB) {}
