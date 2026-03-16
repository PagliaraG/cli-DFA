#ifndef CHAR_SET_H
#define CHAR_SET_H

typedef char* elem;
typedef unsigned int pointer;

typedef struct{
    char** el;
    pointer ptr;
    unsigned int size;
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

#endif //CHAR_SET_H
