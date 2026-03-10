#include <stdbool.h>

typedef char elem;
typedef elem set;

set *createSet();

bool isEmpty(set* set);

set* resizeSet(set* oldSet);

bool contains(set *set, char* el);

set* addElem(set* set, elem el);

set* removeElem(set* set, elem el);

void printSet(set* set);