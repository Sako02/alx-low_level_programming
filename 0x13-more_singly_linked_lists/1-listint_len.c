#include "lists.h"

/**
 * listint_len - returns the number of elements in a linked list
 * @h: head of a list.
 *
 * Return: numbers of nodes used
 */
size_t listint_len(const listint_t *h)
{
	size_t nbnodes = 0;

	while (h != NULL)
	{
		h = h->next;
		nbnodes++;
	}
	return (nbnodes);
}
