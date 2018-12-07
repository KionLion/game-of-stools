#include "game.h"

void init() {
    World world = createWorld();
}

World createWorld() {
    World world;
    world.turn = 0;
    world.redTreasure = INIT_TEASURE;
    world.blueTreasure = INIT_TEASURE;

    Vector2 redPos = {0, 0};
    AList redList = createAgentList(RED, redPos);

    addAgent(redList, createAgent(RED, CASTLE, redPos));
    addAgent(redList, createAgent(RED, BARON, redPos));
    addAgent(redList, createAgent(RED, VILLAGER, redPos));

    world.red = redList;

    return world;
}

Agent *createAgent(char clan, char type, Vector2 pos) {
    Agent *agent = malloc(sizeof(*agent));
    if (agent == NULL)
        exit(EXIT_FAILURE);
    agent->clan = clan;
    agent->type = type;
    agent->pos = pos;
    agent->nextAgent = NULL;
    return agent;
}

AList createAgentList(char clan, Vector2 pos) {
    AList aList = malloc(sizeof(aList));
    if (aList == NULL)
        exit(EXIT_FAILURE);
    aList->clan = clan;
    aList->pos = pos;
    aList->nextAgent = NULL;
    return aList;
}

void addAgent(AList aList, Agent *agent) {
    if (aList == NULL || agent == NULL)
        exit(EXIT_FAILURE);
    Agent *lastAgent = getAgentListTail(aList);
    lastAgent->nextAgent = agent;
}

Agent *getAgentListTail(AList aList) {
    if (aList == NULL)
        exit(EXIT_FAILURE);
    Agent *agent = aList->nextAgent;
    if (agent == NULL)
        return aList;
    while(agent->nextAgent != NULL) {
        agent = agent->nextAgent;
    }
    return agent;
}
