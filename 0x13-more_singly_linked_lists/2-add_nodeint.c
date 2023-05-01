#include "lists.h"
#include <stdlib.h>
/**
 * add_nodeint - add an element to a listint_t
 * @head: listint_t's head
 * @n: int value
 * Return: adress of the new node | NULL (failed)
 */
listint_t *add_nodeint(listint_t **head, const int n)
{
	listint_t *oneNode;

	oneNode = malloc(sizeof(listint_t));
	if (oneNode == NULL)
		return (NULL);

	oneNode->n = n;
	oneNode->next = *head;

	*head = oneNode;
	return (oneNode);
}
