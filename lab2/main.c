#include <stdio.h>
#include <time.h>
#include "bst.h"
int main(){
        srand(time(NULL));
        bst* t = new_bst(0);
        
        for(int i = 1; i < 10; i++){
                insert_bst(t, rand()); 
        }
        free_bst(t);
        return 0;
}