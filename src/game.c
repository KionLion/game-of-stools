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

        // Handle save / load
        handleSaveLoad();

        // Handle all agents by castle
        handleAgents();

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

void handleAgents() {
    Agent *castle = g_world.current->nextAgent;
    while (castle != NULL) {
        handleAgentByCastle(castle, CASTLE);
        handleAgentByCastle(castle, BARON);
        handleAgentByCastle(castle, WARRIOR);
        handleAgentByCastle(castle, VILLAGER);
        castle = castle->nextNeighbor;
    }
}

void handleAgentByCastle(Agent *castle, char type) {
    Agent *agent = castle;
    Agent *next = NULL;
    while (agent != NULL) {
        next = agent->nextAgent;
        if (agent->type == type) {
            updateBuild(castle, agent);
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
            removeCastle(agent);
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
            removeAgent(agent);
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
            buildAgent(agent, CASTLE);
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
            removeAgent(agent);
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
            removeAgent(agent);
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
            takeUpArms(agent);
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
            exit(EXIT_SUCCESS);
        default:
            break;
    }
}

void handleSaveLoad() {
    showSaveCommands();
    switch (get_user_entry_interval(1, 3)) {
        case 1:
            // CONTINUE
            break;
        case 2:
            // SAVE
            printf("\nEnter the name of the file to save: ");
            save(get_user_entry(200));
            printf("\nFile saved!");
            break;
        case 3:
            // LOAD
            printf("\nEnter the name of the file to load: ");
            load(get_user_entry(200));
            printf("\nFile loaded!");
            break;
        default:
            break;
    }
}


