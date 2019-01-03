#include "game.h"

int main(int argc, char *argv[]) {
    setbuf(stdout, 0); // Fix CLion Jetbrains debug mode

    printf("==== GAME OF STOOLS ====");

    play();

    printf("==== ENDGAME ====\n");

    return 0;
}

