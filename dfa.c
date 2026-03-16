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
    state initialState;
    set_t finalStates;
    transition_t transitions[TRANSITION_SIZE];
} dfa_t;

dfa_t createDFA() {
    dfa_t dfa = {
        .alphabet = createSet(),
        .states = createSet(),
        .finalStates = createSet(),
        .initialState = "",
    };
    return dfa;
}

void addState(dfa_t* dfa,state newState){
    if (!contains(dfa->states,newState)){
        addElem(&dfa->states,newState);
    }
}

void removeState(dfa_t* dfa,state newState){
    if (contains(dfa->states,newState)){
        removeElem(&dfa->states,newState);
    }
}

void addSymbol(dfa_t* dfa,char* symbol){
    if (!contains(dfa->alphabet,symbol)){
        addElem(&dfa->alphabet,symbol);
    }
}

void removeSymbol(dfa_t* dfa,char* symbol){
    if (contains(dfa->alphabet,symbol)){
        removeElem(&dfa->alphabet,symbol);
    }
}

void setInitialState(dfa_t* dfa,char* initState) {
    strcpy(dfa->initialState,initState);
}

void addFinalState(dfa_t* dfa,state newState){
    if (!contains(dfa->finalStates,newState)){
        addElem(&dfa->finalStates,newState);
    }
}

void removeFinalState(dfa_t* dfa,state newState){
    if (contains(dfa->finalStates,newState)){
        removeElem(&dfa->finalStates,newState);
    }
}

int main(void){
    return 0;
}