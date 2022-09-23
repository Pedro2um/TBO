
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
void    print(bst* t){
        printf("%d\n", getdata_bst(t));
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
        }while(curr != NULL);
        
        /*if(t == NULL) return;
        push(temp, t);
        while(!empty_stack(temp)){
                curr = top(temp);
                visit(curr);
                pop(temp);
                if(curr->right != NULL)
                        push(temp, curr->right);
                if(curr->left != NULL)
                        push(temp, curr->left);
        }
        */
        free_stack(temp);
}

void    itr_inorder(bst* t, void(*visit)(bst*)){
        stack*  temp = new_stack(MAX_TEMP_STACK);
        bst*    curr = t;
        while(!empty_stack(temp) || curr != NULL){
                //puts("X");
                if(curr != NULL){
                        push(temp, curr);
                        curr = curr->left;   
                        //puts("Y");             
                }
                else{
                        curr = pop(temp);
                        //pop(temp);
                        visit(curr);
                        curr = curr->right;
                        //puts("Z");
                }
        }
        if(empty_stack(temp) == false) perror("DEU RUIM AQUI");
        free_stack(temp);
}

void    itr_postorder(bst* t, void(*visit)(bst*)){
        stack*  temp = new_stack(MAX_TEMP_STACK);
        bst*    last = NULL;
        bst*    curr = t;
        while(!empty_stack(temp) || curr != NULL){
                if(curr != NULL){
                        //puts("X");
                        push(temp, curr);
                        curr = curr->left;
                }
                else{   
                        //puts("Y");

                        bst* peek = top(temp);
                        if(peek != NULL && peek->right != NULL && last != peek->right){
                                curr = peek->right;
                                //puts("Z");
                        }
                        else{
                                //puts("W");
                                if(peek != NULL) visit(peek);
                                last = pop(temp);
                                curr = NULL;
                        }
                }

        }
        
        free_stack(temp);
}

void    free_bst(bst* t){
        if(t == NULL) return;
        free_bst(t->left);
        free_bst(t->right);
        free(t);
}

