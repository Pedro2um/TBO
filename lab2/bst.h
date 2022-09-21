#ifndef         BST
#define         BST

#include <stdio.h>
#include <stdlib.h>

typedef struct bst bst;

bst*    new_bst(int data);
void    insert_bst(bst* t, int data);
void    free_bst(bst* t);

#endif