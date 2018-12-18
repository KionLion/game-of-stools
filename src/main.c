#include "main.h"

World g_world;

int main(int argc, char *argv[]) {
    setbuf(stdout, 0); // Fix CLion Jetbrains debug mode
    printf("==== GAME OF STOOLS ====\n");

    play();

    printf("==== ENDGAME ====\n");

    return 0;
}

void play() {
    initWorld();
    AList current = getRandomColor();
    int cmd;
    int count = 0;
    do {
        updateTurn(count++);
        updateBuild(current);

        showAsciiBoard();

        showClanInfo(current);

        showCommandAgent(current, CASTLE);
        showCommandAgent(current, BARON);
        showCommandAgent(current, WARRIOR);
        showCommandAgent(current, VILLAGER);

        // Turn Option
        cmd = showCommandTurn();

        current = switchTurn(current);
    } while (!isEndGame(cmd));

    // Show Winner !
}

void mlv() {
    /*MLV_create_window( "beginner - 1 - hello world", "hello world", 640, 480 );
    MLV_draw_text(10, 120, "Bonjour !", MLV_COLOR_MAGENTA);
    MLV_actualise_window();
    MLV_wait_seconds(10);
    MLV_free_window();*/
}

