#include <stdio.h>
#include "char_set.h"
#include <string.h>
#include <stdlib.h>

typedef char state[5];
typedef char symbol;

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
    transition_t transitions[100];
} dfa_t;

void addState(dfa_t dfa,state newState){
    int length = sizeof(dfa.states) / sizeof(dfa.states);
    for(int i=0; i < length; i++){
        
    }
    
}

int main(){
    
    set_t alph = createSet();
    addElem(&alph,"a");
    addElem(&alph,"b");
    printSet(alph); 
    return 0;
}