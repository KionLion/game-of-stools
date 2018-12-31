#include "game.h"

World g_world;

void play() {
    // Init global world variable
    initWorld();
    // Get a random color to start
    AList current = getRandomColor();
    int count = 0;
    do {
        // Update turn and builds
        updateTurn(count++);
        updateBuild(current);

        // Show board and clan
        showAsciiBoard();
        showClanInfo(current);

        // Handle agent by type
        handleAgent(current, CASTLE);
        handleAgent(current, BARON);
        handleAgent(current, WARRIOR);
        handleAgent(current, VILLAGER);

        // Select option before the end of turn
        handleTurnCommands();

        // Switch color to play with
        current = switchTurn(current);
    } while (!isEndGame()); // Check if is the end of the game

    // Show Winner !
}

void handleAgent(AList aList, char type) {
    Agent *agent = aList->nextAgent;
    do {
        if (agent->type == type) {
            if (hasDestination(agent)) {
                //TODO: move
            } else {
                handleAgentCommands(agent);
            }
        }
        agent = agent->nextAgent;
    } while (agent != NULL);
}

void handleAgentCommands(Agent *agent) {
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
            break;
    }
}

void handleBaron(Agent *agent) {
    showBaronCommands(agent);
    switch (get_user_entry_interval(1, 4)) {
        case 1:
            // NOTHING
            break;
        case 2:
            break;
        case 3:
            break;
        case 4:
            break;
        default:
            break;
    }
}

void handleWarrior(Agent *agent) {
    showWarriorCommands(agent);
    switch (get_user_entry_interval(1, 4)) {
        case 1:
            // NOTHING
            break;
        case 2:
            break;
        case 3:
            break;
        case 4:
            break;
        default:
            break;
    }
}

void handleVillager(Agent *agent) {
    showVillagerCommands(agent);
    switch (get_user_entry_interval(1, 4)) {
        case 1:
            // NOTHING
            break;
        case 2:
            break;
        case 3:
            break;
        case 4:
            break;
        case 5:
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


