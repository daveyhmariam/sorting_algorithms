#include "sort.h"

/**
 * insertion_sort - sorting with insertion algorithm
 * @list: head to list
 * Return: Nothing
*/
void insertion_sort_list(listint_t **list)
{
	listint_t *insert, *iter;

	if (*list == NULL || (*list)->next == NULL)
        return; 
	insert = (*list)->next;
	iter = insert;
	while (insert != NULL)
	{
		while (iter && iter->prev)
		{
			if ((iter->n) < (iter->prev->n))
			{
				swap(iter);
				if (iter->prev == NULL)
					*list = iter;
				print_list(*list);
				if (iter->prev == NULL)
					break;
			}
			else if (iter->n >= iter->prev->n)
				break;

		}
		insert = insert->next;
		iter = insert;
	}
}

/**
 * swap - swaps nodes
 * @l: swaping node
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
/*
int main()
{
	listint_t *h, *tmp, *tmp2, *tmp3;

	h = (listint_t *) malloc(sizeof(listint_t));
	h->n=6;
	tmp = (listint_t *) malloc(sizeof(listint_t));
	tmp2 = (listint_t *) malloc(sizeof(listint_t));
	tmp3 = (listint_t *) malloc(sizeof(listint_t));
	tmp->n = 1;
	tmp2->n = 3;
	tmp3->n =10;
	tmp3->next = NULL;
	tmp3->prev = tmp2;
	tmp->next = tmp2;
	tmp2->next =tmp3;
	tmp->prev = tmp;
	h->next = tmp;
	tmp->prev = h;

	h->prev = NULL;
	print_list(h);
	swap(tmp);
	print_list(tmp);
	swap(tmp2);
	swap(tmp3);
	swap(tmp3);
	swap(tmp3);
	print_list(tmp);
	swap(tmp3);
	print_list(tmp3);
	print_list(h->prev->prev);
}
*/