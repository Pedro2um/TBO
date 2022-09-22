#include <stdio.h>
#include <time.h>
#include "bst.h"
int main(){
        srand(time(NULL));
        bst* t = new_bst(0);
        int n;
        scanf("%d", &n);
        for(int i = 1; i < n; i++){
                insert_bst(t, rand());
                //puts("k");
        }
        printf("%d\n", height_bst(t));
        free_bst(t);
        return 0;
}