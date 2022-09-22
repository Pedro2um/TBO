
#include "bst.h"

struct bst{
        int data;
        bst* left;
        bst* right;
};

bst*    new_bst(int data){
        bst* t = malloc(sizeof(bst));
        if(t == NULL){
                perror("ERROR IN NEW BST FUNCT\n");
                exit(1);
        }
        t->data = data;
        t->left = NULL;
        t->right = NULL;
}
void    insert_bst(bst* t, int data){
        int  flag = -1;
        bst* prev = t;
        bst* curr = t;
        while(curr != NULL){
                if(data == curr->data) return;
                else if(data < curr->data){
                        flag = 0;
                        prev = curr;
                        curr = curr->left; 
                }
                else {
                        flag = 1;
                        prev = curr;
                        curr = curr->right;
                }
        }

        if(flag == 0)   prev->left = new_bst(data);        
        else            prev->right = new_bst(data); 
}
//int x = 0;
int     height_bst(bst* t){
        if(t == NULL) return 0;
        //printf("%d\n", x++);
        int     lh = height_bst(t->left);
        int     rh = height_bst(t->right);
        return 1 + MAX(lh, rh) ;
}

void    free_bst(bst* t){
        if(t == NULL) return;
        free_bst(t->left);
        free_bst(t->right);
        free(t);
}

