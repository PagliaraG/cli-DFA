#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define INITIAL_SIZE 2
#define STRING_SIZE 10

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

bool isEmpty(set_t* set){
    for(int i = 0; i < getLength(set) ; i++){
        if(strcmp(set->el[i],"") != 0){
            return true;
        }
    }
    return false;
}

void resizeSet(set_t* oldSet){
    int length = getLength(oldSet);
    unsigned int trueLength = 0;
    for(int i = 0; i < length ; i++){
        if(strcmp(oldSet->el[i],"") == 0){
            trueLength = i;
        }
    }
    if(trueLength < length/2){
        oldSet->size/=2;
        oldSet = realloc(oldSet,sizeof(char*)*oldSet->size);
    } else if(trueLength == length){
        oldSet->size*=2;
        oldSet = realloc(oldSet,sizeof(char)*oldSet->size);
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
        for( int i = 0; i < getLength(set); i++){
            if(strcmp(set->el[i],el) == 0){
                free(set->el[i]);
                break;
            }
        }
        //resizeSet(set);
    }
}

void printSet(set_t set){
    int length = getLength(&set);
    printf("[ ");
    for( int i = 0; i < length; i++){
        printf("%s%s",set.el[i],(i < length-1) ? ", " : "");
    }
    printf(" ]\n");
}


/*
char* getFirst(set_t* set){
    set->ptr = 0;
    return set->el[0];
}

char* getNext(set_t* set){
    if(strcmp(set->el[set->ptr+1],NULL) == 0){
        return set->el[set->ptr];
    }else{
        return set->el[++set->ptr];
    }   
}
    */