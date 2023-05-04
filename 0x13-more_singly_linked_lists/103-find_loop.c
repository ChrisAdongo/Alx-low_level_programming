#include "lists.h"

/**
 * find_listint_loop - finds the loop in a linked list
 * @head: linked list to search for
 *
 * Return: Address of the node where the loop starts, or NULL
 */
listint_t *find_listint_loop(listint_t *head)
{
	listint_t *one_node = head;
	listint_t *two_nodes = head;

	if (!head)
		return (NULL);

	while (one_node && two_nodes && two_nodes->next)
	{
		two_nodes = two_nodes->next->next;
		one_node = one_node->next;
		if (two_nodes == one_node)
		{
			one_node = head;

			while (one_node != two_nodes)
			{
				one_node = one_node->next;
				two_nodes = two_nodes->next;
			}
			return (two_nodes);
		}
	}
	return (NULL);
}
