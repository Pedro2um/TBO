#ifndef         BST
#define         BST

#include <stdio.h>
#include <stdlib.h>
#define MAX(a, b)       (a>b?a:b)
typedef struct bst bst;

bst*    new_bst(int data);
int     height_bst(bst* t);
size_t  getsize_bst();
int     getdata_bst(bst* t);
void    rec_preorder(bst* t, void (*visit)(bst*));
void    rec_inorder(bst* t, void (*visit)(bst*));
void    rec_postorder(bst* t, void (*visit)(bst*));

void    itr_preorder(bst* t, void (*visit)(bst*));
//void    itr_inorder(bst* t, void (*visit)(bst*));
//void    itr_postorder(bst* t, void (*visit)(bst*));

void    insert_bst(bst* t, int data);
void    free_bst(bst* t);

#endif