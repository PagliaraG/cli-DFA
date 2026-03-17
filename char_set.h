#ifndef CHAR_SET_H
#define CHAR_SET_H

typedef char* elem;
typedef unsigned int pointer;

typedef struct{
    char** el;
    pointer ptr;
    unsigned int size;
} set_t;

set_t create_set();

int get_length(set_t* set);

bool is_empty(set_t set);

bool contains(set_t set, char* el);

void add_in_set(set_t* set, elem el);

void remove_from_set(set_t* set, elem el);

void print_set(set_t set);

#endif //CHAR_SET_H
