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
    if (canBuild(agent, BARON))
        printf("\n2 . Build Baron (%d gold and %d turns)", COST_BARON, TIME_BARON);
    if (canBuild(agent, WARRIOR))
        printf("\n3 . Build Warrior (%d gold and %d turns)", COST_WARRIOR, TIME_WARRIOR);
    if (canBuild(agent, VILLAGER))
        printf("\n4 . Build Villager (%d gold and %d turns)", COST_VILLAGER, TIME_VILLAGER);
    printf("\n\n");
    switch (get_user_entry_interval(1, 4)) {
        case 1:
            // NOTHING
            break;
        case 2:
            buildAgent(agent, BARON);
            break;
        case 3:
            buildAgent(agent, WARRIOR);
            break;
        case 4:
            buildAgent(agent, VILLAGER);
            break;
        default:
            // NOTHING
            break;
    }
}

void showCommandBaron(Agent *agent) {
    printf("\n1 . Nothing");
    printf("\n2 . New Destination");
    printf("\n3 . Build Castle (%d gold and %d turns)", COST_CASTLE, TIME_CASTLE);
    printf("\n4 . Remove");
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

void showCommandWarrior(Agent *agent) {
    printf("\n1 . Nothing");
    printf("\n2 . New Destination");
    printf("\n3 . Claim");
    printf("\n4 . Remove");
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
        default:
            //CMD_VOID;
            break;
    }
}

void showCommandVillager(Agent *agent) {
    printf("\n1 . Nothing");
    printf("\n2 . New Destination");
    printf("\n3 . Collect");
    printf("\n4 . Take Up Arms (%d gold)", COST_WARRIOR);
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
    printf("\n4 . Quit");
    printf("\n\n");
    switch (get_user_entry_interval(1, 2)) {
        case 1:
            return CMD_END_TURN;
        case 2:
            return CMD_QUIT;
        default:
            return CMD_END_TURN;
    }
}