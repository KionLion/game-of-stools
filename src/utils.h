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

bool get_random_boolean();
int get_random_integer(int begin, int end);
int get_distance(Vector2 pos, Vector2 dest);
int get_sign(int x);
void set_user_entry(char *entry, int maxLength);
char *get_user_entry(int maxLength);
int get_user_entry_integer();
int get_user_entry_interval(int min, int max);
bool clean_stdin();

#endif //GAME_OF_STOOLS_UTILS_H
