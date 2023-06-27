#include <stdlib.h>
#include <stdio.h>
#include "sort.h"
#include "manage_memory.c"
/**
 * fill_subarray - copies from array to subarray upto a certain
 * limit or length of subarray
 * @array: Array to fill form
 * @subarray: array to fill to
 * @length: length to fill upto
 * @index: index of where to start from array
 *
 * Return: sub array
 */
void fill_subarray(int *array, int *subarray, int length, int index)
{
	int i;

	for (i = 0; i < length; i++)
		subarray[i] = array[index + i];
}
/**
 * merge_sorted - Merges two sorted arrays
 * @array: Array to merge
 * @l: index of the leftmost element
 * @m: index of the middle element
 * @r: index of the rightmost element
 */
void merge_sorted(int *array, int l, int m, int r)
{
	int i, j, k, length_left = m - l + 1, length_right = r - m;
	int *array_left, *array_right;

	array_left = _malloc(length_left + length_right);

	if (!array_left)
		return;
	array_right = array_left + length_left;

	printf("Merging...\n");

	fill_subarray(array, array_left, length_left, l);
	printf("[left]: ");
	print_array(array_left, length_left);

	fill_subarray(array, array_right, length_right, m + 1);
	printf("[right]: ");
	print_array(array_right, length_right);

	for (i = 0, j = 0, k = l; k <= r; k++)
	{
		if ((i < length_left) &&
		((j >= length_right) || (array_left[i] <= array_right[j])))
		{
			array[k] = array_left[i];
			i++;
		}
		else
		{
			array[k] = array_right[j];
			j++;
		}
	}

	printf("[Done]: ");
	print_array(array + l, r - l + 1);
	free_array(array_left);
}
/**
 * merge_sort_recursion - Splits an array into subarrays using
 * the middle of array and calls itself to sort the subarrays recursively
 * until only one element is left
 * @array: Array to be sorted
 * @l: Index of the leftmost element
 * @r: Index of the rightmost element
 */
void merge_sort_recursion(int *array, int l, int r)
{
	int m;

	if (l < r)
	{
		m = l + (r - l - 1) / 2;

		merge_sort_recursion(array, l, m);
		merge_sort_recursion(array, m + 1, r);

		merge_sorted(array, l, m, r);
	}
}
/**
 * merge_sort - calls the recursive merge function
 * @array: array to be sorted
 * @size: size of the array
 */
void merge_sort(int *array, size_t size)
{
	int n = size;

	if (n < 2)
		return;
	merge_sort_recursion(array, 0, size - 1);
}
