#ifndef GAME_OF_STOOLS_MODEL_H
#define GAME_OF_STOOLS_MODEL_H

/* LIBRARY */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "utils.h"

/* CONSTANTS */

#define COLS 18
#define ROWS 12

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
#define TIME_CASTLE 0

#define COST_VILLAGER 1
#define COST_WARRIOR 5
#define COST_BARON 20
#define COST_CASTLE 30

#define INIT_RED_POS (Vector2){0, 0}
#define INIT_BLUE_POS (Vector2){COLS - 1, ROWS - 1}
#define INIT_CLAN "BV"
#define INIT_TEASURE 50

#define VILLAGER_COLLECT_VALUE 1

#define EXT_SAVE_FILE ".txt"
#define FREE_CHAR_IN_FILE '-'

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
AList createClan(char clan, Vector2 pos, char *agents);

// Add one agent to the list using nextAgent
Agent *addAgent(AList aList, char clan, char type, Vector2 pos);

// Add one castle to the list using nextNeighbor
Agent *addCastle(AList aList, char clan, Vector2 pos);

// Remove an agent from list and board
void removeAgent(Agent *agent);

// Remove castle and all agents that belong to him and change loyalty to another castle (conqueror)
void removeCastle(Agent *agent, Agent *conqueror);

// Add an agent to the board
void addAgentOnBoard(Agent *agent);

// Remove an agent on board
void removeAgentOnBoard(Agent *agent);

// Get a free position (no agent) next to the position (up, left, down, right)
Vector2 getFreeNextPos(Vector2 pos);

// Check if the destination can be reached by an agent
bool canMove(Vector2 pos, char type);

// Check if the cell at pos there are enemies (castle or agent)
bool isEnemy(Vector2 pos);

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

// Update build of an agent from castle list
void updateBuild(Agent *castle, Agent *agent);

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

// Check if the agent can collect
bool canCollect(Agent *agent);

// Collect resource by villager
void collect(Agent *agent);

// Switch villager to warrior
void takeUpArms(Agent *agent);

// Save by filename
void save(char *filename);

// Append agent data to data array
void appendAgentData(AList aList, char data[]);

// Append board to data array
void appendBoardData(char data[]);

//Load by filename
void load(char *filename);

// Initialize cell from data
void loadBoardFromData(char *data);

// Initialize agents from data
void loadAgentFromData(char **data, int i);

// Get the last agent of the list of agent
Agent *getAgentListTail(AList aList);

// Get the last castle of the list of castle
Agent *getCastleListTail(AList aList);

// Change loyalty to another castle
void changeLoyaltyToCastle(Agent *castle, Agent *agent);

// get the loyalty castle of an agent
Agent *getCastleLoyalty(Agent *agent);

// Handle battle
void battle(Agent *conqueror, Vector2 pos);

// Check if an agent was freed
bool isAgentFreed(Agent *agent);

#endif //GAME_OF_STOOLS_MODEL_H
