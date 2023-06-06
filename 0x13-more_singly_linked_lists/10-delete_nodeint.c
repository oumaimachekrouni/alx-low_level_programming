#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "lists.h"

/**
 * delete_nodeint_at_index - deletes the node at a given index
 * @head: address of pointer to the first node
 * @index: index of the node to delete
 *
 * Return: 1 if succeeded, -1 if failed
 */
int delete_nodeint_at_index(listint_t **head, unsigned int index)
{
	if (head == NULL || *head == NULL)
		return (-1);

	if (index == 0)
	{
		listint_t *temp = *head;
		*head = (*head)->next;
		free(temp);
		return (1);
	}

	listint_t *prev_node = *head;
	listint_t *node = (*head)->next;
	unsigned int count = 1;

	while (node != NULL && count < index)
	{
		prev_node = node;
		node = node->next;
		count++;
	}

	if (node == NULL)
		return (-1);

	prev_node->next = node->next;
	free(node);
	return (1);
}
