#include "main.h"

World g_world;

int main(int argc, char *argv[]) {
    //setbuf(stdout, 0); // Fix CLion Jetbrains debug mode

    printf("==== GAME OF STOOLS ====\n");

    play();

    printf("==== ENDGAME ====\n");

    return 0;
}

void play() {
    // Init global world variable
    initWorld();
    // Get a random color to start
    AList current = getRandomColor();
    int cmd;
    int count = 0;
    do {
        // Update turn and builds
        updateTurn(count++);
        updateBuild(current);

        // Show board and clan
        showAsciiBoard();
        showClanInfo(current);

        // Show commands by agent type
        showCommandAgent(current, CASTLE);
        showCommandAgent(current, BARON);
        showCommandAgent(current, WARRIOR);
        showCommandAgent(current, VILLAGER);

        // Select option before the end of turn
        cmd = showCommandTurn();

        // Switch color to play with
        current = switchTurn(current);
    } while (!isEndGame(cmd)); // Check if is the end of the game

    // Show Winner !
}

