#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "char_set.h"

#define INITIAL_SIZE 2
#define STRING_SIZE 255

set_t create_set(){
    set_t set;
    set.el = calloc(INITIAL_SIZE,sizeof(char*));
    for(int i = 0; i < INITIAL_SIZE;i++){
        set.el[i] = calloc(STRING_SIZE,sizeof(char));
    }
    set.size = INITIAL_SIZE;
    set.ptr = 0;
    return set;
}

int get_length(set_t* set){
    return set->size;
}

int get_last_index(set_t* set) {
    int i = 0;
    while ( i < get_length(set) - 1) {
        if (strcmp(set->el[i],"") == 0) {
            break;
        }
        i++;
    }
    return i;
}

bool is_empty(set_t* set){
    for(int i = 0; i < get_length(set) ; i++){
        if(strcmp(set->el[i],"") != 0){
            return true;
        }
    }
    return false;
}

char** copy_set_elements(set_t* set, int lastIndex) {
    char** output = calloc(lastIndex+1,sizeof(char*));
    for (int i = 0; i <= lastIndex; i++) {
        output[i] = calloc(STRING_SIZE,sizeof(char));
        strcpy(output[i],set->el[i]);
    }
    return  output;
}


static void resize_set(set_t* set){
    int length = get_length(set);
    int last_index = get_last_index(set);
    if(last_index == length - 1 ){
        char** tmp = copy_set_elements(set,last_index);
        free(set->el);
        set->el = calloc(set->size*2,sizeof(char*));
        for (int i = 0; i <= last_index; i++) {
            set->el[i] = calloc(STRING_SIZE,sizeof(char));
            strcpy(set->el[i],tmp[i]);
        }
        free(tmp);
        for (int i = last_index+1 ; i < length*2 ; i++) {
            set->el[i] = calloc(STRING_SIZE,sizeof(char));
        }
        set->size*=2;
    }else if(last_index < length/2 && length > 2){
        for (int i = length/2 ; i < length ; i++) {
            free(set->el[i]);
        }
        set->size/=2;
    }
 }

bool contains(set_t* set, char* el){
    for(int i = 0; i < get_length(set) ; i++){
        if(strcmp(set->el[i],el) == 0){
            return true;         
        } 
    }
    return false;
}

void add_in_set(set_t* set, elem el){
    if(!contains(set,el)){
        resize_set(set);
        for(int i = 0; i < get_length(set); i++){
            if(strcmp(set->el[i],"") == 0){
                strcpy(set->el[i],el);
                break;
            }
        }
    }
}

void remove_from_set(set_t* set, elem el){
    if(contains(set,el)){
        int length = get_length((set));
        int index = 0;
        for( int i = 0; i < length; i++){
            if(strcmp(set->el[i],el) == 0){
                free(set->el[i]);
                index = i;
                break;
            }
        }
        if (index < length-1) {
            for (int i=index; i<length-1; i++) {
                strcpy(set->el[i],set->el[i+1]);
            }
        }
        set->size--;
        resize_set(set);
    }
}

void print_set(set_t set){
    int last_index = get_last_index(&set);
    printf("[ ");
    for( int i = 0; i < last_index; i++){
        if (strcmp(set.el[i],"") == 0) break;
        printf("%s%s",set.el[i],(i < last_index-1) ? ", " : "");
    }
    printf(" ]\n");
}