#include <stdbool.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef char* elem;
typedef unsigned int pointer;

typedef struct{
    char el[2][20];
    pointer ptr;
} set_t;

set_t createSet(){
    set_t set;
    for(int i = 0; i < 2;i++){
        strcpy(set.el[i],"\0");
    }
    set.ptr = 0;
    return set;
}

bool isEmpty(set_t set){
    int length = sizeof(set) / sizeof(set.el[0]);
    for(int i = 0; i < length ; i++){
        if(!strcmp(set.el[i],"\0") == 0){
            return true;
        }
    }
    return false;
}

void resizeSet(set_t* oldSet){
    int length = sizeof(oldSet->el) / sizeof(oldSet->el[0]);
    char** cpyElem = malloc(sizeof(char)*2*sizeof(oldSet->el));
    memcpy(cpyElem,oldSet->el,sizeof(oldSet->el));
    for(int i = 0; i < length ; i++){
        if(strcmp(oldSet->el[i],"\0") == 0){
            if(i < (length / 2)){

            }
        }
    }
}

bool contains(set_t set, char* el){
    int length = sizeof(set.el) / sizeof(set.el[0]);
    for(int i = 0; i < length ; i++){
        if(strcmp(set.el[i],el) == 0){
            return true;         
        } 
    }
    return false;
}

void addElem(set_t* set, elem el){
    if(!contains(*set,el)){
        int length = sizeof(set->el) / sizeof(set->el[0]);
        for( int i = 0; i < length; i++){
            if(strcmp(set->el[i],"\0") == 0){
                strcpy(set->el[i],el);
                break;
            }
        }
    }
}

void removeElem(set_t* set, elem el){
    if(contains(*set,el)){
        int length = sizeof(set->el) / sizeof(set->el[0]);
        for( int i = 0; i < length; i++){
            if(strcmp(set->el[i],el) == 0){
                strcpy(set->el[i],"\0");
                break;
            }
        }
    }
}

void printSet(set_t set){
    int length = sizeof(set.el) / sizeof(set.el[0]);
    printf("[ ");
    bool last = false;
    for( int i = 0; i < length; i++){
        printf("%s%s",(i!=0) ? ", " : "" ,set.el[i]);   
    }
    printf(" ]");
}

char* getFirst(set_t* set){
    set->ptr = 0;
    return set->el[0];
}

char* getNext(set_t* set){
    if(strcmp(set->el[set->ptr+1],"\0") == 0){
        return set->el[set->ptr];
    }else{
        return set->el[++set->ptr];
    }
    
}