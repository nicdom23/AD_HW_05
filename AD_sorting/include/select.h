#ifndef __SELECT__
#define __SELECT__

#include <stdlib.h>

#include "total_order.h"

//for partition() and quick_sort_call()
#include "quick_sort.h"
void selection_sort_call(void *A,int i,int j, 
                    const size_t elem_size, 
                    total_order leq);
/******************
Function for Pivot selecting.

Works on the array @param A for the index @param l_0 to the index @param r_0
********************/
int pivot_select_call(void *A, int l_0,int r_0, 
                       const size_t elem_size, 
                       total_order leq);


/******************
Function for recursive call of SELECT.

Works on the array @param A for the index @param l_0 to the index @param r_0
********************/
int select_index_call(void *A, int l_0,int r_0,
                          const  int i,
                          const size_t elem_size, 
                          total_order leq);

/**********************************************************************
 * An implementation for the Select algorithm.
 *
 * This function implements the Select algorithm to identify the 
 * position of the i-th value in an array if it was sorted.
 * The algorithm may destroy the original ordering of the array.
 * If the fuction `leq` costs Theta(1), then the execution of this 
 * function takes time Theta(n) where n is the number of elements 
 * in the array.
 *
 * @param A is the array of which the i-th value should be found. 
 *          The original ordering of the array may be destroyed.
 * @param n is the number of element of A.
 * @param i is the index in the sorted array of the value to be found.
 * @param elem_size is the type size in bytes of the elements in A.
 * @param leq is the total order to be satisfied by the sorting.
 **********************************************************************/
int select_index(void *A, const unsigned int n, 
                          const  int i,
                          const size_t elem_size, 
                          total_order leq);


/******************
Function for recursive call of quick-sort using select.

Works on the array @param A for the index @param l_0 to the index @param r_0
Picks pivot_select_call(A, l,r, elem_size, leq) as a pivot

********************/
void quick_sort_select_call(void *A, int l_0,int r_0, 
                const size_t elem_size, 
                total_order leq);

/**********************************************************************
 * An implementation for the Quick Sort algorithm.
 *
 * This function implements the Quick Sort algorithm to sort an 
 * array of elements whose type is unknown with respect to the total 
 * order implemented by the function `leq`. The resulting permutation 
 * is stored in the input array. The pivot selection is done by using 
 * the function `select` (which takes time O(n)) in order to balance
 * the size of the recursion tree.
 * If the fuction `leq` costs Theta(1), then the execution of this 
 * function takes time \Theta(n \log n) where n is the number of 
 * elements in the array.
 *
 * @param A is the array to be sorted. This array is also used to 
 *          store the output of the function.
 * @param n is the number of element of A.
 * @param elem_size is the type size in bytes of the elements in A.
 * @param leq is the total order to be satisfied by the sorting.
 **********************************************************************/
void quick_sort_select(void *A, const unsigned int n, 
                       const size_t elem_size, 
                       total_order leq);

#endif // __SELECT__