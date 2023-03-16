#include <stdio.h>
#include <stdlib.h>

/**
 * string_nconcat - concatenates two strings
 * @s1: first string
 * @s2: second string
 * @n: number of bytes of s2 to concatenate
 *
 * Return: pointer to concatenated string
 *         NULL if function fails
 */
char *string_nconcat(char *s1, char *s2, unsigned int n)
{
	char *concat_str;
	unsigned int s1_len = 0, s2_len = 0, i = 0, k = 0;

	if (s1 == NULL)
		s1 = "";
	if (s2 == NULL)
		s2 = "";

	while (s1[s1_len] != '\0')
		s1_len++;
	while (s2[s2_len] != '\0')
		s2_len++;

	if (n >= s2_len)
		n = s2_len;

	concat_str = malloc(sizeof(char) * (s1_len + n + 1));
	if (concat_str == NULL)
		return (NULL);

	for (; i < s1_len; i++)
		concat_str[i] = s1[i];
	for (; k < n; k++, i++)
		concat_str[i] = s2[k];

	concat_str[i] = '\0';

	return (concat_str);
}
