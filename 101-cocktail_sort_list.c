#include "sort.h"

/**
 * cocktail_sort_list - sorting with cocktail_sort
 * @list: list to be sorted
 * Return: Nothing
*/
void cocktail_sort_list(listint_t **list)
{
	listint_t *fwd, *bwd, *nextf,  *nextb, *haltf = NULL, *haltb = NULL;
	int sw = 0;
	
	if (!list || !(*list) || (*list)->next == NULL)
		return;
	fwd = (*list);
	nextf = fwd->next;
	while (1)
	{
		sw = 0;
		while (fwd != haltf && nextf)
		{
			if (fwd->n > nextf->n)
			{
				swap(nextf);
				if (nextf->prev == NULL)
					*list = nextf;
				print_list(*list);
				nextf = fwd->next;
				sw++;
			}
			else
			{
				fwd = fwd->next;
				nextf = nextf->next;
			}
			if (nextf == haltf)
			{
				haltf = fwd;
				bwd = haltf->prev;
				nextb = bwd->prev;
			}
		}
		while (bwd != haltb && nextb)
		{
			if (bwd->n < nextb->n)
			{
				swap(bwd);
				if (haltb == NULL && bwd->prev == NULL)
					*list = bwd;
				print_list(*list);
				nextb = bwd->prev;
				sw++;
			}
			else
			{
				bwd = bwd->prev;
				nextb = nextb->prev;
			}
			if (nextb == haltb)
			{
				haltb = bwd;
				fwd = haltb->next;
				nextf = fwd->next;
			}
		}
		if (sw == 0)
			break;
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
