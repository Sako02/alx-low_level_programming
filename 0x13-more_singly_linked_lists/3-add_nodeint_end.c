#include "lists.h"
#include <stdlib.h>
/**
 * add_nodeint_end - add an element in the end of a listint_t
 * @head: listint_t's head
 * @n: int value
 *
 * Return: adress of the new node.
 */
listint_t *add_nodeint_end(listint_t **head, const int n)
{
	listint_t *nNode, *tmp = *head;

	nNode = malloc(sizeof(listint_t));
	if (nNode == NULL)
		return (NULL);

	nNode->n = n;
	nNode->next = NULL;

	if (*head == NULL)
		*head = nNode;
	else
	{
		while (tmp->next != NULL)
			tmp = tmp->next;
		tmp->next = nNode;
	}

	return (nNode);
}
