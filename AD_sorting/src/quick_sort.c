#include "quick_sort.h"
#include <stdio.h>


void partition(void*A,int i, int j,int piv,const size_t elem_size,total_order leq, int* left_piv,int* right_piv){
    
    swap(A+i*elem_size,A+piv*elem_size,elem_size);
    
    piv = i;
    int last_piv = i;
    i = i+1;

    while(i<=j){
        if(leq(A+piv*elem_size,A+i*elem_size) && leq(A+i*elem_size,A+piv*elem_size)){
         
            
            last_piv = last_piv +1;
            swap(A+i*elem_size,A+last_piv*elem_size,elem_size);
            
            i = i+1; 


        }else if(leq(A+piv*elem_size,A+i*elem_size)){

            swap(A+i*elem_size,A+j*elem_size,elem_size);
            j = j-1;

        }else{
            i = i+1;
        }
    }

    *right_piv = j;
    for (int h = piv ; h<last_piv+1;h++){

        swap(A+h*elem_size,A+j*elem_size,elem_size);
        j = j-1;
    
    }
    *left_piv=j+1;
}

void quick_sort_call(void *A, int l_0,int r_0, 
                const size_t elem_size, 
                total_order leq){
        
int l = l_0;
int r = r_0;

    while(l<r){

        size_t piv = l;

        int left_piv;
        int right_piv;
        partition(A, l, r, piv,elem_size,leq,&left_piv,&right_piv);

        quick_sort_call(A,  l,left_piv-1,
                elem_size, 
                 leq);
        
        l = right_piv+1;
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