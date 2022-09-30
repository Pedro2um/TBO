//
// Created by user on 9/27/2022.
//
#include "item.h"
#include <stdio.h>
#include <stdlib.h>


void sort(Item* a, int lo, int hi){
    for(int i = lo; i <= hi; i++) {
        for (int i = lo; i <= hi; i++) {
            for (int j = i + 1; j <= hi && less(a[j], a[i]); j++) {
                exch(a[i], a[j]);
            }
        }
    }
}