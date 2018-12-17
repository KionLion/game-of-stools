#ifndef GAME_OF_STOOLS_GAME_H
#define GAME_OF_STOOLS_GAME_H

/* LIBRARY */

#include <stdio.h>
#include <stdlib.h>
#include "utils.h"

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

#define MAX_MOVE 1;

#define INIT_TEASURE 50

#define CMD_VOID 0
#define CMD_QUIT -1
#define CMD_END_TURN 1
#define CMD_SAVE 2
#define CMD_LOAD 3
#define CMD_AGENT_NEW_DEST 10
#define CMD_AGENT_REMOVE 11
#define CMD_CASTLE_BUILD_BARON 20
#define CMD_CASTLE_BUILD_WARRIOR 21
#define CMD_CASTLE_BUILD_VILLAGER 22
#define CMD_BARON_BUILD_CASTLE 30
#define CMD_WARRIOR_CLAIM 40
#define CMD_VILLAGER_COLLECT 50
#define CMD_VILLAGER_TAKE_UP_ARMS 51

/* STRUCTURE */

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
bool isCastle(Agent *agent);
bool hasDestination(Agent *agent);
Vector2 getFreeNextPos(Vector2 pos);
bool canMove(Vector2 dest);
bool isFreeCell(Vector2 pos);
bool isOnBoard(Vector2 pos);
int countAgentInList(AList aList, char type);

AList getRandomColor();
AList switchTurn(AList current);
AList getWinnner();
bool isEndGame(int cmd);
void updateTurn(int count);

void wait(Cell cell, Agent *agent);
void setDestination(Agent *agent);
void claim(Cell cell, Agent *agent);
void recolt(Cell cell, Agent *agent);
void takeUpArms(Cell cell, Agent *agent);
void buildCastle(Cell cell, AList aList, char clan);
void product(Cell cell, AList aList, char clan, char type);
void delete(Cell cell, AList aList, Agent *agent);
void endTurn();
void endGame();

//TODO: Axel - Production (game files)
//TODO: Axel - Move (game files)

#endif //GAME_OF_STOOLS_GAME_H
