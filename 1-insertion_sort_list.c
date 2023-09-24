#include "sort.h"
/**
 * swap_nodes - swaps two nodes in a listint_t of a doubly linked list
 * @h: a pointer to the head node
 * @n1: a pointer to the first node to be swaped
 * @n2: a pointer to the second node to be swapped
 */
void swap_nodes(listint_t **h, listint_t **n1, listint_t *n2)
{
	(*n1)->next = n2->next;

	if (n2->next != NULL)
		n2->next->prev = *n1;
	n2->prev = (*n1)->prev;
	n2->next = *n1;
	if ((*n1)->prev != NULL)
		(*n1)->prev->next = n2;
	else
		*h = n2;
	(*n1)->prev = n2;
	*n1 = n2->prev;
}
/**
 * insertion_sort_list - sorts a doubly linked list of integers
 * using the insertion sort algorithm
 * @list: a pointer to the head of a doubly linked list of integers
 * Description: print s the list after each swap
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *rep, *insert, *temp;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;
	for (rep = (*list)->next; rep != NULL; rep = temp)
	{
		temp = rep->next;
		insert = rep->prev;
		while (insert != NULL && rep->n < insert->n)
		{
			swap_nodes(list, &insert, rep);
			print_list((const listint_t *)*list);
		}
	}
}
