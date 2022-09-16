#include <stdio.h>
#include "crivo.h"
int main() {
    int n = 0;

    scanf("%d", &n);

    char * a = calloc(n, sizeof(int)); // todos sao primos em um primeiro momento
    if(a == NULL) exit(1);
    a[0] = 1;
    a[1] = 1;

    for(int curr = 2; find_unmarked(a, n, curr) != -1; curr++){
        mark(a, n, curr);
    }

    for(int i = 0; i < n; i++){
        printf("%d %d\n", i, a[i]);
    }

    return 0;
}
