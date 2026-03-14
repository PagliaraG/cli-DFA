#include <stdbool.h>

typedef char* elem;
typedef unsigned int pointer;

typedef struct{
    char el[2][20];
    pointer ptr;
} set_t;

set_t createSet();

int getLength(set_t* set);

bool isEmpty(set_t set);

set_t resizeSet(set_t oldSet);

bool contains(set_t set, char* el);

void addElem(set_t* set, elem el);

void removeElem(set_t* set, elem el);

void printSet(set_t set);

char* getFirst(set_t set);

char* getNext(set_t set);