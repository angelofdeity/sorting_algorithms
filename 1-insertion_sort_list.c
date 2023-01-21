#include "sort.h"
/**
 * insertion_sort_list - sorts a list using insertion sort algo
 * @list: doubly linked list to be sorted
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *current, *temp;

	if (list == NULL || (*list)->next == NULL)
		return;

	current = (*list)->next;
	while (current != NULL)
	{
		temp = current->prev;
		while (temp != NULL && temp->n > current->n)
		{
			/* swap nodes */
			temp->next = current->next;
			current->prev = temp->prev;

			if (temp->prev != NULL)
				temp->prev->next = current;
			if (current->next != NULL)
				current->next->prev = temp;
			current->next = temp;
			temp->prev = current;

			/* update head if necessary */
			if (*list == temp)
				*list = current;

			/* print the list after each swap */
			print_list(*list);
			temp = current->prev;
		}
		current = current->next;
	}
}
