#include "main.h"
#include <stdlib.h>

/**
 * _strdup - returns a pointer to newly allocated space in memory,
 *           containing a copy of the string given as a parameter.
 * @str: string to duplicate
 *
 * Return: pointer to the duplicated string or NULL if insufficient memory
 *         was available or str is NULL.
 */
char *_strdup(char *str)
{
	char *dupl_str;
	unsigned int len, i;

	if (str == NULL)
		return (NULL);

	len = 0;
	while (str[len] != '\0')
		len++;

	dupl_str = malloc(sizeof(char) * (len + 1));

	if (dupl_str == NULL)
		return (NULL);

	for (i = 0; i < len; i++)
		dupl_str[i] = str[i];

	dupl_str[len] = '\0';

	return (dupl_str);
}
