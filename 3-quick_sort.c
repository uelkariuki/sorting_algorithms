#include "sort.h"
#include "swap.c"

/**
 * partition- function to find the correct index of the pivot
 * @array: the array to be sorted
 * @low: the firs index
 * @high: the last index
 * Return: the correct index of the pivot
 */

int partition(int *array, int low, int high)
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
		}

	}
	swap(&array[i + 1], &array[high]);
	return (i + 1);
}

/**
 * quick- recursive helper function to sort the array
 * @array: array to be sorted
 * @low: first index
 * @high: last index
 */

void quick(int *array, int low, int high)
{
	int pivot_idx;

	if (low < high)
	{
		pivot_idx = partition(array, low, high);
		print_array(array, 10);
		quick(array, low, pivot_idx - 1);
		quick(array, pivot_idx + 1, high);

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
	int n;

	n = size;

	if (n < 2)
		return;

	quick(array, 0, size - 1);
}
