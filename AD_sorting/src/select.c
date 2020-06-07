#include "select.h"

#include "swap.h"
#include <stdio.h>
void selection_sort_call(void *A,int i,int j, 
                    const size_t elem_size, 
                    total_order leq)
{

    for(int q = j;q>i;q--){
       
        int max_w = 0;
        
        for(int w= i+1;w<q+1;w++){
            
            if(leq(A+max_w*elem_size,A+w*elem_size))
                max_w = w;
        
        }
        swap(A+q*elem_size,A+max_w*elem_size,elem_size);
    }
    
}


int pivot_select_call(void *A, int l_0,int r_0, 
                       const size_t elem_size, 
                       total_order leq)
{
   int l = l_0;
   int r = r_0;

   if ( (r-l) <= 10){
       //We call regular quicksort
        selection_sort_call(A,l,r, 
                 elem_size, leq);
        return (l+r)/2;
        
    }
   
    int chunks = (r-l)/5;
    
    for(size_t c = 0; c < chunks;c++){
        
        int c_l=  l+1+c*5 -1;
        int c_r = l+ 5 +c*5 -1; 
        
        //we call recursively quick_sort_select_call
        selection_sort_call(A, c_l, c_r, elem_size,leq);
        swap(A+(c_l + 2)*elem_size,A+(l+c)*elem_size,elem_size);
    
    }

    return select_index_call(A, l,l+chunks-1,l+chunks/2,elem_size,leq);
                     
}

int select_index_call(void *A, int l_0,int r_0,
                          const int i,
                          const size_t elem_size, 
                          total_order leq)
{
    int r = r_0;
    int l = l_0;
    
    if (r-l <= 10){
        //we call regular selectionsort
        selection_sort_call(A,l,r, 
                 elem_size, leq);
        return i;
    }

    int j = pivot_select_call(A,l,r,elem_size,leq);
    int left_piv,right_piv;
    partition(A,l,r,j,elem_size,leq,&left_piv,&right_piv);

    if (i <= right_piv && i>= left_piv)
        return right_piv;

    if (i<left_piv)
        return select_index_call(A,l,left_piv-1,i,elem_size,leq);

   return select_index_call(A,right_piv+1,r,i,elem_size,leq);
	
}


int select_index(void *A, const unsigned int n, 
                          const int i,
                          const size_t elem_size, 
                          total_order leq)
{   
    //we just call and start recursion
    return select_index_call(A, 0,n-1,
                        i,
                        elem_size, 
                        leq);
 
}


void quick_sort_select_call(void *A, int l_0,int r_0, 
                const size_t elem_size, 
                total_order leq){
                     
int l = l_0;
int r = r_0;

    while(l<r){

        int piv = pivot_select_call(A, l,r, elem_size, leq);                
        
        int left_piv,right_piv;
        partition(A, l, r, piv,elem_size,leq,&left_piv,&right_piv);
        
        //recursive call
        quick_sort_select_call(A ,l,left_piv-1,
                elem_size, 
                 leq);
    
        l =right_piv+1;
    
    }

}
void quick_sort_select(void *A, const unsigned int n, 
                       const size_t elem_size, 
                       total_order leq)
{

    //printf("CALLED\n");
    /*
    selection_sort_call(A,0+5,n/2, 
                     elem_size, 
                    leq);
    selection_sort_call(A,n/2+1,n-5, 
                     elem_size, 
                    leq);
                    */
    quick_sort_select_call(A,0,n-1, 
                elem_size, 
                leq);
    
}