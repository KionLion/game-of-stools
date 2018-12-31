#include "ui.h"

World g_world;

void showAsciiBoard() {
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            printf("------");
        }
        printf("-\n");
        for (int j = 0; j < COLS; j++) {
            showAsciiCell(g_world.board[i][j]);
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

void showAgent(Agent *agent) {
    printf("\n#");
    if (agent->clan == RED) {
        printf("Red ");
    } else if (agent->clan == BLUE) {
        printf("Blue ");
    }
    if (agent->type == CASTLE) {
        printf("Castle ");
    } else if (agent->type == BARON) {
        printf("Baron ");
    } else if (agent->type == WARRIOR) {
        printf("Warrior ");
    } else if (agent->type == VILLAGER) {
        printf("Villager ");
    } else {
        printf("(NULL) ");
    }
    printf("(%d, %d). ", agent->pos.x, agent->pos.y);
}

void showClanInfo(AList aList) {
    printf("\nTurn: %d", g_world.turn);
    if (aList->clan == RED) {
        printf("\nPlayer: RED");
        printf("\nTreasure: %d", g_world.redTreasure);
    } else if (aList->clan == BLUE) {
        printf("\nPlayer: BLUE");
        printf("\nTreasure: %d", g_world.blueTreasure);
    }
    printf("\n");
}

void showCastleCommands(Agent *agent) {
    printf("\n1 . Nothing");
    if (canBuild(agent, BARON))
        printf("\n2 . Build Baron (%d gold and %d turns)", COST_BARON, TIME_BARON);
    if (canBuild(agent, WARRIOR))
        printf("\n3 . Build Warrior (%d gold and %d turns)", COST_WARRIOR, TIME_WARRIOR);
    if (canBuild(agent, VILLAGER))
        printf("\n4 . Build Villager (%d gold and %d turns)", COST_VILLAGER, TIME_VILLAGER);
    printf("\n\n");
}

void showBaronCommands(Agent *agent) {
    printf("\n1 . Nothing");
    printf("\n2 . New Destination");
    printf("\n3 . Build Castle (%d gold and %d turns)", COST_CASTLE, TIME_CASTLE);
    printf("\n4 . Remove");
    printf("\n\n");
}

void showWarriorCommands(Agent *agent) {
    printf("\n1 . Nothing");
    printf("\n2 . New Destination");
    printf("\n3 . Claim");
    printf("\n4 . Remove");
    printf("\n\n");
}

void showVillagerCommands(Agent *agent) {
    printf("\n1 . Nothing");
    printf("\n2 . New Destination");
    printf("\n3 . Collect");
    printf("\n4 . Take Up Arms (%d gold)", COST_WARRIOR);
    printf("\n5 . Remove");
    printf("\n\n");
}

int showTurnCommands() {
    printf("End your turn?\n");
    printf("\n1 . End Turn");
    printf("\n2 . Quit");
    printf("\n\n");
}