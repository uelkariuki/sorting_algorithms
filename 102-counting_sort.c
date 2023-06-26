#include "sort.h"
#include <stdlib.h>
#include <stdio.h>
/**
 * counting_sort- unction that sorts an array of integers in
 * ascending order using the Counting sort algorithm
 * @array: the array which is to be count sorted
 * @size: the size of the array
 *
 * (do the cumulative of the counter array[1, 2, 3, 4] be [1, 3, 6, 10]
 * so 10 means it is at position 10 (9 elements before it)
 * elem example like: 1, 2, 3, 4 , 2, 3, 4, 3, 4, 4
 */

void counting_sort(int *array, size_t size)
{
	int n, max, a, size_count;
	int *counter, *temp_output;

	n = size;
	if (n < 2)
		return;
	max = array[0]; /*find the largest/ max integer (k)*/
	for (a = 1; a < n; a++)
	{
		if (array[a] > max)
			max = array[a];
	}
	size_count = max + 1;/* counter array of size max (k)+ 1*/
	counter = malloc(size_count * sizeof(int));
	if (counter == NULL)
		return;
	for (a = 0; a < size_count; a++) /*initialize with [0, 0, ...]*/
		counter[a] = 0;
	for (a = 0; a < n; a++) /*how many times an elem is in the array*/
		counter[array[a]]++;
	for (a = 1; a < size_count; a++) /*refer to line 10, 11 and 12 */
	{
		counter[a] = counter[a] + counter[a - 1];
	}
	print_array(counter, size_count); /* print the counting array */
	temp_output = malloc(n * sizeof(int)); /* temp output array*/
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
