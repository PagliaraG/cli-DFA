#include "stdio.h"

typedef char state[5];
typedef char symbol[1];

typedef struct {
    state init;
    state final;
    symbol symbol;

} transition_t;

typedef struct{
    symbol alphabet[50];
    state states[100];
    state initial_state;
    state final_states[50];
    transition_t transitions[100];
} dfa_t;

void addState(dfa_t dfa,state newState){
    int length = sizeof(dfa.states) / sizeof(dfa.states[0]);
    for(int i=0; i < length; i++){
        if (strcmp(dfa.states[i],newState)){
            break;
        }
    }
    
}