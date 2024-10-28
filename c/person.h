/**
 * unique identification for a Person
 */
typedef struct Id {
    char *firstName;
    char *lastName;
    char *birthday;
} Id;

/**
 * defines a Person struct that stores its Id (= first name, last name and birthday) as well as the
 * id's of their father/mother
 */
typedef struct Person {
    Id *id;
    Id *fatherId;
    Id *motherId;
} Person;

Id *newId(char *firstName, char *lastName, char *birthday);
Person *newPerson(Id *id, Id *fatherId, Id *motherId);
static int comparePerson(Person *personA, Person *personB);
static void swapPerson(People *people, int i, int j);
