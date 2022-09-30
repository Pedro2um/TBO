#include <stdio.h>
#include <time.h>
#include "bst.h"
#include "stack.h"
#include "queue.h"


int main(){
        srand(time(NULL));
        bst* t = new_bst(0);
        int n;

        scanf("%d", &n);
        //stack* s = new_stack(n);

        for(int i = 0; i < n; i++){
                int x;
                scanf("%d", &x);
               
                insert_bst(t, x);
                //enqueue(q, new_bst(x));

                //push(s, x);
                //printf("STACK : %d\n", top(s));
                //pop(s);
                //puts("k");
        }
        //travel_queue(q);
        rec_preorder(t, print);
        puts("\n\n");
        //itr_levelorder(t, print);
        /*clock_t start = clock();

        rec_preorder(t, print);

        clock_t end = clock();

        

        fprintf(stderr, "REC_PREORDER %lf\n", (double)(end - start) / CLOCKS_PER_SEC);

        /// @brief ////////////////////////////////////////////////////////
        /// @return 

        start = clock();

        rec_inorder(t, print);

        end = clock();

        fprintf(stderr, "REC_INORDER %lf\n", (double)(end - start) / CLOCKS_PER_SEC);

        /// @brief /////////////////////////////////////////////////////////
        /// @return 

        start = clock();

        rec_postorder(t, print);

        end = clock();

        

        fprintf(stderr, "REC_POSTORDER %lf\n", (double)(end - start) / CLOCKS_PER_SEC);

        /// @brief ////////////////////////////////////////////////////////
        /// @return 

        //////////////////////////////////////////////////////////////////////////////
        //////////////////////////////////////////////////////////////////////////////
        //////////////////////////////////////////////////////////////////////////////
        //////////////////////////////////////////////////////////////////////////////
        //////////////////////////////////////////////////////////////////////////////
        //////////////////////////////////////////////////////////////////////////////

        start = clock();

        itr_preorder(t, print);

        end = clock();

        
        fprintf(stderr, "ITR_PREORDER %lf\n", (double)(end - start) / CLOCKS_PER_SEC);

        /// @brief ////////////////////////////////////////////////////////
        /// @return 

        start = clock();

        itr_inorder(t, print);

        end = clock();

        fprintf(stderr, "ITR_INORDER %lf\n", (double)(end - start) / CLOCKS_PER_SEC);

        /// @brief /////////////////////////////////////////////////////////
        /// @return 

        start = clock();

        itr_postorder(t, print);

        end = clock();



        fprintf(stderr, "ITR_POSTORDER %lf\n", (double)(end - start) / CLOCKS_PER_SEC);

        /// @brief ////////////////////////////////////////////////////////
        /// @return
       */
        

        //free_bst(t);
        
        //free_stack(s);
        return 0;
}