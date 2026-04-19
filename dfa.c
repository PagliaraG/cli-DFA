#include <stdio.h>
#include <string.h>
#include "char_set.h"
#include "char_queue.h"

#define STATE_SIZE 255
#define SYMBOL_SIZE 255
#define TRANSITION_SIZE 255

typedef char state[STATE_SIZE];
typedef char symbol[SYMBOL_SIZE];


typedef struct {
    state init;
    state final;
    symbol symbol;
} transition_t;

typedef struct{
    set_t alphabet;
    set_t states;
    state initial_state;
    set_t final_states;
    transition_t transitions[TRANSITION_SIZE];
} dfa_t;

dfa_t createDFA() {
    dfa_t dfa = {
        .alphabet = create_set(),
        .states = create_set(),
        .final_states = create_set(),
        .initial_state = "",
    };
    return dfa;
}

void addState(dfa_t* dfa,state newState){
    if (!contains(&dfa->states,newState)){
        add_in_set(&dfa->states,newState);
    }
}

void removeState(dfa_t* dfa,state newState){
    if (contains(&dfa->states,newState)){
        remove_from_set(&dfa->states,newState);
    }
}

void addSymbol(dfa_t* dfa,char* symbol){
    if (!contains(&dfa->alphabet,symbol)){
        add_in_set(&dfa->alphabet,symbol);
    }
}

void removeSymbol(dfa_t* dfa,char* symbol){
    if (contains(&dfa->alphabet,symbol)){
        remove_from_set(&dfa->alphabet,symbol);
    }
}

void setInitialState(dfa_t* dfa,char* initState) {
    strcpy(dfa->initial_state,initState);
}

void addFinalState(dfa_t* dfa,state newState){
    if (!contains(&dfa->final_states,newState)){
        add_in_set(&dfa->final_states,newState);
    }
}

void removeFinalState(dfa_t* dfa,state newState){
    if (contains(&dfa->final_states,newState)){
        remove_from_set(&dfa->final_states,newState);
    }
}

void addTransition(dfa_t* dfa,state start,state end) {

}

int main(void){
    return 0;
}