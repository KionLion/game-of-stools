#ifndef GAME_OF_STOOLS_UI_H
#define GAME_OF_STOOLS_UI_H

/* LIBRARY */

//#include <MLV/MLV_all.h>
#include <stdio.h>
#include "game.h"

/* CONSTANTS */


/* STRUCTURE */


/* API */

void showAgentList(AList aList);
void showAsciiBoard();
void showAsciiCell(Cell cell);
void showAgent(Agent *agent);
void showClanInfo(AList aList);
void showCommandAgent(AList aList, char type);
void showCommandCastle(Agent *agent);
void showCommandBaron(Agent *agent);
void showCommandWarrior(Agent *agent);
void showCommandVillager(Agent *agent);
int showCommandTurn();

#endif //GAME_OF_STOOLS_UI_H
