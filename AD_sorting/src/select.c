#include "select.h"

#include "swap.h"
#include <stdio.h>
unsigned int pivot_select_call(void *A, int l_0,int r_0, 
                       const size_t elem_size, 
                       total_order leq)
{
   int l = l_0;
   int r = r_0;

   if (r-l <= 10){
       //We call regular quicksort
        quick_sort_call(A,l,r, 
                 elem_size, leq);
        return (l+r)/2;
        
    }
   
    int chunks = (r-l)/5;
    
    
    printf("\nSTEP2 , %d , %d, %d \n",chunks, r,l);
    for(size_t c = 0; c < chunks;c++){
        //printf("\nSTEP3 %d \n  ",(-1)/5);
        int c_l = 1+c*5 -1;
        int c_r = 5 +c*5 -1; 
      
        if (c_l<(1<<10)&&c_r<(1<<10)){
        quick_sort_call(A, c_l,c_r, 
                elem_size,leq);
        swap(A+(c_l + 2)*elem_size,A+(l+c)*elem_size,elem_size);
        }
    }

    return select_index_call(A, l,l+chunks-1,
                        chunks/2,
                        elem_size, 
                        leq);
}

unsigned int select_index_call(void *A, int l_0,int r_0,
                          const unsigned int i,
                          const size_t elem_size, 
                          total_order leq)
{
    printf("\nSTEP1\n");
    int r = r_0;
    int l = l_0;
    
    if (r-l <= 10){
        //we call regular quicksort
        quick_sort_call(A,l,r, 
                 elem_size, leq);
        return i;
    }

    int j = pivot_select_call(A,l,r,elem_size,leq);
    int k =partition(A,l,r,j,elem_size,leq);

    if (i == k)
        return k;

    if (i<k )
        return select_index_call(A,l,k-1,i,elem_size,leq);

   return select_index_call(A,k+1,r,i,elem_size,leq);
	
}







unsigned int select_index(void *A, const unsigned int n, 
                          const unsigned int i,
                          const size_t elem_size, 
                          total_order leq)
{
    select_index_call(A, 0,n-1,
                        i,
                        elem_size, 
                        leq);
    return 0;	
}


void quick_sort_select_call(void *A, int l_0,int r_0, 
                const size_t elem_size, 
                total_order leq){
                     printf("\nSelect Quicksort called\n");
int l = l_0;
int r = r_0;

    while(l<r){

        int piv = pivot_select_call(A, l,r, 
                       elem_size, 
                        leq);


        piv = partition(A, l, r, piv,elem_size,leq);
        
         
            quick_sort_call(A,  l,piv-1,
                elem_size, 
                 leq);
    
        l = piv+1;

    }

}
void quick_sort_select(void *A, const unsigned int n, 
                       const size_t elem_size, 
                       total_order leq)
{
    quick_sort_select_call(A,0,n-1, 
                elem_size, 
                leq);
   

}