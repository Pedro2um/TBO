#include <stdio.h>
#include <stdlib.h>
#include "item.h"
#define		push2(A,B)	push(A);push(B)
#define		CUTOFF	8
#define 	MAX_STACK	10000001
typedef struct stack stack;
struct stack{
	Item s[MAX_STACK+1];
	int top_ptr;
};

stack local;

static void stack_init(){
	local.top_ptr = -1;
}

static void push(Item a){
	if(local.top_ptr + 1 <= MAX_STACK) {	
		local.top_ptr++;
		local.s[local.top_ptr] = a;
	}
	else exit(1);
}

static Item pop(){
	if(local.top_ptr >= 0){
		local.top_ptr--;	
		return local.s[local.top_ptr+1];
	}
	else exit(1);
}

static int stack_empty(){
	if(local.top_ptr == -1) return 1;
	return 0;	
}

static void stack_finish(){
	local.top_ptr = -1;
}


void quick_sort_topdown(Item* a, int lo, int hi);

void quick_sort_topdown_cutoff(Item* a, int lo, int hi);

void quick_sort_topdown_median_of_three(Item* a, int lo, int h);

void quick_sort_topdown_median_of_three_and_cutoff(Item* a, int lo, int hi);

void quick_sort_bottom_up(Item* a, int lo, int hi);

void quick_sort_bottom_up_median_of_three_and_cutoff(Item* a, int lo, int hi);

void insertion_sort(Item* a, int lo, int hi);


void sort(Item* a, int lo, int hi){
        quick_sort_bottom_up(a, lo, hi);
}

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

int partition(Item* a, int lo, int  hi){
	int i = lo, j = hi+1;
	int pivot = a[lo];
	while(1){
		while(less(a[++i], a[lo]))
			if(i==hi) break;
		while(less(a[lo],a[--j]))
			if(j==lo) break;
		if(i >= j) break;
		exch(a[i],a[j]);
	}
	exch(a[lo], a[j]);
	return j;	
}

//Version 1

void quick_sort_topdown(Item* a, int lo, int hi){
        if(hi <= lo){
                return; 
        }
        int j = partition(a, lo, hi);
        quick_sort_topdown(a, lo, j-1);
        quick_sort_topdown(a, j+1, hi);
}

//Version 2

void quick_sort_topdown_cutoff(Item* a, int lo, int hi){
	if(hi <= lo){
		return;
	}
	else if( hi <= lo + CUTOFF - 1 ){
		insertion_sort(a, lo, hi);
		return;
	}
	int j = partition(a, lo, hi);
        quick_sort_topdown_cutoff(a, lo, j-1);
        quick_sort_topdown_cutoff(a, j+1, hi);
	
}

//Version 3

void quick_sort_topdown_median_of_three(Item* a, int lo, int hi){

	if(hi <= lo){
                return; 
        }
	Item v = a[lo];
	
	int lt = lo, gt = hi, i = lo;

	while(i <= gt){
		if(a[i] < v){
			exch(a[lt], a[i]);
			lt++;
			i++;
		}
		else if(a[i] > v){
			exch(a[i], a[gt]);
			gt--;
		}
		else {
			i++;
		}
	}

        int j = partition(a, lo, hi);
        quick_sort_topdown_median_of_three(a, lo, j-1);
        quick_sort_topdown_median_of_three(a, j+1, hi);
	
}

//Version 4

void quick_sort_topdown_median_of_three_and_cutoff(Item* a, int lo, int hi){

	if(hi <= lo){
                return; 
        }
	else if( hi <= lo + CUTOFF - 1 ){
		insertion_sort(a, lo, hi);
		return;
	}

	Item v = a[lo];
	
	int lt = lo, gt = hi, i = lo;

	while(i <= gt){
		if(a[i] < v){
			exch(a[lt], a[i]);
			lt++;
			i++;
		}
		else if(a[i] > v){
			exch(a[i], a[gt]);
			gt--;
		}
		else {
			i++;
		}
	}

        int j = partition(a, lo, hi);
        quick_sort_topdown_median_of_three_and_cutoff(a, lo, j-1);
        quick_sort_topdown_median_of_three_and_cutoff(a, j+1, hi);
	
}

//Version 5
void quick_sort_bottom_up(Item* a, int lo, int hi){
	stack_init();
	push2(lo,hi);
	while(stack_empty() == 0){
		lo = pop();
		hi = pop();
		if(hi <= lo) continue;
		int i = partition(a, lo, hi);
		if( (i-lo) > (hi-i) ){
			push(lo);
			push(i-1);
			
			push(i+1);
			push(hi);
		}
		else {
			push(i+1);
			push(hi);

			push(lo);
			push(i-1);

		}
	}
	stack_finish();	
}


