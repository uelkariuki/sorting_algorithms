#include "sort.h"
#include "swap.c"

/**
 *heapify- a function to help in heapifying an array,(largest be at root)
 * @array: the array to be heapified
 * @size: the size of the array
 * @begin: the node at start
 * @end: node at end
 *
 */

void heapify(int *array, size_t size, size_t begin, size_t end)
{
	size_t largest, left_child, swap_idx;

	largest = begin; /* set begin as largest elem for now*/

	/*In binary heap, each node has 2 children*/

	while (2 * largest + 1 <= end)
	{
		left_child = 2 * largest + 1;
		swap_idx = largest;
		if (array[swap_idx] < array[left_child])
			swap_idx = left_child;

		if (left_child + 1 <= end && array[swap_idx] < array[left_child + 1])
			swap_idx = left_child + 1;

		if (swap_idx == largest)
			return;


	/*If largest is not at root or root does not have the largest elem*/
		swap(&array[largest], &array[swap_idx]);
		print_array(array, size);

		largest = swap_idx;
	}

}

/**
 * heap_sort- function that sorts an array of integers in ascending
 * order using the Heap sort algorithm
 * @array: the array to be sorted
 * @size: the size of the array
 */

void heap_sort(int *array, size_t size)
{
	int q;

	/*build the max heap for the non-leaf nodes*/
	for (q = size / 2 - 1; q >= 0; q--)
	{
		heapify(array, size, q, size - 1);
	}
	/*the heap sort*/
	for (q = size - 1; q > 0; q--)
	{
		swap(&array[0], &array[q]); /* the root is at index 0*/
		print_array(array, size);
		heapify(array, size, 0, q - 1);
		/*q in heapify refering to elements remaining in*/
		/* the sub-array yet to be sorted*/
	}

}
