#ifndef         BST
#define         BST

#include <stdio.h>
#include <stdlib.h>
#define MAX(a, b)       (a>b?a:b)
typedef struct bst bst;

bst*    new_bst(int data);
int     height_bst(bst* t);
void    insert_bst(bst* t, int data);
void    free_bst(bst* t);

#endif