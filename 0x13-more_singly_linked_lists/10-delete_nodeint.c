#include "lists.h"
#include <stdlib.h>

/**
 * * delete_nodeint_at_index - deletes the node at index
 * of a linked list.
 * @head: listint_t's head.
 * @index: index to delete.
 *
 * Return: new node
 */
int delete_nodeint_at_index(listint_t **head, unsigned int index)
{
	listint_t *p, *m, *r = *head;
	unsigned int i = 0;

	if ((*head) == NULL)
		return (-1);

	if (index > 0)
	{
		while (r->next != NULL)
		{
			if (i == (index - 1))
			{
				break;
			}
			i++;
			r = r->next;
		}
		p = r;
		if (r->next == NULL)
			return (-1);
		m = r->next;
		if (m->next == NULL)
		{
			free(m);
			p->next = NULL;
		}
		else
		{
			p->next = m->next;
			free(m);
		}
	}
	else
	{
		m = (*head);
		(*head) = (*head)->next;
		free(m);
	}

	return (1);
}
