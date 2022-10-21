#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <sys/time.h>
#include "item.h"
#include "stack.h"
#define		push2(P,A,B)	push(P,B);push(P,A)
#define		CUTOFF	8




void quick_sort_topdown(Item* a, int lo, int hi);

void quick_sort_topdown_cutoff(Item* a, int lo, int hi);

void quick_sort_topdown_median_of_three(Item* a, int lo, int h);

void quick_sort_topdown_median_of_three_and_cutoff(Item* a, int lo, int hi);

void quick_sort_bottom_up(Item* a, int lo, int hi);

void quick_sort_bottom_up_median_of_three_and_cutoff(Item* a, int lo, int hi);

void quick_sort_bottom_up_median_of_three_and_cutoff_shuffle(Item* a, int lo, int hi);

void insertion_sort(Item* a, int lo, int hi);
void shuffle(Item *a, int N);

void sort(Item* a, int lo, int hi){
        quick_sort_bottom_up_median_of_three_and_cutoff(a, lo, hi);
}


void shuffle(Item *a, int N){

	struct timeval tv; gettimeofday(&tv, NULL);
	srand48(tv.tv_usec);
	for (int i = N-1; i > 0; i--) {
		int j = (unsigned int) (drand48()*(i+1));
		exch(a[i], a[j]);
	}
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
	stack* p = stack_init();

	push2(p,lo,hi);
	while(stack_empty(p) == 0){
		lo = pop(p);
		hi = pop(p);
		if(hi <= lo) continue;
		int i = partition(a, lo, hi);
		if( (i-lo) > (hi-i) ){
			push2(p,lo,i-1);
			push2(p,i+1,hi);
			
		}
		else {
			push2(p,i+1,hi);
			push2(p,lo,i-1);
			

		}
	}
	stack_finish(p);	
}

//Version 6
void quick_sort_bottom_up_median_of_three_and_cutoff(Item* a, int lo, int hi){
	stack* p = stack_init();

	push2(p,lo,hi);
	while(stack_empty(p) == 0){
		lo = pop(p);
		hi = pop(p);
		if(hi <= lo + CUTOFF - 1) {
			insertion_sort(a, lo, hi);
			continue;
		}

		Item v = a[lo];
	
		int lt = lo, gt = hi, j = lo;

		while(j <= gt){
			if(a[j] < v){
				exch(a[lt], a[j]);
				lt++;
				j++;
			}
			else if(a[j] > v){
				exch(a[j], a[gt]);
				gt--;
			}
			else {
				j++;
			}
		}


		int i = partition(a, lo, hi);
		if( (i-lo) > (hi-i) ){
			push2(p,lo,i-1);
			push2(p,i+1,hi);
			
		}
		else {
			push2(p,i+1,hi);
			push2(p,lo,i-1);
			

		}
	}
	stack_finish(p);
}


//Version 7
void quick_sort_bottom_up_median_of_three_and_cutoff_shuffle(Item* a, int lo, int hi){
	shuffle(a, (hi-lo+1) );
	stack* p = stack_init();

	push2(p,lo,hi);
	while(stack_empty(p) == 0){
		lo = pop(p);
		hi = pop(p);
		if(hi <= lo + CUTOFF - 1) {
			insertion_sort(a, lo, hi);
			continue;
		}

		Item v = a[lo];
	
		int lt = lo, gt = hi, j = lo;

		while(j <= gt){
			if(a[j] < v){
				exch(a[lt], a[j]);
				lt++;
				j++;
			}
			else if(a[j] > v){
				exch(a[j], a[gt]);
				gt--;
			}
			else {
				j++;
			}
		}


		int i = partition(a, lo, hi);
		if( (i-lo) > (hi-i) ){
			push2(p,lo,i-1);
			push2(p,i+1,hi);
			
		}
		else {
			push2(p,i+1,hi);
			push2(p,lo,i-1);
			

		}
	}
	stack_finish(p);
}
