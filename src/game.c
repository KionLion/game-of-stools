#include "game.h"

World g_world;

void play() {
    // Init global world variable
    initWorld();
    // Set a random player to start
    setRandomPlayer();
    int count = 0;
    do {
        // Update turn and builds
        updateTurn(count++);
        updateBuild(g_world.current);

        // Handle agent by type
        handleAgent(CASTLE);
        handleAgent(BARON);
        handleAgent(WARRIOR);
        handleAgent(VILLAGER);

        // Show board and clan
        showAsciiBoard();
        showClanInfo();

        // Select option before the end of turn
        handleTurnCommands();

        // Switch color to play with
        switchTurn();
    } while (!isEndGame()); // Check if is the end of the game

    showWinner(getWinnner()->clan);
}

void handleAgent(char type) {
    Agent *agent = g_world.current->nextAgent;
    Agent *next = NULL;
    while (agent != NULL) {
        next = agent->nextAgent;
        if (agent->type == type) {
            if (hasDestination(agent)) {
                moveAgent(agent);
            } else {
                handleAgentCommands(agent);
            }
        }
        if (g_world.current->nextAgent == NULL) {
            break;
        }
        agent = next;
    }
}

void handleAgentCommands(Agent *agent) {
    showAsciiBoard();
    showClanInfo();
    showAgent(agent);
    printf("Your order?\n");
    switch (agent->type) {
        case CASTLE:
            handleCastle(agent);
            break;
        case BARON:
            handleBaron(agent);
            break;
        case WARRIOR:
            handleWarrior(agent);
            break;
        case VILLAGER:
            handleVillager(agent);
            break;
        default:
            break;
    }
}

void handleCastle(Agent *agent) {
    showCastleCommands(agent);
    switch (get_user_entry_interval(0, 4)) {
        case 0:
            // REMOVE
            removeAgent(g_world.current, agent);
            break;
        case 1:
            // NOTHING
            break;
        case 2:
            // BUILD BARON
            buildAgent(agent, BARON);
            break;
        case 3:
            // BUILD WARRIOR
            buildAgent(agent, WARRIOR);
            break;
        case 4:
            // BUILD VILLAGER
            buildAgent(agent, VILLAGER);
            break;
        default:
            break;
    }
}

void handleBaron(Agent *agent) {
    showBaronCommands(agent);
    switch (get_user_entry_interval(0, 3)) {
        case 0:
            // REMOVE
            removeAgent(g_world.current, agent);
            break;
        case 1:
            // NOTHING
            break;
        case 2:
            // MOVE
            agent->dest = getAgentNewDestCommands(agent);
            moveAgent(agent);
            break;
        case 3:
            // BUILD CASTLE
            break;
        default:
            break;
    }
}

void handleWarrior(Agent *agent) {
    showWarriorCommands(agent);
    switch (get_user_entry_interval(0, 2)) {
        case 0:
            // REMOVE
            removeAgent(g_world.current, agent);
            break;
        case 1:
            // NOTHING
            break;
        case 2:
            // MOVE
            agent->dest = getAgentNewDestCommands(agent);
            moveAgent(agent);
            break;
        default:
            break;
    }
}

void handleVillager(Agent *agent) {
    showVillagerCommands(agent);
    switch (get_user_entry_interval(0, 4)) {
        case 0:
            // REMOVE
            removeAgent(g_world.current, agent);
            break;
        case 1:
            // NOTHING
            break;
        case 2:
            // MOVE
            agent->dest = getAgentNewDestCommands(agent);
            moveAgent(agent);
            break;
        case 3:
            // COLLECT
            collect(agent);
            break;
        case 4:
            // TAKE UP ARMS
            break;
        default:
            break;
    }
}

void handleTurnCommands() {
    showTurnCommands();
    switch (get_user_entry_interval(1, 2)) {
        case 1:
            // END TURN = DO NOTHING
            break;
        case 2:
            // QUIT GAME
            exit(0);
        default:
            break;
    }
}


