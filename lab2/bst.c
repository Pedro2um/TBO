
#include "bst.h"
#include "stack.h"
#define MAX_TEMP_STACK 1000
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

int     getdata_bst(bst* t){
        return t->data;
}

size_t  getsize_bst(){
        return  sizeof(bst);
}
void    rec_preorder(bst* t, void (*visit)(bst*)){
        if(t == NULL) return;
        visit(t);
        rec_preorder(t->left, visit);        
        rec_preorder(t->right, visit);  
}
void    rec_inorder(bst* t, void (*visit)(bst*)){
        if(t == NULL) return;
        rec_inorder(t->left, visit);        
        visit(t);
        rec_inorder(t->right, visit);  
}
void    rec_postorder(bst* t, void (*visit)(bst*)){
        if(t == NULL) return;
        rec_postorder(t->left, visit);        
        rec_postorder(t->right, visit);
        visit(t);
}
/*
static void     now(stack* s, bst* t){
        if(t == NULL) return;
        visit(t);
        push(s, t->right);
        push(s, t->left);
        visit(top())
}*/
void    itr_preorder(bst* t, void (*visit)(bst*)){
        stack*  temp = new_stack(MAX_TEMP_STACK);
        bst*    curr = t;
        do{
                while(curr != NULL){
                        visit(curr);
                        //if(curr->left != NULL) push(temp, curr->left);
                        if(curr->right != NULL) push(temp, curr->right);
                        curr = curr->left;        
                }
                curr = top(temp);
                pop(temp);
        }while(!empty_stack(temp));
}

void    free_bst(bst* t){
        if(t == NULL) return;
        free_bst(t->left);
        free_bst(t->right);
        free(t);
}

