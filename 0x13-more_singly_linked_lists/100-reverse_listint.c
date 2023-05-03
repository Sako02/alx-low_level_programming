#include "lists.h"

/**
 * reverse_listint - Reverses a listint_t linked list
 * @head: pointer to te first node in the list
 *
 * Return: poiter
 */
listint_t *reverse_listint(listint_t **head)
{
	listint_t *pre = NULL;
	listint_t *sui = NULL;

	for (; *head; *head = sui)
	{
		sui = (*head)->next;
		(*head)->next = pre;
		pre = *head;
	}
	*head = pre;

	return (*head);
}
