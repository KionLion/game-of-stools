#include "game.h"

void init() {
    World world = createWorld();
    initBoard(world.board);
    initAgentList(world.red, world.board);
    initAgentList(world.blue, world.board);

    showAsciiBoard(world.board);
}

void initBoard(Cell board[ROWS][COLS]) {
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            board[i][j].clan = FREE;
            board[i][j].castle = NULL;
            board[i][j].inhabitants = NULL;
        }
    }
}

void initAgentList(AList aList, Cell board[ROWS][COLS]) {
    Agent *agent = aList->nextAgent;
    while(agent != NULL && agent->nextAgent != NULL) {
        //TODO: update board
        board[agent->pos.y][agent->pos.x].clan = agent->clan;
        if (agent->type == CASTLE) {
            board[agent->pos.y][agent->pos.x].castle = agent;
        }
        agent = agent->nextAgent;
    }
}

void initAgent(Agent *agent, char clan, char type, Vector2 pos) {
    Vector2 dest = {-1, -1};
    agent->clan = clan;
    agent->type = type;
    agent->product = FREE;
    agent->time = -1;
    agent->pos = pos;
    agent->dest = dest;
    agent->nextAgent = NULL;
    agent->prevAgent = NULL;
    agent->nextNeighbor = NULL;
    agent->prevNeighbor = NULL;
}

World createWorld() {
    World world;
    world.turn = 0;
    world.redTreasure = INIT_TEASURE;
    world.blueTreasure = INIT_TEASURE;
    world.red = createClan(RED, 0, 0);
    world.blue = createClan(BLUE, COLS - 1, ROWS - 1);
    return world;
}

AList createClan(char clan, int x, int y) {
    Vector2 pos = {x, y};
    AList aList = createCastle(clan, pos);
    addAgent(aList, clan, BARON, pos);
    addAgent(aList, clan, VILLAGER, pos);
    return aList;
}

AList createCastle(char clan, Vector2 pos) {
    AList aList = malloc(sizeof(AList));
    if (aList == NULL)
        exit(EXIT_FAILURE);

    Agent *castle = malloc(sizeof(Agent));
    if (castle == NULL)
        exit(EXIT_FAILURE);

    initAgent(aList, clan, FREE, pos);
    initAgent(castle, clan, CASTLE, pos);

    aList->nextAgent = castle;
    return aList;
}

void addAgent(AList aList, char clan, char type, Vector2 pos) {
    Agent *agent = malloc(sizeof(Agent));
    if (aList == NULL || agent == NULL)
        exit(EXIT_FAILURE);

    initAgent(agent, clan, type, pos);

    if (aList->nextAgent == NULL) {
        aList->nextAgent = agent;
    } else {
        Agent *tail = aList->nextAgent;
        while(tail->nextAgent != NULL) {
            tail = tail->nextAgent;
        }
        tail->nextAgent = agent;
    }
}

/* ----- UI -----*/

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
        // TODO: Mohamed (count agent type)
        string[2] = '.';
        string[3] = '.';
        string[4] = '.';
    }
    printf("|%s", string);
}

