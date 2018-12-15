#ifndef GAME_OF_STOOLS_GAME_H
#define GAME_OF_STOOLS_GAME_H

/* LIBRARY */

#include <stdio.h>
#include <stdlib.h>

/* CONSTANTS */

typedef int bool;

#define TRUE 1
#define FALSE 0

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

#define MAX_MOVE 1;

#define INIT_TEASURE 50

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
    Agent *inhabitants; /* les autres occupants */
    char clan; /* RED ou BLUE */
} Cell;

typedef struct {
    Cell board[ROWS][COLS];
    AList red, blue;
    int turn; /* Numero du tour */
    int redTreasure, blueTreasure;
} World;

/* GLOBAL VARIABLES */

extern World g_world;

/* API */

void initWorld();
void initBoard();
void initAgent(Agent *agent, char clan, char type, Vector2 pos);
AList createClan(char clan, Vector2 pos);
AList createCastle(char clan, Vector2 pos);
void addAgent(AList aList, char clan, char type);
void setAgentOnBoard(Agent *agent);
void moveAgent(Agent *agent);
bool hasDestination(Agent *agent);
Vector2 getFreeNextPos(Vector2 pos);
bool canMove(Vector2 dest);
bool isFreeCell(Vector2 pos);
bool isOnBoard(Vector2 pos);
int getDistance(Vector2 pos, Vector2 dest);
int countAgentInList(AList aList, char type);

/* ----- ORDERS ----- */

void wait(Cell cell, Agent *agent);
void setDestination(Agent *agent);
void claim(Cell cell, Agent *agent);
void recolt(Cell cell, Agent *agent);
void takeUpArms(Cell cell, Agent *agent);
void buildCastle(Cell cell, AList aList, char clan);
void product(Cell cell, AList aList, char clan, char type);
void delete(Cell cell, AList aList, Agent *agent);

//TODO: Axel - Production (game files)
//TODO: Axel - Move (game files)

//TODO: Mohamed : Turn managment + random (game files)

#endif //GAME_OF_STOOLS_GAME_H
