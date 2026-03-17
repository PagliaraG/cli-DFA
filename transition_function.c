#include <stdlib.h>
#include <string.h>
#include "transition_function.h"

transition_t create_transition() {
    transition_t transition = {
        .start = calloc(STATE_SIZE,sizeof(char)),
        .end = calloc(STATE_SIZE,sizeof(char)),
        .symbol = ""
    };
    return transition;
}

void add_start_state(transition_t* transition, char* start) {
    strcpy(transition->start,start);
}

void add_end_state(transition_t* transition, char* end) {
    strcpy(transition->end,end);
}

void add_symbol(transition_t* transition, char symbol) {
    if (strlen(&symbol) == 1) {
        strcpy(transition->symbol,&symbol);
    }
}
