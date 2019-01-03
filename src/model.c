#include "model.h"

void initWorld() {
    initBoard();
    g_world.turn = 0;
    g_world.redTreasure = INIT_TEASURE;
    g_world.blueTreasure = INIT_TEASURE;
    g_world.red = createClan(RED, (Vector2){0, 0});
    g_world.blue = createClan(BLUE, (Vector2){COLS - 1, ROWS - 1});
    g_world.current = NULL;
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
    agent->time = 0;
    agent->pos = pos;
    agent->dest = pos;
    agent->nextAgent = NULL;
    agent->prevAgent = NULL;
    agent->nextNeighbor = NULL;
    agent->prevNeighbor = NULL;
}

AList createClan(char clan, Vector2 pos) {
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
    addAgentOnBoard(castle);

    aList->nextAgent = castle;
    return aList;
}

Agent *addAgent(AList aList, char clan, char type, Vector2 pos) {
    Agent *agent = malloc(sizeof(Agent));
    if (aList == NULL || agent == NULL || aList->nextAgent == NULL)
        exit(EXIT_FAILURE);

    initAgent(agent, clan, type, pos);
    addAgentOnBoard(agent);

    Agent *next = aList->nextAgent;
    while(next->nextAgent != NULL) {
        next = next->nextAgent;
    }
    next->nextAgent = agent;
    return agent;
}

void removeAgent(AList aList, Agent *agent) {
    Agent *current = aList->nextAgent;
    Agent *next = NULL;
    if (agent->type == CASTLE) { // Delete all agents belong to castle
        while (current != NULL) {
            removeAgentOnBoard(current);
            next = current->nextAgent;
            free(current);
            current = next;
        }
        aList->nextAgent = NULL;
    } else {
        next = aList->nextAgent;
        while (next->nextAgent != NULL && agent != next) { // Search and delete
            current = next;
            next = next->nextAgent;
        }
        if (agent == next) {
            removeAgentOnBoard(agent);
            current->nextAgent = agent->nextAgent;
            free(agent);
        }
    }
}

void addAgentOnBoard(Agent *agent) {
    int row = agent->pos.y;
    int col = agent->pos.x;
    if (agent->type == CASTLE) {
        g_world.board[row][col].castle = agent;
    } else {
        g_world.board[row][col].inhabitants = agent;
    }
    claim(agent);
}

void removeAgentOnBoard(Agent *agent) {
    int row = agent->pos.y;
    int col = agent->pos.x;
    if (agent->type == CASTLE) {
        g_world.board[row][col].castle = NULL;
    } else {
        g_world.board[row][col].inhabitants = NULL;
    }
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
    return g_world.board[pos.y][pos.x].inhabitants == NULL
        && g_world.board[pos.y][pos.x].castle == NULL;
}

bool isOnBoard(Vector2 pos) {
    return pos.x >= 0 && pos.x < COLS && pos.y >= 0 && pos.y < ROWS;
}

int countAgentInList(AList aList, char type) {
    return (aList != NULL && aList->type == type) ? 1 : 0;
}

void setRandomPlayer() {
    g_world.current = get_random_boolean() ? g_world.red : g_world.blue;
}

void switchTurn() {
    g_world.current = (g_world.current == g_world.red) ? g_world.blue : g_world.red;
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

bool isEndGame() {
    return getWinnner() != NULL;
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
            return 0;
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
                addAgent(aList, agent->clan, agent->product, agent->pos);
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

void moveAgent(Agent *agent) {
    if (agent->type != CASTLE) {
        removeAgentOnBoard(agent);
        agent->pos = getDirectionOnMove(agent);
        addAgentOnBoard(agent);
    }
    if (agent->type == WARRIOR) {
        claim(agent);
    }
}

Vector2 getDirectionOnMove(Agent *agent) {
    Vector2 direction = (Vector2) {
            get_sign(agent->dest.x - agent->pos.x),
            get_sign(agent->dest.y - agent->pos.y)
    };
    Vector2 nextPosOnX = (Vector2) {agent->pos.x + direction.x, agent->pos.y};
    Vector2 nextPosOnY = (Vector2) {agent->pos.x, agent->pos.y + direction.y};
    bool canMoveOnX = direction.x != 0 && canMove(nextPosOnX);
    bool canMoveOnY = direction.y != 0 && canMove(nextPosOnY);

    if (canMoveOnX && canMoveOnY) {
        if (get_random_boolean()) {
            return nextPosOnX;
        } else {
            return nextPosOnY;
        }
    } else if (canMoveOnX) {
        return nextPosOnX;
    } else if (canMoveOnY) {
        return nextPosOnY;
    } else {
        return agent->pos;
    }
}

void claim(Agent *agent) {
    if (agent->type == WARRIOR || agent->type == CASTLE) {
        int row = agent->pos.y;
        int col = agent->pos.x;
        g_world.board[row][col].clan = agent->clan;
    }
}

bool hasDestination(Agent *agent) {
    return agent->dest.x != agent->pos.x || agent->dest.y != agent->pos.y;
}

bool canCollect(Agent *agent) {
    return agent->type == VILLAGER
    && g_world.board[agent->pos.y][agent->pos.x].clan == agent->clan;
}

void collect(Agent *agent) {
    if (canCollect(agent)) {
        if (agent->clan == RED) {
            g_world.redTreasure += VILLAGER_COLLECT_VALUE;
        } else if (agent->clan == BLUE) {
            g_world.blueTreasure += VILLAGER_COLLECT_VALUE;
        }
    }
}

void takeUpArms(Agent *agent) {
    if (agent->type == VILLAGER && canBuild(agent, WARRIOR)) {
        spendTreasure(getAgentCost(WARRIOR), agent->clan);
        agent->type = WARRIOR;
    }
}

void save(char *filename) {
    char data[10000];
    if (g_world.current->clan == RED) {
        sprintf(data, "%s%c %d %d %d \n", data, g_world.current->clan,
                g_world.turn, g_world.redTreasure, g_world.blueTreasure);
    } else if (g_world.current->clan == BLUE) {
        sprintf(data, "%s%c %d %d %d \n", data, g_world.current->clan,
                g_world.turn, g_world.blueTreasure, g_world.redTreasure);
    }

    appendAgentData(g_world.red, data);
    appendAgentData(g_world.blue, data);
    appendBoardData(data);

    strcat(filename, EXT_SAVE_FILE);
    write_file(filename, data);
}

void appendAgentData(AList aList, char data[]) {
    Agent *agent = aList->nextAgent;
    while(agent != NULL) {
        sprintf(data, "%s%c%c%c %d %d %d %d %d \n", data,
                agent->clan, agent->type, agent->product == FREE ? FREE_CHAR_IN_FILE : agent->product,
                agent->time, agent->pos.x, agent->pos.y, agent->dest.x, agent->pos.y);
        agent = agent->nextAgent;
    }
}

void appendBoardData(char data[]) {
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            sprintf(data, "%s%c", data, g_world.board[i][j].clan == FREE ? FREE_CHAR_IN_FILE : g_world.board[i][j].clan);
        }
        sprintf(data, "%s\n", data);
    }
}

void load(char *filename) {
    char data[10000];
    strcat(filename, EXT_SAVE_FILE);
    read_file(filename, data);

    char **lines = str_split(data, ' ');

    if (lines == NULL)
        exit(EXIT_FAILURE);

    g_world.current = lines[0][0] == RED ? g_world.red : g_world.blue;
    g_world.turn = parse_int(lines[1]);
    if (g_world.current->clan == RED) {
        g_world.redTreasure = parse_int(lines[2]);
        g_world.blueTreasure = parse_int(lines[3]);
    } else {
        g_world.blueTreasure = parse_int(lines[2]);
        g_world.redTreasure = parse_int(lines[3]);
    }

    // Get the length of the array
    int length;
    for (length = 0; lines[length]; length++);

    loadBoardFromData(lines[length - 1]);

    for (int i = 4; i < length - 1; i += 6) {
       loadAgentFromData(lines, i);
    }

    // Clear lines
    for (int i = 0; lines[i]; ++i) {
        free(lines[i]);
    }
    free(lines);
}

void loadBoardFromData(char *data) {
    initBoard();
    char clan;
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            clan = data[i * (COLS + 1) + j + 1]; // +1 because of '\n'
            if (clan == FREE_CHAR_IN_FILE)
                clan = FREE;
            g_world.board[i][j].clan = clan;
        }
    }
}

void loadAgentFromData(char **data, int i) {
    char clan = data[i][1];
    char type = data[i][2];
    char product = data[i][3];
    int time = parse_int(data[i + 1]);
    Vector2 pos = {parse_int(data[i + 2]), parse_int(data[i + 3])};
    Vector2 dest = {parse_int(data[i + 4]), parse_int(data[i + 5])};

    AList list;
    Agent *agent;
    if (type == CASTLE) {
        list = createCastle(clan, pos);
        agent = list->nextAgent;
    } else {
        list = (clan == RED) ? g_world.red : g_world.blue;
        agent = addAgent(list, clan, type, pos);
    }
    agent->product = product;
    if (product == FREE_CHAR_IN_FILE)
        agent->product = FREE;
    agent->time = time;
    agent->pos = pos;
    agent->dest = dest;

    if (clan == RED) {
        g_world.red = list;
    } else if (clan == BLUE) {
        g_world.blue = list;
    }
}
