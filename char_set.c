#include "stdbool.h"

typedef char elem;
typedef elem set;


set *createSet(){
    elem el[2] = {"\0"};
    set set[2] = {el};
    return set;
}

bool isEmpty(set* set){
    int length = sizeof(set) / sizeof(set[0]);
    for(int i = 0; i < length ; i++){
        if(!strcmp(set[i],"\0")){
            return true;
        }
    }
    return false;
}

set* resizeSet(set* oldSet){
    int length = sizeof(oldSet) / sizeof(oldSet[0]);
    set newLongSet[length*2];
    set newShortSet[length/2];
    for(int i = 0; i < length ; i++){
        newLongSet[i] = oldSet[i];
        if(i < length / 2){
            newShortSet[i] = oldSet[i];
        }
        if(strcmp(oldSet[i],"\0")){
            if(i < (length / 2)){
                return newShortSet;
            } else{
                return oldSet;
            }
        }
    }
    return newLongSet;
}

bool contains(set *set, char* el){
    int length = sizeof(set) / sizeof(set[0]);
    for(int i = 0; i < length ; i++){
        if(strcmp(set[i],el)){
            return true;         
        } 
    }
    return false;
}

set* add(set* set, elem el){
    if(!contains(set,el)){
        set = resizeSet(set);
        int length = sizeof(set) / sizeof(set[0]);
        for( int i = 0; i < length; i++){
            if(strcmp(set[i],"\0")){
                set[i] = el;
                break;
            }
        }
    }
    return set;
}

set* remove(set* set, elem el){
    if(contains(set,el)){
        int length = sizeof(set) / sizeof(set[0]);
        for( int i = 0; i < length; i++){
            if(strcmp(set[i],el)){
                set[i] = "\0";
                break;
            }
        }
        set = resizeSet(set);
    }
    return set;
}