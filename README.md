# AD_HW_05
Homework for the course Algorithm design at the DSSC course at the University of Trieste. 2019-2020

03/06/2020

Now to move to the next homework.

--------------------------------------------------------
04/06/2020

I had some issues with underflowing when using size_t variables, so quick_sort, quick_sort_select and select_index use int variables for the indexes.

The sorting algorithm I implemented last was heapsort. I copied libbinheap.so in the folder and I added the adress to CMakeLists.txt. And then it worked. Make correctly imported the library and used it.
However I had to create a secondary array void* B to build the array on. Otherwise the elements of A could have been modified and so the indexes of the heap nodes could have been misdirective. We fill A from left to right and we empty  the heap by leaving all the elements in B in their order. As I said in AD_HW_04 my implementation of binary heaps with no swapping in A does insert new keys in A but does not delete them when we extract.

-------------------------------------------------------

The output of the code is then:
