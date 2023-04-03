#include "lists.h"

/**
 * add_nodeint - Adds a new node at the beginning of a linked listint_t list.
 * @head: Pointer to the address of first node in the listint_t list.
 * @n: int to replace in that new node.
 *
 * Return: Address of the new node;
 *	Otherwise -  NULL if it fails.
 */
listint_t *add_nodeint(listint_t **head, const int n)
{
listint_t *new;

	new = malloc(sizeof(listint_t));
	if (!new)
		return (NULL);

	new->n = n;
	new->next = *head;

	*head = new;

	return (new);
}
