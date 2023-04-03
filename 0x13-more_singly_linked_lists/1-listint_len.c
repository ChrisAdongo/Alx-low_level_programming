#include "lists.h"
#include <stdio.h>

/**
* listint_len - Returns the num of elements in a linked listint_t list
 * @h: A pointer to the head of listint_t list
 *
 * Return: Num of elements in a linked listint_t list.
 */
size_t listint_len(const listint_t *h)
{
size_t j = 0;

	while (h)
	{
		j++;
		h = h->next;
	}

	return (j);
}
