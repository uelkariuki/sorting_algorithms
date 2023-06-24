#include "sort.h"

/**
 * swap- function to swap two elememts
 * @a: the first element (swap a with b)
 * @b: the second element
 */

void swap(int *a, int *b)
{
	int temp;

	temp = *a;
	*a = *b;
	*b = temp;

}
