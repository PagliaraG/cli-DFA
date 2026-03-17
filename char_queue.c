#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "char_queue.h"


#define INITIAL_SIZE 4
#define STRING_SIZE 255

char_queue_t create_queue() {
    char_queue_t queue = {
        .elem = calloc(INITIAL_SIZE,sizeof(char*)),
        .last_index = 0,
        .size = INITIAL_SIZE
        };
    for (int i = 0; i < queue.size; i++) {
        queue.elem[i] = calloc(STRING_SIZE,sizeof(char));
    }
    return queue;
}

bool is_queue_empty(char_queue_t* queue) {
    for (int i = 0; i < queue->size; i++) {
        if (strcmp(queue->elem[i],"") != 0) {
            return false;
        }
    }
    return true;
}

char** copy_queue_elements(char_queue_t queue) {
    char** cpy = calloc(queue.last_index,sizeof(char*));
    for (int i = 0; i < queue.last_index; i++) {
        cpy[i] = calloc(STRING_SIZE,sizeof(char));
        strcpy(cpy[i],queue.elem[i]);
    }
    return cpy;
}

static void resize_queue(char_queue_t* queue) {
    bool resizeFlag = false;
    if (queue->last_index == queue->size) {
        resizeFlag = true;
        queue->size*=2;
    } else if (queue->last_index < queue->size/2) {
        resizeFlag = true;
        queue->size/=2;
    }
    if (resizeFlag) {
        char** tmp = copy_queue_elements(*queue);
        free(queue->elem);
        queue->elem = calloc(queue->size,sizeof(char*));
        for (int i = 0; i < queue->last_index; i++) {
            queue->elem[i] = calloc(STRING_SIZE,sizeof(char));
            strcpy(queue->elem[i],tmp[i]);
        }
        for ( int i = queue->last_index ; i < queue->size; i++) {
            queue->elem[i] = calloc(STRING_SIZE,sizeof(char));
        }
        free(tmp);
    }
}

void add_in_queue(char_queue_t* queue,char* el) {
    resize_queue(queue);
    strcpy(queue->elem[queue->last_index],el);
    queue->last_index++;
}

char* poll(char_queue_t* queue) {
    char* output = calloc(STRING_SIZE,sizeof(char));
    strcpy(output,queue->elem[0]);
    for (int i = 0; i < queue->last_index; i++) {
        strcpy(queue->elem[i],queue->elem[i+1]);
    }
    free(queue->elem[queue->last_index]);
    queue->last_index--;
    resize_queue(queue);
    return output;
}

char* peek(char_queue_t* queue) {
    return queue->elem[0];
}

void print_queue(char_queue_t queue) {
    printf("[ ");
    for (int i = 0; i <= queue.last_index; i++) {
        printf("%s%s",queue.elem[i],(i < queue.last_index - 1) ? ", " : "");
    }
    printf(" ] \n");
}


