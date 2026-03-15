#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define INITIAL_SIZE 2
#define STRING_SIZE 255

typedef char* elem;
typedef unsigned int pointer;

typedef struct{
    char** el;
    pointer ptr;
    unsigned int size;
} set_t;

set_t createSet(){
    set_t set;
    set.el = calloc(INITIAL_SIZE,sizeof(char*));
    for(int i = 0; i < INITIAL_SIZE;i++){
        set.el[i] = calloc(STRING_SIZE,sizeof(char));
    }
    set.size = INITIAL_SIZE;
    set.ptr = 0;
    return set;
}

int getLength(set_t* set){
    return set->size;
}

int getLastIndex(set_t* set) {
    int i = 0;
    while ( i < getLength(set) - 1) {
        if (strcmp(set->el[i],"") == 0) {
            break;
        }
        i++;
    }
    return i;
}

bool isEmpty(set_t* set){
    for(int i = 0; i < getLength(set) ; i++){
        if(strcmp(set->el[i],"") != 0){
            return true;
        }
    }
    return false;
}

char** copyElements(set_t* set, int lastIndex) {
    char** output = calloc(lastIndex+1,sizeof(char*));
    for (int i = 0; i <= lastIndex; i++) {
        output[i] = calloc(STRING_SIZE,sizeof(char));
        strcpy(output[i],set->el[i]);
    }
    return  output;
}


void resizeSet(set_t* set){
    int length = getLength(set);
    int lastIndex = getLastIndex(set);
    if(lastIndex == length - 1 ){
        char** tmp = copyElements(set,lastIndex);
        free(set->el);
        set->el = calloc(set->size*2,sizeof(char*));
        for (int i = 0; i <= lastIndex; i++) {
            set->el[i] = calloc(STRING_SIZE,sizeof(char));
            strcpy(set->el[i],tmp[i]);
        }
        free(tmp);
        for (int i = lastIndex+1 ; i < length*2 ; i++) {
            set->el[i] = calloc(STRING_SIZE,sizeof(char));
        }
        set->size*=2;
    }else if(lastIndex < length/2 && length > 2){
        for (int i = length/2 ; i < length ; i++) {
            free(set->el[i]);
        }
        set->size/=2;
    }
 }

bool contains(set_t* set, char* el){
    for(int i = 0; i < getLength(set) ; i++){
        if(strcmp(set->el[i],el) == 0){
            return true;         
        } 
    }
    return false;
}

void addElem(set_t* set, elem el){
    if(!contains(set,el)){
        resizeSet(set);
        for(int i = 0; i < getLength(set); i++){
            if(strcmp(set->el[i],"") == 0){
                strcpy(set->el[i],el);
                break;
            }
        }
    }
}

void removeElem(set_t* set, elem el){
    if(contains(set,el)){
        int length = getLength((set));
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
        resizeSet(set);
    }
}

void printSet(set_t set){
    int lastIndex = getLastIndex(&set);
    printf("[ ");
    for( int i = 0; i < lastIndex; i++){
        if (strcmp(set.el[i],"") == 0) break;
        printf("%s%s",set.el[i],(i < lastIndex-1) ? ", " : "");
    }
    printf(" ]\n");
}