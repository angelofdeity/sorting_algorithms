#include "sort.h"

void insertion_sort_list(listint_t **list)
{
	listint_t *a_node, *b_node, *current = (*list)->next;

	if (*list == NULL || (*list)->next == NULL)
		return;

	while (current != NULL)
	{
		b_node = current;
		a_node = current->prev;

		while (b_node->prev != NULL && b_node->n < a_node->n)
		{
			a_node->next = b_node->next;
			b_node->prev = a_node->prev;
			if (a_node->prev != NULL)
				a_node->prev->next = b_node;
			if (b_node->next != NULL)
				b_node->next->prev = a_node;
			b_node->next = a_node;
			a_node->prev = b_node;
			if (*list == a_node)
				*list = b_node;

			/*move a and b a step back each*/
			print_list(*list);
			a_node = b_node->prev;
		}
		/* if (b_node->prev == NULL)
		 *list = b_node; */
		current = current->next;
	}
}
