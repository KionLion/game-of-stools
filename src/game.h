#ifndef MAIN_GAME_H
#define MAIN_GAME_H

/* LIBRARY */

//#include <MLV/MLV_all.h>
#include <stdio.h>
#include <stdlib.h>
//#include "ui.h"

/* CONSTANTS */

#define COLS 18
#define ROWS 12

#define RED 'R'
#define BLUE 'B'
#define FREE '\0'

#define VILLAGER 'M'
#define BARON 'B'
#define WARRIOR 'G'
#define CASTLE 'C'

#define TIME_VILLAGER 2
#define TIME_WARRIOR 4
#define TIME_BARON 6

#define COST_VILLAGER 1
#define COST_WARRIOR 5
#define COST_BARON 10
#define COST_CASTLE 30

#define INIT_TEASURE 50
//#define INIT_AGENT_LIST "cbm"

/* STRUCTURE */

typedef struct {
    int x;
    int y;
} Vector2;

typedef struct Agent Agent;

typedef struct Agent {
    char clan; /* RED ou BLUE */
    char type; /* BARON, VILLAGER, WARRIOR, CASTLE */
    char product; /* production actuelle d'un chateau*/
    int time; /* tours restant pour cette production */
    Vector2 pos; /* position actuelle */
    Vector2 dest; /* destination (negatif pour manant immobile) */
    Agent *nextAgent, *prevAgent; /* liste des agents liees a un chateau */
    Agent *nextNeighbor, *prevNeighbor; /* liste des voisins */
} *AList;

typedef struct {
    Agent *castle; /* s'il y a un chateau sur la case */
    AList inhabitants; /* les autres occupants */
    char clan; /* RED ou BLUE */
} Cell;

typedef struct {
    Cell board[ROWS][COLS];
    AList red, blue;
    int turn; /* Numero du tour */
    int redTreasure, blueTreasure;
} World;

/* API */

void init();
World createWorld();
void initBoard(Cell board[ROWS][COLS]);
void initAgentList(AList aList, Cell board[ROWS][COLS]);
void initAgent(Agent *agent, char clan, char type, Vector2 pos);
AList createClan(char clan, int x, int y);
AList createCastle(char clan, Vector2 pos);
void addAgent(AList aList, char clan, char type, Vector2 pos);

void showAgentList(AList aList);
void showAsciiBoard(Cell board[ROWS][COLS]);
void showAsciiCell(Cell cell);

//TODO: Axel - Init Cell inhabitant (game files)
//TODO: Axel - Production (game files)
//TODO: Axel - Move (game files)

//TODO: Mohamed : Turn managment + random (game files)

#endif //MAIN_GAME_H
