#include "ui.h"

World g_world;

void showAgentList(AList aList) {
    if (aList == NULL)
        exit(EXIT_FAILURE);
    Agent *agent = aList->nextAgent;
    while(agent != NULL) {
        printf("{%c-%c(%d,%d)}\n", agent->clan, agent->type, agent->pos.x, agent->pos.y);
        agent = agent->nextAgent;
    }
}

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
    printf("\n");
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
    printf("(%d, %d)", agent->pos.x, agent->pos.y);
    printf("\n\n");
}

void showClanInfo(AList aList) {
    if (aList->clan == RED) {
        printf("\nPlayer turn: RED");
        printf("\nTreasure: %d", g_world.redTreasure);
    } else if (aList->clan == BLUE) {
        printf("\nPlayer turn: BLUE");
        printf("\nTreasure: %d", g_world.blueTreasure);
    }
    printf("\n");
}

void showCommandAgent(AList aList, char type) {
    Agent *agent = aList->nextAgent;
    do {
        if (agent->type == type) {
            showAgent(agent);
            printf("Your order?\n");
            switch (type) {
                case CASTLE:
                    showCommandCastle(agent);
                    break;
                case BARON:
                    showCommandBaron(agent);
                    break;
                case WARRIOR:
                    showCommandWarrior(agent);
                    break;
                case VILLAGER:
                    showCommandVillager(agent);
                    break;
                default:
                    break;
            }
        }
        agent = agent->nextAgent;
    } while (agent != NULL);
}

void showCommandCastle(Agent *agent) {
    printf("\n1 . Nothing");
    printf("\n2 . Build Baron");
    printf("\n3 . Build Warrior");
    printf("\n4 . Build Villager");
    printf("\n\n");
    switch (get_user_entry_interval(1, 4)) {
        case 1:
            //CMD_END_TURN;
            break;
        case 2:
            //CMD_END_TURN;
            break;
        case 3:
            //CMD_END_TURN;
            break;
        case 4:
            //CMD_END_TURN;
            break;
        default:
            //CMD_VOID;
            break;
    }
}

void showCommandBaron(Agent *agent) {
    printf("\n1 . Nothing");
    printf("\n2 . New Destination");
    printf("\n3 . Claim");
    printf("\n4 . Build Castle");
    printf("\n5 . Remove");
    printf("\n\n");
    switch (get_user_entry_interval(1, 5)) {
        case 1:
            //CMD_END_TURN;
            break;
        case 2:
            //CMD_END_TURN;
            break;
        case 3:
            //CMD_END_TURN;
            break;
        case 4:
            //CMD_END_TURN;
            break;
        case 5:
            //CMD_END_TURN;
            break;
        default:
            //CMD_VOID;
            break;
    }
}

void showCommandWarrior(Agent *agent) {
    printf("\n1 . Nothing");
    printf("\n2 . New Destination");
    printf("\n3 . Claim");
    printf("\n4 . Build Castle");
    printf("\n5 . Remove");
    printf("\n\n");
    switch (get_user_entry_interval(1, 5)) {
        case 1:
            //CMD_END_TURN;
            break;
        case 2:
            //CMD_END_TURN;
            break;
        case 3:
            //CMD_END_TURN;
            break;
        case 4:
            //CMD_END_TURN;
            break;
        case 5:
            //CMD_END_TURN;
            break;
        default:
            //CMD_VOID;
            break;
    }
}

void showCommandVillager(Agent *agent) {
    printf("\n1 . Nothing");
    printf("\n2 . New Destination");
    printf("\n3 . Collect");
    printf("\n4 . Take Up Arms");
    printf("\n5 . Remove");
    printf("\n\n");
    switch (get_user_entry_interval(1, 5)) {
        case 1:
            //CMD_END_TURN;
            break;
        case 2:
            //CMD_END_TURN;
            break;
        case 3:
            //CMD_END_TURN;
            break;
        case 4:
            //CMD_END_TURN;
            break;
        case 5:
            //CMD_END_TURN;
            break;
        default:
            //CMD_VOID;
            break;
    }
}

int showCommandTurn() {
    printf("End your turn?\n");
    printf("\n1 . End Turn");
    printf("\n2 . Save");
    printf("\n3 . Load");
    printf("\n4 . Quit");
    printf("\n\n");
    switch (get_user_entry_interval(1, 4)) {
        case 1:
            return CMD_END_TURN;
        case 2:
            return CMD_SAVE;
        case 3:
            return CMD_LOAD;
        case 4:
            return CMD_QUIT;
        default:
            return CMD_END_TURN;
    }
}