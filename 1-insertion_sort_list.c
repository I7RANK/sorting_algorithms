#include "sort.h"

/**
 * change_nodes - changes two nodes of positions in doubly linked list
 * Description: change the node greater to right (prev)
 * and the less to left (next)
 *
 * @index: the node grater
 * @node_insert: the node less
 * @list: pointer to header
 *
 * Return: na
*/
void change_nodes(listint_t *index, listint_t *node_insert, listint_t **list)
{
	listint_t *index_prev = NULL, *node_next = NULL;

	index_prev = index->prev;
	node_next = node_insert->next;

	index->next = node_insert->next;
	node_insert->prev = index->prev;

	node_insert->next = index;
	index->prev = node_insert;

	if (node_next)
		node_next->prev = index;

	if (index_prev)
		index_prev->next = node_insert;
	else
		*list = node_insert;
}

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

	if (!list || !(*list)->next)
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
			while (index)
			{
				if (index->n > node_insert->n)
				{
					change_nodes(index, node_insert, list);

					index = index->prev;
					print_list(*list);
				}
				else
				{
					break;
				}
				index = index->prev;
			}
			list_temp = list_temp->prev;
		}
		list_temp = list_temp->next;
	}
}
