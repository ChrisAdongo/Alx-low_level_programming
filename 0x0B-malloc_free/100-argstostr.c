#include "main.h"
#include <stdlib.h>

/**
 * argstostr - concatenates all the arguments of a program
 * @ac: the number of arguments
 * @av: the array of arguments
 *
 * Return: a pointer to the concatenated string, or NULL on failure
 */
char *argstostr(int ac, char **av)
{
	int len = 0, i, j, k = 0;
	char *str;

	if (ac == 0 || av == NULL)
		return (NULL);
	
	/* calculate length of concatenated string */
	for (i = 0; i < ac; i++)
    	{
		for (j = 0; av[i][j] != '\0'; j++)
		len++;
		len++; /* add space for newline character */
	}
	/* allocate memory for concatenated string */
	str = malloc(sizeof(char) * (len + 1));
	if (str == NULL)
	return (NULL);

	/* copy arguments to concatenated string */
	for (i = 0; i < ac; i++)
	{
	for (j = 0; av[i][j] != '\0'; j++)
	{
		str[k] = av[i][j];
		k++;
        }
	str[k] = '\n'; /* add newline character */
	k++;
	}
	str[k] = '\0'; /* add null terminator */

	return (str);
}
