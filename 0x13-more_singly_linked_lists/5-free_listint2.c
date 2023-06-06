#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "lists.h"

/**
 * free_listint2 - frees a list of ints
 * @head: pointer of the first node
 *
 * Return: void
 */
void free_listint2(listint_t **head)
{
	listint_t *node = *head;
	listint_t *next;

	while (node != NULL)
	{
		next = node->next;
		free(node);
		node = next;
	}
	*head = NULL;
}
