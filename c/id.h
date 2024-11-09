#ifndef ID_H
#define ID_H

/**
 * unique identification for a Person
 */
typedef struct Id {
    char firstName[21];
    char lastName[21];
    char birthyear[5];
} Id;

Id *newId(char *firstName, char *lastName, char *birthyear);

#endif
