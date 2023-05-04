#include "lists.h"

/**
 * add_nodeint_end - Adds a new node at the end of a listint_t list.
 * @head: Pointer to the head of the list.
 * @n: Int to replace for the new node.
 *
 * Return: Address of the new element if success. Otherwise - Return NULL.
 */
listint_t *add_nodeint_end(listint_t **head, const int n)
{
	listint_t *new_n, *last_n;

	new_n = malloc(sizeof(listint_t));
	if (!new_n)
		return (NULL);

	new_n->n = n;
	new_n->next = NULL;

	if (*head == NULL)
		*head = new_n;
	else
	{
		last_n = *head;
		while (last_n->next != NULL)
			last_n = last_n->next;

		last_n->next = new_n;
	}

	return (new_n);
}
