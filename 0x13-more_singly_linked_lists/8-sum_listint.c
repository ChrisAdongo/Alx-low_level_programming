#include "lists.h"

/**
 * sum_listint - Calculates the sum of all the data (n) of a listint_t list
 * @head: Pointer to the head of the linked list.
 *
 * Return: 0 - if list is empty,
 *		Otherwise - resulting sum.
 */
int sum_listint(listint_t *head)
{
	int sum = 0;
	listint_t *temp = head;

	while (temp)
	{
		sum += temp->n;
		temp = temp->next;
	}
	return (sum);
}
