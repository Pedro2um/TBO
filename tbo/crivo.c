//
// Created by user on 9/16/2022.
//
#include "crivo.h"

void mark(char* arr, llu size, llu curr){
    for(llu i = 2; curr*i < size; i++){
        arr[curr*i] = 1;
    }
}

llu find_unmarked(char* arr, llu size, llu curr){
    for(llu i = curr; i < size; i++){
        if(arr[i] == 0) return i;
    }
    return 0;
}
