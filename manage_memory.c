#include "sort.h"
/**
 * _malloc - Allocates memory for array
 * @length: lengh of array to allocate
 *
 * Return: array with allocated memory
 */
int *_malloc(int length)
{
	int *new_array;

	new_array = malloc(sizeof(int) * length);
	if (!new_array)
		return (NULL);
	return (new_array);
}
/**
 * free_array - Frees memory allocated by array
 * @array: array to free
 */
void free_array(int *array)
{
	free(array);
}
