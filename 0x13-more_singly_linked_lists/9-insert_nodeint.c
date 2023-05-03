#include "lists.h"

/**
 * insert_nodeint_at_index - inserts a new node in a linked list
 * 
 * @head: pointer to the first node in the list
 * @idx: index where the new node is added
 * @n: data to insert in the new node
 *
 * Return: node, or NULL
 */
listint_t *insert_nodeint_at_index(listint_t **head, unsigned int idx, int n)
{
	if (idx == 0)
	{
		listint_t *one_node = malloc(sizeof(listint_t));

		if (one_node == NULL)
			return (NULL);

		one_node->n = n;
		one_node->next = *head;
		*head = one_node;

		return (one_node);
	}

	if (*head == NULL)
		return (NULL);

	return (insert_nodeint_at_index(&(*head)->next, idx - 1, n));
}
