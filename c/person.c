/**
 * file that manages everything relating to the person struct
 */

typedef struct Name {
    char *firstName;
    char *lastName;
} Name;

/**
 * defines a Person struct which contains the Name (first and last), birthday
 * and pointers to their parents
 */
typedef struct Person {
    Name *name;
    char *birthday;
    struct Person *father;
    struct Person *mother;
} Person;

/**
 * struct that stores an array of Person (i.e. People). memory allocation is
 * done by malloc(sizeof(People) + sizeof(Person) * len) due to flexible array
 * member
 */
typedef struct People {
    int len;
    Person *list;
} People;
