#include "lists.h"
#include <stdlib.h>

/**
 * print_listint_safe - Function that prints a listint_t linked list
 * @head: pointer to the first node of the linked list
 *
 * Return: new_node
 */
size_t print_listint_safe(const listint_t *head)
{
	size_t i = 0;
	size_t j;
	const listint_t *p = NULL;
	const listint_t *l = NULL;

	p = head;
	while (p)
	{
		printf("[%p] %d\n", (void *)p, p->n);
		i++;
		p = p->next;
		l = head;
		j = 0;
		if (!head)
			exit(98);
		while (j < i)
		{
			if (p == l)
			{
				printf("-> [%p] %d\n", (void *)p, p->n);
				return (i);
			}
			l = l->next;
			j++;
		}
	}
	return (i);
}
