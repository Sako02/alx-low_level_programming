#include "lists.h"

/**
 * pop_listint - delete the head node of a linked list
 * @head: double pointer to the linked list start
 *
 * Return: n
 */
int pop_listint(listint_t **head)
{
	listint_t *d;
	int n;

	if (head && *head)
	{
		n = (**head).n;
		d = *head;
		*head = (**head).next;
		free(d);
		return (n);
	}
	return (0);
}
