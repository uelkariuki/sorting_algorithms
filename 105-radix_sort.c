#include <stdlib.h>
#include "sort.h"
/**
 * find_max - Finds the maximum number from an array
 * @array: to look into
 * @size: size of the array
 *
 * Return: the maximum number
 */
int find_max(int *array, int size)
{
	int i, max = array[0];

	for (i = 1; i < size; i++)
	{
		if (array[i] > max)
			max = array[i];
	}
	return (max);
}
/**
 * count_sort - Function that sorts an array in place value(digit specified)
 * @array: array to sort
 * @size: size of the array
 * @digit: specify the place value to sort like ones, tens etc
 */
void count_sort(int *array, int size, int digit)
{
	int *result;
	int i, count[10] = { 0 };

	result = malloc(sizeof(int) * size);

	if (!result)
		return;

	for (i = 0; i < size; i++)
		count[(array[i] / digit) % 10]++;

	for (i = 1; i < 10; i++)
		count[i] += count[i - 1];
	for (i = size - 1; i >= 0; i--)
	{
		result[count[(array[i] / digit) % 10] - 1] = array[i];
		count[(array[i] / digit) % 10]--;
	}
	for (i = 0; i < size; i++)
		array[i] = result[i];

	free(result);
}
/**
 * radix_sort - a linear sorting algorithm that sorts elements by
 * processing them digit by digit
 * @array: the array to sort
 * @size: size of the array
 */
void radix_sort(int *array, size_t size)
{
	int max, digit, n;

	n = size;
	if (n < 2)
		return;

	max = find_max(array, size);

	for (digit = 1; (max / digit) > 0; digit *= 10)
	{
		count_sort(array, size, digit);
		print_array(array, size);
	}
}
