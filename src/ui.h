#ifndef GAME_OF_STOOLS_UI_H
#define GAME_OF_STOOLS_UI_H

/* LIBRARY */

//#include <MLV/MLV_all.h>
#include <stdio.h>
#include "model.h"

/* CONSTANTS */


/* STRUCTURE */


/* API */

// Show the board (row, col) in the terminal
void showAsciiBoard();

// Show the cell of the board in the terminal
void showAsciiCell(Cell cell);

// Show one agent in the terminal
void showAgent(Agent *agent);

// Show the clan info (turn, color and treasure) in the terminal
void showClanInfo(AList aList);

// Show the command of a castle in the terminal
void showCastleCommands(Agent *agent);

// Show the command of a baron in the terminal
void showBaronCommands(Agent *agent);

// Show the command of a warrior in the terminal
void showWarriorCommands(Agent *agent);

// Show the command of a villager in the terminal
void showVillagerCommands(Agent *agent);

// Show the command of at the end of turn in the terminal
int showTurnCommands();

#endif //GAME_OF_STOOLS_UI_H
