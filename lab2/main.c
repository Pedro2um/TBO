#include <stdio.h>
#include <time.h>
#include "bst.h"
#include "stack.h"



int main(){
        srand(time(NULL));
        bst* t = new_bst(0);
        int n;
        scanf("%d", &n);
        stack* s = new_stack(n);
        for(int i = 0; i < n; i++){
                int x;
                scanf("%d", &x);
                insert_bst(t, x);
                //push(s, x);
                //printf("STACK : %d\n", top(s));
                //pop(s);
                //puts("k");
        }

        rec_preorder(t, print);
        
        puts("\n\n\n");

        itr_preorder(t, print);
        
        free_bst(t);
        free_stack(s);
        return 0;
}