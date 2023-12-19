#include<stdio.h>
#include<stdlib.h>
#include"sort.h"

/**
 * insertion_sort_list - implements the insertion sort algorithm to sort
 * a doubly linked list in ascending order.
 *
 * @list: The "list" parameter is a pointer to a pointer
 * to a linked list of integers.
 */
void insertion_sort_list(listint_t **list)
{
listint_t *curr;
listint_t *prev;

for (curr = (*list)->next; curr != NULL; curr = curr->next)
{
prev = curr->prev;
while (prev != NULL && prev->n > curr->n)
{
swapper(list, &prev, curr);
print_list((*list));
}
}
}

/**
 * swapper - swaps two nodes in a doubly linked list.
 *
 * @head: A pointer to the head of the linked list.
 * @Node_1: Node_1 is a pointer to a pointer to a node in a doubly linked list.
 * @Node_2: Node_2 is a pointer to a node in a doubly linked list.
 */
void swapper(listint_t **head, listint_t **Node_1, listint_t *Node_2)
{
(*Node_1)->next = Node_2->next;
if (Node_2->next != NULL)
Node_2->next->prev = *Node_1;
Node_2->prev = (*Node_1)->prev;
Node_2->next = *Node_1;
if ((*Node_1)->prev != NULL)
(*Node_1)->prev->next = Node_2;
else
*head = Node_2;
(*Node_1)->prev = Node_2;
*Node_1 = Node_2->prev;
}