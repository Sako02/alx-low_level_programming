#include "lists.h"
#include <string.h>

/**
 * add_node - adds a new node at the beginning of a list_t list
 * @head: pointer to the head of the list
 * @str: string to be duplicated and added as the new node's content
 * Return: the address of the new element
 */

list_t *add_node(list_t **head, const char *str)
{
	char *one_str;
	list_t *one_node;

	one_node = malloc(sizeof(list_t));
	if (one_node == NULL)
		return (NULL);

	one_str = strdup(str);
	if (one_str == NULL)
	{
		free(one_node);
		return (NULL);
	}

	one_node->str = one_str;
	one_node->len = strlen(one_str);
	one_node->next = *head;
	*head = one_node;

	return (one_node);
}
