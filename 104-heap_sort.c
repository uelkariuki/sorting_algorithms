#include "sort.h"
#include "swap.c"

/**
 *heapify- a function to help in heapifying an array,(largest be at root)
 * @array: the array to be heapified
 * @size: the size of the array
 * @q: the node q
 *
 */

void heapify(int *array, int size, int q)
{
	int largest, left, right;

	largest = q; /* set q as largest elem for now*/

	/*In binary heap, each node has 2 children so to find*/
	/* the left child index of the node at index q*/
	left = 2 * q + 1;
	/*and for the right child index*/
	right = 2 * q + 2;

	if (left < size && array[left] > array[largest])
	{
		largest = left;
	}
	if (right < size && array[right] > array[largest])
	{
		largest = right;
	}

	/*If largest is not at root or root does not have the largest elem*/
	if (largest != q)
	{
		swap(&array[q], &array[largest]);
		print_array(array, size);
		/*doing swap may have affected the max heap so */
		/*recurively call heapify to restore heap*/
		heapify(array, size, largest);
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

	/*if (n < 2)*/
		/*return;*/
	/*build the max heap for the non-leaf nodes*/
	for (q = size / 2 - 1; q >= 0; q--)
	{
		heapify(array, size, q);
	}
	/*the heap sort*/
	for (q = size - 1; q >= 0; q--)
	{
		swap(&array[0], &array[q]); /* the root is at index 0*/
		print_array(array, q);
		heapify(array, q, 0);
		/*q in heapify refering to elements remaining in*/
		/* the sub-array yet to be sorted*/
	}

}
