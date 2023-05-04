#include "lists.h"

/**
 * free_listint_safe - Frees a listint_t list.
 * @h: Pointer to a pointer to the head of the list.
 *
 * Return: Size of the list that has been freed.
 */
size_t free_listint_safe(listint_t **h)
{
	listint_t *temp = NULL;
	listint_t *current = NULL;

	size_t s = 0;

	if (!h || !*h)
		return (0);

	while (*h)
	{
		current = *h;
		if (current <= current->next)
		{
			*h = current->next;
			free(current);
			s++;
		}
		else
		{
			while (current && current <= current->next)
			{
				temp = current;
				current = current->next;
				free(temp);
				s++;
			}
			if (!current)
				break;
			*h = current->next;
			free(current);
			s++;
		}
	}

	return (s);
}
