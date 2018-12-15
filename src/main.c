#include "main.h"

World g_world;

int main(int argc, char *argv[]) {
    printf("==== Game of Stools ====\n");

    play();

    return 0;
}

void play() {
    initWorld();
    showAsciiBoard();
}

void mlv() {
    /*MLV_create_window( "beginner - 1 - hello world", "hello world", 640, 480 );
    MLV_draw_text(10, 120, "Bonjour !", MLV_COLOR_MAGENTA);
    MLV_actualise_window();
    MLV_wait_seconds(10);
    MLV_free_window();*/
}

