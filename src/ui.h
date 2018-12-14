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
void showAsciiBoard(Cell board[ROWS][COLS]);
void showAsciiCell(Cell cell);

//TODO: Mohamed : Choice menu (menu files)

#endif //GAME_OF_STOOLS_UI_H
