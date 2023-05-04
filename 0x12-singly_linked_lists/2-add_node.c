#include "lists.h"
#include <stdlib.h>
#include <string.h>

/**
 * add_node - Adds a new node at the beginning
 *            of a list_t list.
 * @head: A pointer to the head of the list_t list.
 * @str: String to be added to the list_t list.
 *
 * Return: If the function fails - NULL.
 *         Otherwise - the address of the new element.
 */
list_t *add_node(list_t **head, const char *str)
{
	list_t *new_node = NULL;
	char *str_copy = NULL;
	int len = 0;

	if (!head || !str)
	exit(EXIT_FAILURE);

	new_node = malloc(sizeof(list_t));
	if (!new_node)
	exit(EXIT_FAILURE);

	str_copy = malloc(sizeof(char) * (strlen(str) + 1));
	if (!str_copy)
	{
		free(new_node);
		exit(EXIT_FAILURE);
	}

	while (str[len])
	len++;

	memcpy(str_copy, str, len + 1);

	new_node->str = str_copy;
	new_node->len = len;
	new_node->next = *head;

	*head = new_node;

	return (new_node);
}
