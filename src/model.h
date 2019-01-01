#ifndef GAME_OF_STOOLS_MODEL_H
#define GAME_OF_STOOLS_MODEL_H

/* LIBRARY */

#include <stdio.h>
#include <stdlib.h>
#include "utils.h"

/* CONSTANTS */

#define COLS 8
#define ROWS 6

#define RED 'R'
#define BLUE 'B'
#define FREE '\0'

#define VILLAGER 'V'
#define BARON 'B'
#define WARRIOR 'W'
#define CASTLE 'C'

#define TIME_VILLAGER 2
#define TIME_WARRIOR 4
#define TIME_BARON 6
#define TIME_CASTLE 1

#define COST_VILLAGER 1
#define COST_WARRIOR 5
#define COST_BARON 10
#define COST_CASTLE 30

#define INIT_TEASURE 50

// List of commands
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
    AList current; /* Current player */
} World;

/* GLOBAL VARIABLES */

extern World g_world;

/* API */

// Init the world
void initWorld();

// Init the board
void initBoard();

// Init agent with clan, type and position
void initAgent(Agent *agent, char clan, char type, Vector2 pos);

// Create a clan at position
AList createClan(char clan, Vector2 pos);

// Create a castle at position
AList createCastle(char clan, Vector2 pos);

// Add one agent to the list of agent
void addAgent(AList aList, char clan, char type);

// Remove agent in the list of agent or all list if agent is a castle
void removeAgent(AList aList, Agent *agent);

// Add an agent to the board
void addAgentOnBoard(Agent *agent);

// Remove an agent on board
void removeAgentOnBoard(Agent *agent);

// Get a free position (no agent) next to the position (up, left, down, right)
Vector2 getFreeNextPos(Vector2 pos);

// Check if the destination can be reached by an agent
bool canMove(Vector2 dest);

// Check if the cell at position is free (no agent)
bool isFreeCell(Vector2 pos);

// Check if a position is on the board
bool isOnBoard(Vector2 pos);

// Counts the number of agents (by type) in an agent list
int countAgentInList(AList aList, char type);

// Set a random list from the different players
void  setRandomPlayer();

// Set the opposite list of player in order to switch turn
void switchTurn();

// Get the winner
AList getWinnner();

// Check if the game is ended
bool isEndGame();

// Update turn count
void updateTurn(int count);

// Get treasure clan
int getTreasure(char clan);

// Spend treasure clan with cost
void spendTreasure(int cost, char clan);

// Update turn count
int getAgentTimeBuild(char type);

// Get the cost of an agent
int getAgentCost(char type);

// Check if a castle can build an agent type
bool canBuild(Agent *castle, char type);

// Build an agent type into castle
void buildAgent(Agent *castle, char type);

// Update build from current player list
void updateBuild(AList aList);

// Check if there is enough space to build around the position
bool hasAvailableSpaceToBuild(Vector2 pos);

// Move an agent
void moveAgent(Agent *agent);

// Get the correct direction to move agent properly
Vector2 getDirectionOnMove(Agent *agent);

// Claim cell by warrior
void claim(Agent *agent);

// Check if an agent has a destination
bool hasDestination(Agent *agent);

//TODO:
//void wait(Cell cell, Agent *agent);
//void setDestination(Agent *agent);
//void claim(Cell cell, Agent *agent);
//void recolt(Cell cell, Agent *agent);
//void takeUpArms(Cell cell, Agent *agent);
//void buildCastle(Cell cell, AList aList, char clan);
//void delete(Cell cell, AList aList, Agent *agent);
//void endTurn();
//void endGame();

#endif //GAME_OF_STOOLS_MODEL_H
