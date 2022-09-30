//
// Created by user on 9/27/2022.
//
#include "item.h"
#include <stdio.h>
#include <stdlib.h>


void sort(Item* a, int lo, int hi){
    for(int i = lo; i <= hi; i++){
        Item min_element = a[i];
        Item idx = i;
        //fprintf(stderr, "X\n");
        for(int j = i+1; j <= hi; j++){
           if(less(a[j], min_element)){
               min_element = a[j];
               idx = j;
           }
        }
        exch(a[i], a[idx]);
    }
}