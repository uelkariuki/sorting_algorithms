#include "sort.h"
/**
 * sort - Sort a node on the right place
 * @list: List to be sorted
 * @current: Node to be inserted
 */
void sort(listint_t **list, listint_t *current)
{
	listint_t *prev, *next;

	prev = current->prev;
	next = current->next;
	while (prev != NULL && current->n < prev->n)
	{
		prev->next = next;
		if (next != NULL)
			next->prev = prev;
		current->next = prev;
		current->prev = prev->prev;
		if (prev->prev != NULL)
			prev->prev->next = current;
		else
			*list = current;
		prev->prev = current;
		prev = current->prev;
		next = current->next;
		print_list(*list);
	}
}
/**
 * insertion_sort_list - Transverses and calls sort on each node
 * @list: List to be sorted
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *current = *list, *next_node;

	while (current)
	{
		next_node = current->next;
		sort(list, current);
		current = next_node;
	}
}
