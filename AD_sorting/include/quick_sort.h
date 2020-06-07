#ifndef __QUICK_SORT__
#define __QUICK_SORT__

#include <stdlib.h>

#include "total_order.h"

/*************************
 * Functions that performs a G-E-S partition based on the pivot @param piv 
 * on the array @param A from the index @param i to the index @param j. 
 * 
 * Saves the indexes at the extremes of the array into @param left_piv and @param right_piv
 * 
 *****************/
void partition(void*A,int i, int j,int piv,const size_t elem_size,total_order leq,int* left_piv,int* right_piv);
 
/******************
Function for recursive call of regular quick-sort.

Works on the array @param A for the index @param l_0 to the index @param r_0
Picks l_0 as a pivot.
********************/
void quick_sort_call(void *A, int l_0,int r_0, 
                const size_t elem_size, 
                total_order leq);



/**********************************************************************
 * An implementation for the Quick Sort algorithm.
 *
 * This function implements the Quick Sort algorithm to sort an 
 * array of elements whose type is unknown with respect to the total 
 * order implemented by the function `leq`. The resulting permutation 
 * is stored in the input array.
 * If the fuction `leq` costs Theta(1), then the execution of this 
 * function takes time O(n^2)\cap Omega(n \log n) where n is the 
 * number of elements in the array.
 *
 * @param A is the array to be sorted. This array is also used to 
 *          store the output of the function.
 * @param n is the number of element of A.
 * @param elem_size is the type size in bytes of the elements in A.
 * @param leq is the total order to be satisfied by the sorting.
 **********************************************************************/
void quick_sort(void *A, const unsigned int n, 
                const size_t elem_size, 
                total_order leq);

#endif // __QUICK_SORT__