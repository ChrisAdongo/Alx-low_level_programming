#include "main.h"
#include <stdlib.h>

/**
 * str_concat - Concatenates two strings.
 * @s1: The string to be concatenated upon.
 * @s2: The string to be concatenated to s1.
 *
 * Return: If concatenation fails - NULL.
 *         Otherwise - a pointer the newly-allocated space in memory
 *                     containing the concatenated strings.
 */
char *str_concat(char *s1, char *s2)
{
	char *str_conct;
	int i, len = 0, concat_index = 0;

	if (s1 == NULL)
		s1 = "";

	if (s2 == NULL)
		s2 = "";

	for (i = 0; s1[i] || s2[i]; i++)
		len++;

	str_conct = malloc(sizeof(char) * len);

	if (str_conct == NULL)
		return (NULL);

	for (i = 0; s1[i]; i++)
		str_conct[concat_index++] = s1[i];

	for (i = 0; s2[i]; i++)
		str_conct[concat_index++] = s2[i];

	return (str_conct);
}
