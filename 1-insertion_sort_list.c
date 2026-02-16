#include "sort.h"

/**
 * insertion_sort_list - Sorts a doubly linked list of integers
 * in ascending order using the Insertion sort algorithm.
 * @list: Double pointer to the head of the doubly linked list.
 *
 * Description: Swaps the nodes themselves, not the integer values.
 * Prints the list after each swap.
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *iter, *insert, *temp;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;

	iter = (*list)->next;
	while (iter != NULL)
	{
		temp = iter->next;
		insert = iter->prev;
		while (insert != NULL && iter->n < insert->n)
		{
			/* Swap logic */
			insert->next = iter->next;
			if (iter->next != NULL)
				iter->next->prev = insert;

			iter->prev = insert->prev;
			iter->next = insert;

			if (insert->prev != NULL)
				insert->prev->next = iter;
			else
				*list = iter;

			insert->prev = iter;

			/* Print list after swap */
			print_list(*list);

			/* Update insert pointer to check previous node */
			insert = iter->prev;
		}
		iter = temp;
	}
}
