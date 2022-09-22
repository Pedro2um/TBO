#include <stdio.h>
#include <time.h>
#include "bst.h"
#include "stack.h"

void    print(bst* t){
        printf("%d\n", getdata_bst(t));
}

int main(){
        srand(time(NULL));
        bst* t = new_bst(0);
        int n;
        scanf("%d", &n);
        stack* s = new_stack(n);
        for(int i = 1; i < n; i++){
                int x = rand()%100;
                insert_bst(t, x);
                //push(s, x);
                //printf("STACK : %d\n", top(s));
                //pop(s);
                //puts("k");
        }

        printf("%d\n", height_bst(t));
        itr_preorder(t, print);
        puts("\n\n\n");
        rec_preorder(t, print);
        /*
        puts("RECURSIVE PRE-ORDER");
        rec_preorder(t, print);

        puts("RECURSIVE IN-ORDER");
        rec_inorder(t, print);

        puts("RECURSIVE POST-ORDER");
        rec_postorder(t, print);
        */
        free_bst(t);
        free_stack(s);
        return 0;
}