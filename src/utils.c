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

int get_sign(int x) {
    return (x > 0) - (x < 0);
}

void set_user_entry(char *entry, int maxLength) {
    fgets(entry, maxLength - 1, stdin);
    entry[strcspn(entry, "\r\n")] = 0; // remove "\r\n" from entry
}

char *get_user_entry(int maxLength) {
    char *entry = malloc(sizeof(char) * maxLength);
    set_user_entry(entry, maxLength);
    return entry;
}

int get_user_entry_integer() {
    int entry = 0;
    char c;
    do {
        printf("[Enter integer]");
    } while ((scanf("%d%c", &entry, &c) != 2 || c != '\n') && clean_stdin());
    return entry;
}

int get_user_entry_interval(int min, int max) {
    int entry = 0;
    char c;
    do {
        printf("[Enter integer between %d to %d]", min, max);
    } while (((scanf("%d%c", &entry, &c) != 2 || c != '\n')
            && clean_stdin()) || entry < min || entry > max);
    return entry;
}

bool clean_stdin() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF) {}
    return TRUE;
}

void write_file(char *filepath, char *data) {
    FILE *f = fopen(filepath, "w");
    if (f == NULL) {
        printf("Error opening file!\n");
        exit(EXIT_FAILURE);
    }
    fprintf(f, "%s", data);
    fclose(f);
}


