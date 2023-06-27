#include "sort.h"
#include "swap.c"

/**
 * hoare_partition- function to help partition array using hoare
 * partition scheme
 * @array: the array to be sorted
 * @low: the starting index
 * @high: the ending index
 * @size: the size of the array
 * Return: the partition index
 */

int hoare_partition(int *array, int low, int high, size_t size)
{
	int pivot, i, j;

	pivot = array[high]; /*last elem of the partition*/
	i = low - 1;
	j = high + 1;
	while (1)
	{
		do {
			i++;
		} while (array[i] < pivot);

		do {
			j--;
		} while (array[j] > pivot);

		if (i >= j)
			return (i);
		swap(&array[i], &array[j]);
		print_array(array, size);
	}

}
/**
 * quick_hoare- helper function that sorts an array of integers in
 * ascending order using the Quick sort algorithm
 * @array: the array to be sorted
 * @low: the starting index
 * @high: the ending index
 * @size: the size of the array
 *
 */


void quick_hoare(int *array, int low, int high, size_t size)
{
	int partition_idx;

	if (low < high)
	{
		partition_idx = hoare_partition(array, low, high, size);
		quick_hoare(array, low, partition_idx - 1, size);
		quick_hoare(array, partition_idx, high, size);

	}

}
/**
 * quick_sort_hoare- function that sorts an array of integers in
 * ascending order using the Quick sort algorithm
 * @array: the array to be sorted in ascending order
 * @size: the size of the array
 *
 */

void quick_sort_hoare(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;

	quick_hoare(array, 0, size - 1, size);

}


