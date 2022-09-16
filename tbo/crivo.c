//
// Created by user on 9/16/2022.
//
#include "crivo.h"

void mark(char* arr, int size, int curr){
    for(int i = 2; curr*i < size; i++){
        arr[curr*i] = 1;
    }
}

int find_unmarked(char* arr, int size, int curr){
    for(int i = curr; i < size; i++){
        if(arr[i] == 0) return i;
    }
    return -1;
}

