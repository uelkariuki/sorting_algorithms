#include "sort.h"
#include "swap.c"

/**
 * partition- function to partition an array using the Lomuto partition scheme
 * @array: the array to be partitioned
 * @low: the firs index of the partition
 * @high: the last index of the partition
 * @size: the size of the array
 * Return: the correct (final) index of the pivot
 */

int partition(int *array, int low, int high, size_t size)
{
	int pivot, i, j;

	pivot = array[high];
	i = low - 1;

	for (j = low; j <= high - 1; j++)
	{
		if (array[j] < pivot)
		{
			i++;
			swap(&array[i], &array[j]);
			if (i != j)
				print_array(array, size);
		}

	}
	swap(&array[i + 1], &array[high]);
	if ((i + 1) != high)
		print_array(array, size);
	return (i + 1);
}

/**
 * quick- recursive helper function to sort the array
 * @array: array to be sorted
 * @low: first index
 * @high: last index
 * @size: the size of the array
 */

void quick(int *array, int low, int high, size_t size)
{
	int pivot_idx;

	if (low < high)
	{
		pivot_idx = partition(array, low, high, size);
		quick(array, low, pivot_idx - 1, size);
		quick(array, pivot_idx + 1, high, size);

	}
}

/**
 * quick_sort- function that sorts an array of integers in
 * ascending order using the Quick sort algorithm
 * @array: the array to be sorted
 * @size: the size of the array
 */

void quick_sort(int *array, size_t size)
{

	if (array == NULL || size < 2)
		return;

	quick(array, 0, size -1 , size);
}
