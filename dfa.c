#include "char_set.h"
#include <stdio.h>

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
        .alphabet = createSet(),
        .states = createSet(),
        .final_states = createSet(),
        .initial_state = "",
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

int main(){
    
    dfa_t bStaraStar = createDFA();
    addState(&bStaraStar,"q0");
    addSymbol(&bStaraStar,"a");
    addSymbol(&bStaraStar,"b");
    return 0;
}