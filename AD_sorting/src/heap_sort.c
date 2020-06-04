#include "heap_sort.h"
#include <binheap.h>
#include <string.h>
//#include </usr/lib/libbinheap.so>
void heap_sort(void *A, const unsigned int n, 
               const size_t elem_size, 
               total_order leq)
{
    void * B = malloc(n*elem_size);
    for (size_t j= 0;j<n;j++)
        memcpy(B+j*elem_size,A+j*elem_size,elem_size);
    
    //binheap_type *heapA=build_heap(B,n,n,elem_size,leq);//build maxheap

    for (size_t j= 0;j<n;j++){

        //memcpy(A+j*elem_size,extract_min(heapA),elem_size)
    
    }

}