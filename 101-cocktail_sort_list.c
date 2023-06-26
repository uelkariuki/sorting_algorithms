#include "sort.h"
/**
 * swap_nodes - Swaps two nodes
 * @list: list to swap the nodes
 * @a: first node
 * @b: second node
 */
void swap_nodes(listint_t **list, listint_t *a, listint_t *b)
{
	listint_t *prev_a, *next_b;

	prev_a = a->prev;
	next_b = b->next;
	a->next = next_b;
	if (next_b != NULL)
		next_b->prev = a;
	b->prev = prev_a;
	if (prev_a != NULL)
		prev_a->next = b;
	else
		*list = b;
	b->next = a;
	a->prev = b;
}
/**
 * cocktail_sort_list - Sorts a list using bi-directional bubble sort
 * @list: list to be sorted
 */
void cocktail_sort_list(listint_t **list)
{
	listint_t *current, *prev, *first = NULL, *last = NULL;
	int swapped = 1;

	if (!list || !(*list) || !((*list)->next))
		return;
	current = *list;
	while (swapped)
	{
		swapped = 0;
		while (current->next != last)
		{
			if (current->n > current->next->n)
			{
				swap_nodes(list, current, current->next);
				swapped = 1;
				print_list(*list);
			}
			else
				current = current->next;
		}
		if (!swapped)
			break;
		swapped = 0;
		last = current;
		current = last->prev;
		while (current->prev != first)
		{
			prev = current->prev;
			if (current->n < prev->n)
			{
				swap_nodes(list, prev, current);
				swapped = 1;
				print_list(*list);
			}
			else
				current = current->prev;
		}
		first = current;
		current = first->next;
	}
}
