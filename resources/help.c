

typedef struct Element { /**/
    int val;
    Element *next;
    Element *prev;
};

typedef struct List {
    Element *first;
};

int toto[] <=> int *toto

List <-> Element (5) <-> Element (1) <-> NULL

AList -> NULL
AList -> Castle (DATA) -> Villager (DATA) -> Baron (DATA) -> NULL

// ADD HEAD
List -> Element (0) -> NULL
List -> Element (1) -> Element (0) -> NULL

// ADD TAIL
List -> Element (0) -> NULL
List -> Element (0) -> Element (1) -> NULL
