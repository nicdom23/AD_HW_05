#include "heap_sort.h"
#include "binheap.h"
#include <string.h>

//#include </usr/lib/libbinheap.so>
void heap_sort(void *A, const unsigned int n, 
               const size_t elem_size, 
               total_order leq)
{
    //We need a new array if we want not to destroy the heap indexes sense 
    // while we extract the minimum and memorize it into A
    void *B =malloc(n*elem_size);
    for(size_t i = 0;i<n;i++)
        memcpy(B+i*elem_size,A+i*elem_size,elem_size);
    
    binheap_type *heapA=build_heap(B,n,n,elem_size,leq);//build maxheap
    
    for(size_t i = 0;i<n;i++){
        if(!is_heap_empty(heapA)){

            memcpy(A+i*elem_size,extract_min(heapA),elem_size);

        }
    }
    
    
    delete_heap(heapA);
    free(B);
}