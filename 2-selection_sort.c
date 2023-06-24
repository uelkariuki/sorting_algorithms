#include "sort.h"
#include "swap.c"

/**
 * selection_sort- function that sorts an array of integers in
 * ascending order using the Selection sort algorithm
 * @array: an array to be sorted
 * @size: the size of the array
 *
 */

void selection_sort(int *array, size_t size)
{
	int i, j, n, min_idx;

	n = size;
	if (n < 2)
		return;
	for (i = 0; i < n - 1; i++)
	{
		min_idx = i;

		for (j = i + 1; j < n; j++)
		{
			if (array[j] < array[min_idx])
				min_idx = j;


		}
		if (min_idx != i)
		{
			swap(&array[min_idx], &array[i]);
			print_array(array, size);


		}

	}

}
