#include "utils.h"

bool get_random_boolean() {
    srand((unsigned)time(NULL));
    return rand() % 2;
}

int get_random_integer(int begin, int end) {
    srand((unsigned)time(NULL));
    return (rand() % (end - begin + 1)) + begin;
}

int get_distance(Vector2 pos, Vector2 dest) {
    return abs(dest.x - pos.x + dest.y - pos.y);
}


