#include "lists.h"

/**
 * free_listint2 - frees a linked list
 * @head: head of a list.
 *
 * Return: no return.
 */
void free_listint2(listint_t **head)
{
    listint_t *p;
    listint_t *r;

    if (head != NULL)
    {
        r = *head;
        while ((p = curr) != NULL)
        {
            r = r->next;
            free(p);
        }
        *head = NULL;
    }
}
