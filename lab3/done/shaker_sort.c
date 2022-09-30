//
// Created by user on 9/27/2022.
//
#include "item.h"
#include <stdio.h>
#include <stdlib.h>
void sort(Item* a, int lo, int hi){
    int flag = 1;
    int l = lo;
    int r = hi;
    while(flag){
        flag = 0;
        for(int i = l; i+1 <= r; i++){
            if(less(a[i+1], a[i])){
                exch(a[i+1], a[i]);
                flag = 1;
            }
        }

        if(!flag) break;

        flag = 0;

        r--;

        for(int i = r; i >= l; i--){
            if(less(a[i+1], a[i])){
                exch(a[i+1], a[i]);
                flag = 1;
            }
        }

        l++;
    }
}