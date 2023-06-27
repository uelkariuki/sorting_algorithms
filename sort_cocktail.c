#include "sort.h"
#include <stdio.h>
void cocktail_sort_list(listint_t **list)
{
	listint_t *start = *list, *current, *prev, *next, *next_node;
	int swapped = 1;

	while (swapped)
	{
		next_node = start->next;
		current = start;
		while (current->next != NULL)
		{
			prev = current->prev;
			next = current->next;
			if (current->n > next->n)
			{
				if (prev != NULL)
					prev->next = next;
				else
					*list = next;
				next->prev = prev;
				current->next = next->next;
				if (next->next != NULL)
					next->next->prev = current;
				next->next = current;
				current->prev = next;
				print_list(*list);
				continue;
					
			}
			current = current->next;
		}
		if (!swapped)
			break;
		swapped = 0;
		current = current->prev;
		while (current->prev != NULL)
		{
			prev = current->prev;
			next = current->next;
			if (current->n < prev->n)
			{
				prev->next = next;
				if (next != NULL)
					next->prev = prev;
				current->prev = prev->prev;
				if (prev->prev != NULL)
					prev->prev->next = current;
				else
					*list = current;
				current->next = prev;
				prev->prev = current;
				print_list(*list);
				swapped = 1;
				continue;
			}
			current = current->prev;
		}
		start = next_node;
	}
}

