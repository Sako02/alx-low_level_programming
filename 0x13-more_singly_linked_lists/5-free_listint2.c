#include "lists.h"
#include <stdlib.h>
/**
 * free_listint2 - free a listint_t
 * @head: listint_t's head
 * return : none
 */
void free_listint2(listint_t **head)
{
	listint_t *p;

	if (head != NULL)
	{
		while (*head != NULL)
		{
			p = (*head);
			(*head) = (*head)->next;
			free(p);
		}
		free(*head);
		*head = NULL;
	}
}
