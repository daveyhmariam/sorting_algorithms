#include "sort.h"

/**
 * insertion_sort_list - sorting with insertion algorithm
 * @list: head to list
 * Return: Nothing
*/
void insertion_sort_list(listint_t **list)
{
	listint_t *insert, *iter;

	if (*list == NULL || (*list)->next == NULL)
		return;
	insert = (*list)->next;
	while (insert != NULL)
	{
		iter = insert;
		insert = insert->next;
		while (iter && iter->prev && (iter->n) < (iter->prev->n))
		{
			swap(iter);
			if (iter->prev == NULL)
				*list = iter;
			print_list(*list);

		}
	}
}

/**
 * swap - swaps nodes
 * @swp: swaping node
 * Return: Nothing
*/
void swap(listint_t *swp)
{
	listint_t *tmp;

	tmp = swp->prev;
	if (tmp == NULL)
		return;
	tmp->next = swp->next;
	if (tmp->next)
		tmp->next->prev = tmp;
	swp->next = tmp;
	swp->prev = tmp->prev;
	tmp->prev = swp;
	if (swp->prev)
		swp->prev->next = swp;
}
