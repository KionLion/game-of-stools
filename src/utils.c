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
    FILE *f = fopen(filepath, "w+");
    if (f == NULL) {
        perror("Error opening file!\n");
        exit(EXIT_FAILURE);
    }
    fprintf(f, "%s", data);
    fclose(f);
}

void read_file(char *filepath, char *data) {
    FILE *f;

    f = fopen(filepath, "r");

    if (f == NULL) {
        perror("Error opening file!\n");
        exit(EXIT_FAILURE);
    }

    /* Get the number of bytes */
    fseek(f, 0L, SEEK_END);
    long numbytes = ftell(f);

    /* Reset the file position indicator to
    the beginning of the file */
    fseek(f, 0L, SEEK_SET);

    /* Copy all the text into the buffer */
    fread(data, sizeof(char), (size_t) numbytes, f);
    fclose(f);
}

int parse_int(char *digits) {
    return strtol(digits, NULL, 10);
}

char parse_char(int ch) {
    return '0' + ch;
}

char** str_split(char* a_str, const char a_delim) {
    char** result = 0;
    size_t count = 0;
    char* tmp = a_str;
    char* last_comma = 0;
    char delim[2];
    delim[0] = a_delim;
    delim[1] = 0;

    /* Count how many elements will be extracted. */
    while (*tmp) {
        if (a_delim == *tmp) {
            count++;
            last_comma = tmp;
        }
        tmp++;
    }

    /* Add space for trailing token. */
    count += last_comma < (a_str + strlen(a_str) - 1);

    /* Add space for terminating null string so caller
       knows where the list of returned strings ends. */
    count++;

    result = malloc(sizeof(char*) * count);

    if (result) {
        size_t idx  = 0;
        char* token = strtok(a_str, delim);

        while (token) {
            assert(idx < count);
            *(result + idx++) = strdup(token);
            token = strtok(0, delim);
        }
        assert(idx == count - 1);
        *(result + idx) = 0;
    }
    return result;
}


