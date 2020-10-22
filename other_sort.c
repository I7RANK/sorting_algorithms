#include "sort.h"

/**
 * insertion_sort_list - sorts a doubly linked list in ascending order
 * using the insertion sort algorithm
 * @list: pointer to the header of doubly linked list
 *
 * Return: na
*/
void insertion_sort_list(listint_t **list)
{
	listint_t *list_temp = NULL, *index = NULL;
	listint_t *node_insert = NULL;

	if (!list)
		return;

	list_temp = *list;
	while (list_temp)
	{
		if (!list_temp->next)
			break;
		if (list_temp->n > list_temp->next->n)
		{
			node_insert = list_temp->next;
			index = list_temp;
			list_temp->next = node_insert->next;
			while (index)
			{
				if (!index->prev)
				{
					index->prev = node_insert;
					node_insert->next = index;
					node_insert->prev = NULL;
					*list = node_insert;
					print_list(*list);
					list_temp = list_temp->prev;
					break;
				}
				if (index->n <= node_insert->n)
				{
					index->next->prev = node_insert;
					node_insert->next = index->next;
					index->next = node_insert;
					node_insert->prev = index;
					print_list(*list);
					list_temp = list_temp->prev;
					break;
				}
				index = index->prev;
			}
		}
		list_temp = list_temp->next;
	}
}
