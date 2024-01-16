#include "sort.h"

/**
 * swap_nodes - Swaps two nodes in a doubly linked list.
 * @list: Pointer to the head of the list.
 * @node1: First node to swap.
 * @node2: Second node to swap.
 *
 * Description: This function swaps the positions of two nodes in a doubly
 *              linked list. It adjusts the relevant pointers to maintain
 *              the integrity of the list structure. If the list, or either
 *              of the nodes provided is NULL, the function has no effect.
 *              If node1 is the same as node2, no swap is performed.
 */
void swap_nodes(listint_t **list, listint_t *node1, listint_t *node2)
{
	if (!list || !*list || !node1 || !node2)
		return;

	if (node1 == node2)
		return;

	if (node1->prev)
		node1->prev->next = node2;
	else
		*list = node2;

	if (node2->next)
		node2->next->prev = node1;

	node1->next = node2->next;
	node2->prev = node1->prev;
	node1->prev = node2;
	node2->next = node1;
}

/**
 * insertion_sort_list - Sorts a doubly linked list in ascending order.
 * @list: Pointer to the head of the list.
 *
 * Description: This function applies the insertion sort algorithm to sort a
 *              doubly linked list of integers in ascending order. It iterates
 *              through the list, swapping nodes when necessary to achieve the
 *              desired order. If the list or the head is NULL, the function
 *              has no effect.
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *head, *tmp;

	if (!list || !*list)
		return;

	head = *list;

	while (head)
	{
		while (head->prev && (head->n < head->prev->n))
		{
			tmp = head->prev;
			swap_nodes(list, tmp, head);
			print_list(*list);
		}
		head = head->next;
	}
}
