#include <stdio.h>
#include <limits.h>
#include <stdlib.h>
#include "item.h"
#define  CUTTOFF        16

void insertion_sort(Item* a, int lo, int hi){
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

void sort(Item* a, int lo, int hi){
        Item* aux = malloc((hi-lo+1)*sizeof(Item));
        if(aux==NULL) exit(1);
        merge_sort_top_down_cut_off_and_skip(a, aux, lo, hi);
        free(aux);
}

// Version 1

void merge1(Item* a, Item* aux, int lo, int m, int hi){
        for(int k = lo; k <= hi; k++)
                aux[k] = a[k];
        for(int k = lo, i = lo, j = m+1; k <= hi; k++){
                        if(i > m)                        a[k] = aux[j++];
                else    if(j > hi)                       a[k] = aux[i++];
                else    if(less(a[j], a[i]))             a[k] = aux[j++];
                else                                     a[k] = aux[i++];
        }
}

void merge_sort_top_down(Item* a, Item* aux, int lo, int hi){
        if(hi<=lo) return;
        int m = lo + (hi-lo)/2;
        merge_sort_top_down(a, aux, lo, m);
        merge_sort_top_down(a, aux, m+1, hi);
        merge1(a, aux, lo, m, hi);
}

// Version 2

void merge_sort_top_down_cut_off(Item* a, Item* aux, int lo, int hi){
        if(hi <= lo + CUTTOFF - 1){
                insertion_sort(a, lo, hi);
                return;
        }
        int m = lo + (hi-lo)/2;
        merge_sort_top_down_cut_off(a, aux, lo, m);
        merge_sort_top_down_cut_off(a, aux, m+1, hi);
        merge1(a, aux, lo, m, hi);
}

// Version 3

void merge_sort_top_down_skip(Item* a, Item* aux, int lo, int hi){
        if(hi<=lo) return;
        int m = lo + (hi-lo)/2;
        merge_sort_top_down_skip(a, aux, lo, m);
        merge_sort_top_down_skip(a, aux, m+1, hi);
        if(!less(a[m+1], a[m])) return;
        merge1(a, aux, lo, m, hi);
}

// Version 4

void merge_sort_top_down_cut_off_and_skip(Item* a, Item* aux, int lo, int hi){
        if(hi <= lo + CUTTOFF - 1){
                insertion_sort(a, lo, hi);
                return;
        }
        int m = lo + (hi-lo)/2;
        merge_sort_top_down_cut_off_and_skip(a, aux, lo, m);
        merge_sort_top_down_cut_off_and_skip(a, aux, m+1, hi);
        if(!less(a[m+1], a[m])) return;
        merge1(a, aux, lo, m, hi);
}