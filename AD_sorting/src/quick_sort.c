#include "quick_sort.h"
#include <stdio.h>

int is_ok(size_t i){

    return i>=0 && i<=(1<<10);

}

size_t partition(void*A,int i, int j,int piv,const size_t elem_size,total_order leq){
    swap(A+i*elem_size,A+piv*elem_size,elem_size);
    piv = i;
    i = i+1;

    while(i<=j){
        if(leq(A+piv*elem_size,A+i*elem_size)){
            swap(A+i*elem_size,A+j*elem_size,elem_size);
            j = j-1;
            
        }else{
            i = i+1;
            
        }
    }

    swap(A+piv*elem_size,A+j*elem_size,elem_size);
   
    return j;
}

void quick_sort_call(void *A, int l_0,int r_0, 
                const size_t elem_size, 
                total_order leq){
        
int l = l_0;
int r = r_0;

    while(l<r){

        size_t piv = l;
        piv = partition(A, l, r, piv,elem_size,leq);

        quick_sort_call(A,  l,piv-1,
                elem_size, 
                 leq);
        
        l = piv+1;
    }

}


void quick_sort(void *A, const unsigned int n, 
                const size_t elem_size, 
                total_order leq)
{

    quick_sort_call(A,  0,n-1,
                elem_size, 
                 leq);
    
}