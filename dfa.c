#include "char_set.h"
#include <stdio.h>

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
    printSet(alph);
    addElem(&alph,"b");
    printSet(alph);
    /*
    addElem(&alph,"c");
    printSet(alph);
    addElem(&alph,"d");
    printSet(alph);
    */
    return 0;
}