#include "lists.h"

/**
 * pop_listint - Deletes the head node of a listint_t list.
 * @head: A pointer to the address of the head of the listint_t list.
 *
 * Return: 0 - if the linked list is empty,
 *         Otherwise - The head node's data (k).
 */
int pop_listint(listint_t **head)
{
	int k = 0;
	listint_t *temp;

	if (head == NULL || *head == NULL)
		return (0);
	temp = *head;
	*head = temp->next;
	k = temp->n;
	free(temp);
	return (k);
}
