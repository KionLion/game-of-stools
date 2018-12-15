#ifndef GAME_OF_STOOLS_UTILS_H
#define GAME_OF_STOOLS_UTILS_H

/* LIBRARY */

#include <stdlib.h>
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

#endif //GAME_OF_STOOLS_UTILS_H
