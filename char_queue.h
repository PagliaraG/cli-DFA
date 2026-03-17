#ifndef CHAR_QUEUE_H
#define CHAR_QUEUE_H

#define INITIAL_SIZE 4
#define STRING_SIZE 255

typedef struct {
    char** elem;
    int last_index;
    int size;
} char_queue_t;

char_queue_t create_queue();

bool is_queue_empty(char_queue_t* queue);

void add_in_queue(char_queue_t* queue,char* el);

char* poll(char_queue_t* queue);

char* peek(char_queue_t* queue);

void print_queue(char_queue_t queue);

#endif //CHAR_QUEUE_H