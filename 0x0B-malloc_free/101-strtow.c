#include "main.h"
#include <stdlib.h>

int word_len(char *str);
int count_words(char *str);
char **strtow(char *str);

/**
 * word_len - Locates the index marking the end of the
 *            first word contained within a string.
 * @str: The string to be searched.
 *
 * Return: The index marking the end of the initial word pointed to by str.
 */
int word_len(char *str)
{
	int i = 0, len = 0;

	while (*(str + i) && *(str + i) != ' ')
	{
		len++;
		i++;
	}

	return (len);
}

/**
 * count_words - Counts number of words contained within a string.
 * @str: String to be searched.
 *
 * Return: Number of words contained within str.
 */
int count_words(char *str)
{
	int i = 0, words = 0, len = 0;

	for (i = 0; *(str + i); i++)
		len++;

	for (i = 0; i < len; i++)
	{
		if (*(str + i) != ' ')
		{
			words++;
			i += word_len(str + i);
		}
	}

	return (words);
}

/**
 * strtow - Splits a string into words.
 * @str: String to be split.
 *
 * Return: If str = NULL, str = "", or the function fails - NULL.
 *         Otherwise - a pointer to an array of strings (words).
 */
char **strtow(char *str)
{
	char **strs;
	int index = 0, words, w, letters, l;

	if (str == NULL || str[0] == '\0')
		return (NULL);

	words = count_words(str);
	if (words == 0)
		return (NULL);

	strs = malloc(sizeof(char *) * (words + 1));
	if (strs == NULL)
		return (NULL);

	for (w = 0; w < words; w++)
	{
		while (str[index] == ' ')
			index++;

		letters = word_len(str + index);

		strs[w] = malloc(sizeof(char) * (letters + 1));

		if (strs[w] == NULL)
		{
			for (; w >= 0; w--)
				free(strs[w]);

			free(strs);
			return (NULL);
		}

		for (l = 0; l < letters; l++)
			strs[w][l] = str[index++];

		strs[w][l] = '\0';
	}
	strs[w] = NULL;

	return (strs);
}
