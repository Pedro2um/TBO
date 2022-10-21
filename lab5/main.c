#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "item.h"
#include <math.h>
#include "stack.h"
extern void sort(Item* a, int lo, int hi);

int main(int argc, char* argv[]){
    //if(argc <= 1) exit(1);
	int N;
    //int N = atoi(argv[1]);
    scanf("%d", &N);
    Item* arr = malloc(N*sizeof(Item));
    for(int i = 0; i < N; i++) scanf("%d", &arr[i]);

    clock_t  start = clock();
    sort(arr, 0, N-1);
    clock_t end = clock();

    double seconds = ((double)end - start) / CLOCKS_PER_SEC;
    printf("Time in seconds = %lf\n", seconds);
    puts("Sorted array");
    for(int i = 0; i < N; i++) printf(" %d", arr[i]);
    puts("");
    
    return 0;
}
