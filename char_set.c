#include <stdbool.h>
#include <stdio.h>
#include <string.h>

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
        if(!strcmp(set.el[i],"2")){
            return true;
        }
    }
    return false;
}

set_t resizeSet(set_t oldSet){
    int length = sizeof(oldSet.el) / sizeof(oldSet.el[0]);
    set_t newLongSet;
    newLongSet.el[length*2];
    newLongSet.ptr = oldSet.ptr;
    set_t newShortSet;
    newShortSet.el[length/2];
    newShortSet.ptr = oldSet.ptr;
    for(int i = 0; i < length ; i++){
        strcpy(newLongSet.el[i],oldSet.el[i]);
        if(i < length / 2){
            strcpy(newShortSet.el[i],oldSet.el[i]);
        }
        if(strcmp(oldSet.el[i],"\0")){
            if(i < (length / 2)){
                return newShortSet;
            } else{
                return oldSet;
            }
        }
    }
    return newLongSet;
}

bool contains(set_t set, char* el){
    int length = sizeof(set.el) / sizeof(set.el[0]);
    for(int i = 0; i < length ; i++){
        if(strcmp(set.el[i],el)){
            return true;         
        } 
    }
    return false;
}

set_t addElem(set_t set, elem el){
    if(!contains(set,el)){
        set = resizeSet(set);
        int length = sizeof(set.el) / sizeof(set.el[0]);
        for( int i = 0; i < length; i++){
            if(strcmp(set.el[i],"\0")){
                strcpy(set.el[i],el);
                break;
            }
        }
    }
    return set;
}

set_t removeElem(set_t set, elem el){
    if(contains(set,el)){
        int length = sizeof(set.el) / sizeof(set.el[0]);
        for( int i = 0; i < length; i++){
            if(strcmp(set.el[i],el)){
                strcpy(set.el[i],"\0");
                break;
            }
        }
        set = resizeSet(set);
    }
    return set;
}

void printSet(set_t set){
    int length = sizeof(set.el) / sizeof(set.el[0]);
    printf("[");
    bool last = false;
    for( int i = 0; i < length; i++){
        if(strcmp(set.el[i],"\0")){
            break;
            last = true;
        }
        printf("%s",set.el[i]);
        if(!last){
            printf(" ,");
        }
    }
    printf(" ]");
}

char* getFirst(set_t set){
    set.ptr = 0;
    return set.el[0];
}

char* getNext(set_t set){
    if(strcmp(set.el[set.ptr+1],"\0")){
        return set.el[set.ptr];
    }else{
        return set.el[++set.ptr];
    }
    
}