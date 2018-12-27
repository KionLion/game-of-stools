#ifndef GAME_OF_STOOLS_UTILS_H
#define GAME_OF_STOOLS_UTILS_H

/* LIBRARY */

#include <stdlib.h>
#include <stdio.h>
#include <time.h>

/* CONSTANTS */

typedef int bool;

#define TRUE 1
#define FALSE 0

/* STRUCTURE */

typedef struct {
    int x;
    int y;
} Vector2;

/* GLOBAL VARIABLES */


/* API */

// Generate a random boolean (0 or 1)
bool get_random_boolean();

// Generate a random integer between begin to end (included)
int get_random_integer(int begin, int end);

// Get distance between 2 vector
int get_distance(Vector2 pos, Vector2 dest);

// Get the sign of a number (positive = 1, negative = -1, null = 0)
int get_sign(int x);

// Ask to user a string entry with max length
void set_user_entry(char *entry, int maxLength);

// Get a string user entry with max length from terminal
char *get_user_entry(int maxLength);

// Get an integer user entry from terminal
int get_user_entry_integer();

// Get an integer between interval user entry from terminal
// Retry if the number is not contains into interval
int get_user_entry_interval(int min, int max);

// Clean input / stdin
bool clean_stdin();

#endif //GAME_OF_STOOLS_UTILS_H
