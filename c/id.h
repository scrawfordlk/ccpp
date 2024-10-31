#ifndef ID_H
#define ID_H

/**
 * unique identification for a Person
 */
typedef struct Id {
    char *firstName;
    char *lastName;
    char *birthday;
} Id;

Id *newId(char *firstName, char *lastName, char *birthday);
void freeId(Id *id);

#endif
