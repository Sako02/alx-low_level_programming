#include "lists.h"
#include <string.h>

/**
 * add_node_end - add element in the end of a linked list
 * @head: linked list's head
 * @str: string to copy in the new element
 *
 * Return: new head
 */
list_t *add_node_end(list_t **head, const char *str)
{
	list_t *oneNode, *ptr = *head;
	int len = 0;

	oneNode = malloc(sizeof(list_t));
	if (!oneNode)
		return (NULL);

	/*Fill the newNode*/
	oneNode->str = strdup(str);
	while (str[len] != '\0')
		len++;
	oneNode->len = len;
	oneNode->next = NULL;

	if (*head == NULL)
		*head = oneNode;
	else
	{
		while (ptr->next != NULL)
			ptr = ptr->next;

		ptr->next = oneNode;
	}
	return (oneNode);
}
