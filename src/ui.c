#include "ui.h"

World g_world;

void showAsciiBoard() {
    printf("\n\n");
    for (int j = 0; j < COLS; j++) {
        printf("  %2d  ", j);
    }
    printf("\n");
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            printf("------");
        }
        printf("-\n");
        for (int j = 0; j < COLS; j++) {
            showAsciiCell(g_world.board[i][j]);
        }
        printf("| %d\n", i);
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
    }
    if (cell.inhabitants != NULL) {
        string[0] = cell.inhabitants->clan;
    }
    if (cell.castle != NULL) {
        string[0] = cell.castle->clan;
    }
    if (cell.castle != NULL) {
        string[1] = CASTLE;
    }
    if (cell.clan != FREE || cell.castle != NULL || cell.inhabitants != NULL) {
        string[2] = parse_char(countAgentInList(cell.inhabitants, BARON));
        string[3] = parse_char(countAgentInList(cell.inhabitants, WARRIOR));
        string[4] = parse_char(countAgentInList(cell.inhabitants, VILLAGER));
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

void showClanInfo() {
    printf("\nTurn: %d", g_world.turn);
    if (g_world.current->clan == RED) {
        printf("\nPlayer: RED");
        printf("\nTreasure: %d", g_world.redTreasure);
    } else if (g_world.current->clan == BLUE) {
        printf("\nPlayer: BLUE");
        printf("\nTreasure: %d", g_world.blueTreasure);
    }
    printf("\n");
}

void showCastleCommands(Agent *agent) {
    if (agent->product != FREE) {
        printf("\n/!\\ ");
        switch (agent->product) {
            case BARON:
                printf("Baron ");
                break;
            case WARRIOR:
                printf("Warrior ");
                break;
            case VILLAGER:
                printf("Villager ");
                break;
            default:
                break;
        }
        printf("arrive in %d turn(s).\n", agent->time);
    }
    printf("\n0 . Remove");
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
    printf("\n0 . Remove");
    printf("\n1 . Nothing");
    printf("\n2 . New Destination");
    printf("\n3 . Build Castle (%d gold and %d turns)", COST_CASTLE, TIME_CASTLE);
    printf("\n\n");
}

void showWarriorCommands(Agent *agent) {
    printf("\n0 . Remove");
    printf("\n1 . Nothing");
    printf("\n2 . New Destination");
    printf("\n\n");
}

void showVillagerCommands(Agent *agent) {
    printf("\n0 . Remove");
    printf("\n1 . Nothing");
    printf("\n2 . New Destination");
    if (canCollect(agent))
        printf("\n3 . Collect");
    if (canBuild(agent, WARRIOR))
        printf("\n4 . Take Up Arms (%d gold)", COST_WARRIOR);
    printf("\n\n");
}

void showTurnCommands() {
    printf("\nEnd your turn?\n");
    printf("\n1 . End Turn");
    printf("\n2 . Quit");
    printf("\n\n");
}

void showGameCommands() {
    if (g_world.current == NULL)
        printf("\n1 . New Game");
    else
        printf("\n1 . Continue");
    printf("\n2 . Load");
    if (g_world.current != NULL) {
        printf("\n3 . Save");
    }
    printf("\n\n");
}

Vector2 getAgentNewDestCommands(Agent *agent) {
    printf("\nEnter new X position (current: %d): ", agent->dest.x);
    int x = get_user_entry_interval(0, COLS - 1);
    printf("\nEnter new Y position (current: %d): ", agent->dest.y);
    int y = get_user_entry_interval(0, ROWS - 1);
    printf("\n");
    return (Vector2) {x, y};
}

void showWinner(char clan) {
    printf("\n\n*********************\n");
    if (clan == RED) {
        printf("*   WINNER IS RED   *");
    } else if (clan == BLUE) {
        printf("*   WINNER IS BLUE  *");
    }
    printf("\n*********************\n\n");
}