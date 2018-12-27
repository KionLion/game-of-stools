#include "game.h"

void initWorld() {
    initBoard();
    g_world.turn = 0;
    g_world.redTreasure = INIT_TEASURE;
    g_world.blueTreasure = INIT_TEASURE;
    g_world.red = createClan(RED, (Vector2){0, 0});
    g_world.blue = createClan(BLUE, (Vector2){COLS - 1, ROWS - 1});
}

void initBoard() {
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            g_world.board[i][j].clan = FREE;
            g_world.board[i][j].castle = NULL;
            g_world.board[i][j].inhabitants = NULL;
        }
    }
}

void initAgent(Agent *agent, char clan, char type, Vector2 pos) {
    pos = getFreeNextPos(pos);
    agent->clan = clan;
    agent->type = type;
    agent->product = FREE;
    agent->time = -1;
    agent->pos = pos;
    agent->dest = pos;
    agent->nextAgent = NULL;
    agent->prevAgent = NULL;
    agent->nextNeighbor = NULL;
    agent->prevNeighbor = NULL;
}

AList createClan(char clan, Vector2 pos) {
    AList aList = createCastle(clan, pos);
    addAgent(aList, clan, BARON);
    addAgent(aList, clan, VILLAGER);
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
    setAgentOnBoard(castle);

    aList->nextAgent = castle;
    return aList;
}

void addAgent(AList aList, char clan, char type) {
    Agent *agent = malloc(sizeof(Agent));
    if (aList == NULL || agent == NULL || aList->nextAgent == NULL)
        exit(EXIT_FAILURE);

    Agent *castle = aList->nextAgent;
    initAgent(agent, clan, type, castle->pos);
    setAgentOnBoard(agent);

    Agent *tail = aList->nextAgent;
    while(tail->nextAgent != NULL) {
        tail = tail->nextAgent;
    }
    tail->nextAgent = agent;
}

void setAgentOnBoard(Agent *agent) {
    int row = agent->pos.y;
    int col = agent->pos.x;
    g_world.board[row][col].clan = agent->clan;
    if (agent->type == CASTLE) {
        g_world.board[row][col].castle = agent;
    } else {
        g_world.board[row][col].inhabitants = agent;
    }
}

void moveAgent(Agent *agent) {
    //TODO: Move
}

bool hasDestination(Agent *agent) {
    return agent->dest.x != agent->pos.x || agent->dest.y != agent->pos.y;
}

Vector2 getFreeNextPos(Vector2 pos) {
    Vector2 up = {pos.x, pos.y - 1};
    Vector2 right = {pos.x + 1, pos.y};
    Vector2 down = {pos.x, pos.y + 1};
    Vector2 left = {pos.x - 1, pos.y};
    if (canMove(pos))
        return pos;
    if (canMove(up))
        return up;
    if (canMove(right))
        return right;
    if (canMove(down))
        return down;
    if (canMove(left))
        return left;
    return pos;
}

bool canMove(Vector2 dest) {
    return isOnBoard(dest) && isFreeCell(dest);
}

bool isFreeCell(Vector2 pos) {
    return g_world.board[pos.y][pos.x].inhabitants == NULL;
}

bool isOnBoard(Vector2 pos) {
    return pos.x >= 0 && pos.x < COLS && pos.y >= 0 && pos.y < ROWS;
}

int countAgentInList(AList aList, char type) {
    return (aList != NULL && aList->type == type) ? 1 : 0;
}

AList  getRandomColor() {
    return get_random_boolean() ? g_world.red : g_world.blue;
}

AList switchTurn(AList current) {
    return (current == g_world.red) ? g_world.blue : g_world.red;
}

AList getWinnner() {
    if (g_world.red->nextAgent == NULL) {
        return g_world.blue;
    }
    if (g_world.blue->nextAgent == NULL) {
        return g_world.red;
    }
    return NULL;
}

bool isEndGame(int cmd) {
    return getWinnner() != NULL || cmd == CMD_QUIT;
}

void updateTurn(int count) {
    if (count % 2 == 0) {
        g_world.turn++;
    }
}

int getTreasure(char clan) {
    return (clan == RED) ? g_world.redTreasure : g_world.blueTreasure;
}

void spendTreasure(int cost, char clan) {
    if (clan == RED) {
        g_world.redTreasure -= cost;
    } else if (clan == BLUE) {
        g_world.blueTreasure -= cost;
    }
}

int getAgentTimeBuild(char type) {
    switch (type) {
        case CASTLE:
            return TIME_CASTLE;
        case BARON:
            return TIME_BARON;
        case WARRIOR:
            return TIME_WARRIOR;
        case VILLAGER:
            return TIME_VILLAGER;
        default:
            return -1;
    }
}

int getAgentCost(char type) {
    switch (type) {
        case CASTLE:
            return COST_CASTLE;
        case BARON:
            return COST_BARON;
        case WARRIOR:
            return COST_WARRIOR;
        case VILLAGER:
            return COST_VILLAGER;
        default:
            return -1;
    }
}

bool canBuild(Agent *castle, char type) {
    return castle->product == FREE && getTreasure(castle->clan) >= getAgentCost(type);
}

void buildAgent(Agent *castle, char type) {
    if (canBuild(castle, type)) {
        castle->product = type;
        castle->time = getAgentTimeBuild(type);
        spendTreasure(getAgentCost(type), castle->clan);
    }
}

void updateBuild(AList aList) {
    Agent *agent = aList->nextAgent;
    while(agent != NULL) {
        if (agent->product != FREE) {
            agent->time--;
            if (agent->time <= 0 && hasAvailableSpaceToBuild(agent->pos)) {
                addAgent(aList, agent->clan, agent->product);
                agent->product = FREE;
            }
        }
        agent = agent->nextAgent;
    }
}

bool hasAvailableSpaceToBuild(Vector2 pos) {
    Vector2 vector = getFreeNextPos(pos);
    return g_world.board[vector.y][vector.x].inhabitants == NULL;
}