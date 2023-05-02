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
	listint_t *nNode, *p = *head;

	nNode = malloc(sizeof(listint_t));
	if (nNode == NULL)
		return (NULL);

	nNode->n = n;
	nNode->next = NULL;

	if (*head == NULL)
		*head = nNode;
	else
	{
		while (p->next != NULL)
			p = p->next;
		p->next = nNode;
	}

	return (nNode);
}
