#include <stdio.h>
#include <stdlib.h>
#include "item.h"

extern void sort(Item* a, int lo, int hi);

int main(){

    int N;
    scanf("%d", &N);
    int arr = malloc(sizeof(int));
    for(int i = 0; i < N; i++) scanf("%d", &arr[i]);
    sort(arr, 0, N-1);
    for(int i = 0; i < N; i++) printf("%d ", arr[i]);
    puts("");

    return 0;
}