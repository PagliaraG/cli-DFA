#ifndef CHAR_QUEUE_H
#define CHAR_QUEUE_H

#define INITIAL_SIZE 4
#define STRING_SIZE 255

typedef struct {
    char** elem;
    int lastIndex;
    int size;
} char_queue_t;

char_queue_t createQueue();

void addInQueue(char_queue_t* queue,char* el);

char* poll(char_queue_t* queue);

char* peek(char_queue_t* queue);

void resizeQueue(char_queue_t* queue);

void printQueue(char_queue_t queue);




#endif //CHAR_QUEUE_H