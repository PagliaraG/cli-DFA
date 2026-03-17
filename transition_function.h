#ifndef TRANSITION_FUNCTION_H
#define TRANSITION_FUNCTION_H

#define STATE_SIZE 255

typedef struct {
    char* start;
    char* end;
    char symbol[1];
} transition_t;

transition_t create_transition();

void add_start_state(transition_t* transition, char* start);

void add_end_state(transition_t* transition, char* end);

void add_symbol(transition_t* transition, char symbol);


#endif //TRANSITION_FUNCTION_H