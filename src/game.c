#include "game.h"

World createWorld() {
    World world;
    initBoard(world.board);
    world.turn = 0;
    world.redTreasure = INIT_TEASURE;
    world.blueTreasure = INIT_TEASURE;
    world.red = createClan(world.board, RED, (Vector2){0, 0});
    world.blue = createClan(world.board, BLUE, (Vector2){COLS - 1, ROWS - 1});
    return world;
}

AList createClan(Cell board[ROWS][COLS], char clan, Vector2 pos) {
    AList aList = createCastle(board, clan, pos);
    addAgent(board, aList, clan, BARON, pos);
    addAgent(board, aList, clan, VILLAGER, pos);
    return aList;
}

AList createCastle(Cell board[ROWS][COLS], char clan, Vector2 pos) {
    AList aList = malloc(sizeof(AList));
    if (aList == NULL)
        exit(EXIT_FAILURE);

    Agent *castle = malloc(sizeof(Agent));
    if (castle == NULL)
        exit(EXIT_FAILURE);

    initAgent(aList, clan, FREE, pos);
    initAgent(castle, clan, CASTLE, pos);
    setAgentOnBoard(board, castle);

    aList->nextAgent = castle;
    return aList;
}

void addAgent(Cell board[ROWS][COLS], AList aList, char clan, char type, Vector2 pos) {
    Agent *agent = malloc(sizeof(Agent));
    if (aList == NULL || agent == NULL)
        exit(EXIT_FAILURE);

    pos = getFreeNextPos(board, pos);
    initAgent(agent, clan, type, pos);
    setAgentOnBoard(board, agent);

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

void setAgentOnBoard(Cell board[ROWS][COLS], Agent *agent) {
    int row = agent->pos.y;
    int col = agent->pos.x;
    board[row][col].clan = agent->clan;
    if (agent->type == CASTLE) {
        board[row][col].castle = agent;
    } else {
        board[row][col].inhabitants = agent;
    }
}

void initAgent(Agent *agent, char clan, char type, Vector2 pos) {
    agent->clan = clan;
    agent->type = type;
    agent->product = FREE;
    agent->time = -1;
    agent->pos = pos;
    agent->dest = (Vector2){-1, -1};
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

Vector2 getFreeNextPos(Cell board[ROWS][COLS], Vector2 pos) {
    Vector2 up = {pos.x, pos.y - 1};
    Vector2 right = {pos.x + 1, pos.y};
    Vector2 down = {pos.x, pos.y + 1};
    Vector2 left = {pos.x - 1, pos.y};
    if (canMove(board, pos, up))
        return up;
    if (canMove(board, pos, right))
        return right;
    if (canMove(board, pos, down))
        return down;
    if (canMove(board, pos, left))
        return left;
}

bool canMove(Cell board[ROWS][COLS], Vector2 pos, Vector2 dest) {
    return isOnBoard(dest) && isFreeCell(board, dest)
        && getDistance(pos, dest) == MAX_MOVE;
}

bool isFreeCell(Cell board[ROWS][COLS], Vector2 pos) {
    return board[pos.y][pos.x].inhabitants == NULL;
}

bool isOnBoard(Vector2 pos) {
    return pos.x >= 0 && pos.x < COLS && pos.y >= 0 && pos.y < ROWS;
}

int getDistance(Vector2 pos, Vector2 dest) {
    return abs(dest.x - pos.x + dest.y - pos.y);
}

int countAgentInList(AList aList, char type) {
    return (aList != NULL && aList->type == type) ? 1 : 0;
}