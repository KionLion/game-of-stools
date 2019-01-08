#ifndef GAME_OF_STOOLS_GAME_H
#define GAME_OF_STOOLS_GAME_H

/* LIBRARY */

#include <stdio.h>
#include <stdlib.h>
#include "model.h"
#include "ui.h"

/* CONSTANTS */


/* STRUCTURE */


/* GLOBAL VARIABLES */


/* API */

// Play game
void play();

// Handle all agents by castle
void handleAgents();

// Handle agent on browsing agent list by castle
void handleAgentByCastle(Agent *castle, char type);

// Handle agent commands
void handleAgentCommands(Agent *agent);

// Handle castle commands
void handleCastle(Agent *agent);

// Handle baron commands
void handleBaron(Agent *agent);

// Handle warrior commands
void handleWarrior(Agent *agent);

// Handle villager commands
void handleVillager(Agent *agent);

// Handle turn commands
void handleTurnCommands();

// Handle game
void handleGame();

#endif //GAME_OF_STOOLS_GAME_H
