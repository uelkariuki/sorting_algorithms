#include "sort.h"
#include <stdlib.h>

/**
 * counting_sort- unction that sorts an array of integers in
 * ascending order using the Counting sort algorithm
 * @array: the array which is to be count sorted
 * @size: the size of the array
 *
 */

void counting_sort(int *array, size_t size)
{
	int n, max, a, size_count;
	int *counter, *temp_output;

	n = size;
	if (n < 2 )
		return;
	/*find the largest/ max integer*/
	max = array[0];

	for (a = 1; a < n; a++)
	{
		if (array[a] > max)
			max = array[a];
	}
	size_count = max + 1;/* count array of size max + 1*/
	counter = malloc(size_count * sizeof(int));
	if (counter == NULL)
		return;
	for (a = 0; a < size_count; a++) /*initialize with [0, 0, 0, 0]*/
		counter[a] = 0;
	/* how mamy times an element appeared in the array*/
	for (a = 0; a < n; a++)
		counter[array[a]]++;

	/*do the cumulative of the counter array[1,2, 3, 4] be [1,3,6, 10]*/
	 for (a = 1; a < size_count; a++)
		 counter[a] = counter[a] + counter[a - 1];
	 /* temp output array*/
	 temp_output = malloc(n * sizeof(int));
	 if (temp_output == NULL)
	 {
		 free(counter);
		 return;
	 }
	 for (a = n - 1; a >= 0; a--) /*build the temp_output array*/
	 {
		 temp_output[counter[array[a]] - 1] = array[a];
		 counter[array[a]]--;
	 }
	 for (a = 0; a < n; a++) /* copy sorted elems to original array*/
		 array[a] = temp_output[a];
	 free(counter);
	 free(temp_output);
}
