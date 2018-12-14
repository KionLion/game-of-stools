#include "ui.h"

void showAgentList(AList aList) {
    if (aList == NULL)
        exit(EXIT_FAILURE);
    Agent *agent = aList->nextAgent;
    while(agent != NULL) {
        printf("{%c-%c(%d,%d)}\n", agent->clan, agent->type, agent->pos.x, agent->pos.y);
        agent = agent->nextAgent;
    }
}

void showAsciiBoard(Cell board[ROWS][COLS]) {
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            printf("------");
        }
        printf("-\n");
        for (int j = 0; j < COLS; j++) {
            showAsciiCell(board[i][j]);
        }
        printf("|\n");
    }
    for (int j = 0; j < COLS; j++) {
        printf("------");
    }
    printf("-\n");
}

void showAsciiCell(Cell cell) {
    char string[] = "     ";
    if (cell.clan != FREE) {
        string[0] = cell.clan;
        if (cell.castle != NULL){
            string[1] = CASTLE;
        }
        string[2] = '0' + countAgentInList(cell.inhabitants, BARON);
        string[3] = '0' + countAgentInList(cell.inhabitants, WARRIOR);
        string[4] = '0' + countAgentInList(cell.inhabitants, VILLAGER);
    }
    printf("|%s", string);
}