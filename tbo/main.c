#include <stdio.h>
#include "crivo.h"


int main() {
    llu n = 0;

    scanf("%llu", &n);

    char * a = malloc(n*sizeof(llu)); // todos sao primos em um primeiro momento
    if(a == NULL) exit(1);
    a[0] = 1;
    a[1] = 1;

    for(llu curr = 2; find_unmarked(a, n, curr); curr++){
        mark(a, n, curr);
    }
    /*
    for(llu i = 0; i < n; i++){
        printf("%llu %d\n", i, a[i]);
    }
    */
    free(a);
    return 0;
}