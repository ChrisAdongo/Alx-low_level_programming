#include "lists.h"

/**
 * delete_nodeint_at_index - Deletes node at index of a listint_t linked list.
 * @head: Pointer to the first element in the list
 * @index: Index of the node to delete
 *
 * Return: 1 (Success), or -1 (Fail)
 */
int delete_nodeint_at_index(listint_t **head, unsigned int index)
{
	listint_t *temp = *head;
	listint_t *del = NULL;
	unsigned int j = 0;

	if (*head == NULL)
		return (-1);

	if (index == 0)
	{
		*head = (*head)->next;
		free(temp);
		return (1);
	}

	while (j < index - 1)
	{
		if (!temp || !(temp->next))
			return (-1);
		temp = temp->next;
		j++;
	}

	del = temp->next;
	temp->next = del->next;
	free(del);

	return (1);
}
