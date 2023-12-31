#include "sort.h"

/**
 * shell_sort- unction that sorts an array of integers in ascending
 * order using the Shell sort algorithm, using the Knuth sequence
 * @array: the array to be sorted
 * @size: the size of the array
 */

void shell_sort(int *array, size_t size)
{
	int n = size, gap = 1, temp, i, j;

	if (n < 2)
		return;

	while (gap < n / 3)
		gap = gap * 3 + 1;

	while (gap > 0)
	{
		for (i = gap; i < n ; i++)
		{
			temp = array[i];
			j = i;

			while (j >= gap && array[j - gap] > temp)
			{
				array[j] = array[j - gap];
				j -= gap;
			}
			array[j] = temp;
		}
		gap = gap / 3;
		print_array(array, size);
	}

}
