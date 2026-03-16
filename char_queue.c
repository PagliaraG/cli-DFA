#include <stdlib.h>
#include <string.h>
#include <stdio.h>

#define INITIAL_SIZE 4
#define STRING_SIZE 255

typedef struct {
    char** elem;
    int lastIndex;
    int size;
} char_queue_t;

char_queue_t createQueue() {
    char_queue_t queue = {
        .elem = calloc(INITIAL_SIZE,sizeof(char*)),
        .lastIndex = 0,
        .size = INITIAL_SIZE
        };
    for (int i = 0; i < queue.size; i++) {
        queue.elem[i] = calloc(STRING_SIZE,sizeof(char));
    }
    return queue;
}

void addElem(char_queue_t* queue,char* el) {
    strcpy(queue->elem[queue->lastIndex],el);
    queue->lastIndex++;
}

char* poll(char_queue_t* queue) {
    char* output = queue->elem[0];
    for (int i = 0; i < queue->lastIndex; i++) {
        strcpy(queue->elem[i],queue->elem[i+1]);
    }
    queue->size-=1;
    return output;
}

char* peek(char_queue_t* queue) {
    return queue->elem[0];
}

char** copyElements(char_queue_t queue) {
    return queue.elem;
}

void resizeQueue(char_queue_t* queue) {
    if (queue->lastIndex == queue->size -1) {
        char** tmp = copyElements(*queue);
        queue->size*=2;
        queue->elem = calloc(queue->size,sizeof(char*));
        for (int i = 0; i < queue->lastIndex; i++) {
            queue->elem[i] = calloc(STRING_SIZE,sizeof(char));
            strcpy(queue->elem[i],tmp[i]);
        }
        for ( int i = queue->lastIndex; i < queue->size; i++) {
            queue->elem[i] = calloc(STRING_SIZE,sizeof(char));
        }
    }
}

void printQueue(char_queue_t queue) {
    printf("[ ");
    for (int i = 0; i <= queue.lastIndex; i++) {
        printf("%s%s",queue.elem[i],(i < queue.lastIndex) ? ", " : " ");
    }
    printf("] \n");
}


