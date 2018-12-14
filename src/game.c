#include "game.h"

World createWorld() {
    World world;
    initBoard(world.board);
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

void initBoard(Cell board[ROWS][COLS]) {
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            board[i][j].clan = FREE;
            board[i][j].castle = NULL;
            board[i][j].inhabitants = NULL;
        }
    }
}

void setAgentListOnBoard(AList aList, Cell board[ROWS][COLS]) {
    Agent *agent = aList->nextAgent;
    while(agent != NULL && agent->nextAgent != NULL) {
        setAgentOnBoard(agent, board);
        agent = agent->nextAgent;
    }
}

void setAgentOnBoard(Agent *agent, Cell board[ROWS][COLS]) {
    int row = agent->pos.y;
    int col = agent->pos.x;
    board[row][col].clan = agent->clan;
    if (agent->type == CASTLE) {
        board[row][col].castle = agent;
    } else {
        board[row][col].inhabitants = agent;
    }
}

int countAgentInList(AList aList, char type) {
    //TODO: Mohamed
}

