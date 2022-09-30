//
// Created by user on 9/27/2022.
//
#include "item.h"
#include <stdio.h>
#include <stdlib.h>


void sort(Item* a, int lo, int hi){
    for(int i = lo; i <= hi; i++) {
        for(int j = i+1; j <= hi; j++){
           if(less(a[j], a[i])){
              Item temp = a[j];
              a[j] = a[i];
              int k;
              for(k = i-1; k >= lo && less(temp, a[k]); k--){
                  exch(a[k+1], a[k]);
              }
              a[k + 1] = temp;
           }
        }
    }
}