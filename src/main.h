#ifndef GAME_OF_STOOLS_MAIN_H
#define GAME_OF_STOOLS_MAIN_H

/* LIBRARY */

#include <MLV/MLV_all.h>
//#include <stdio.h>
//#include <stdlib.h>
//#include <string.h>
//#include <math.h>

/* CONSTANTS */

typedef int bool

#define TRUE 1
#define FALSE 0

#define COLS 18
#define ROWS 12

#define RED 'R'
#define BLUE 'B'
#define FREE '-'

#define VILLAGER 'm'
#define BARON 'b'
#define WARRIOR 'g'
#define CASTLE 'c'

#define TIME_VILLAGER 2
#define TIME_WARRIOR 4
#define TIME_BARON 6

#define COST_VILLAGER 1
#define COST_WARRIOR 5
#define COST_BARON 10
#define COST_CASTLE 30

/* STRUCTURE */

typedef struct Vector2 {
    int x;
    int y;
};

typedef struct Agent {
    char clan; /* RED ou BLUE */
    char type; /* BARON, VILLAGER, WARRIOR, CASTLE */
    char product; /* production actuelle d'un chateau*/
    int time; /* tours restant pour cette production */
    Vector2 pos; /* position actuelle */
    Vector2 dest; /* destination (negatif pour manant immobile) */
    struct Agent *nextAgent, *prevAgent; /* liste des agents liees a un chateau */
    struct Agent *nextNeighbor, *prevNeighbor; /* liste des voisins */
} Agent, *AList;

typedef struct {
    Agent *castle; /* s'il y a un chateau sur la case */
    AList inhabitants; /* les autres occupants */
    char clan;/* couleur du clan ayant revendique*/
} Cell;

typedef struct {
    Cell board[ROWS][COLS];
    AList red, blue;
    int turn; /* Numero du tour */
    int redTreasure, blueTreasure;
} World;

/* API */

//TODO

#endif //GAME_OF_STOOLS_MAIN_H
