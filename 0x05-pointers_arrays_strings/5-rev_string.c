#include "main.h"

/**
 * rev_string - prints a string in reverse
 * @s: string to beb reversed
 * Return: 0
 */

void rev_string(char *s)
{
	int len, k, half;
	char temp;

	for (len = 0; s[len] != '\0'; len++)
	;
	k = 0;
	half = len / 2;

	while (half--)
	{
		temp = s[len - k - 1];
		s[len - k - 1] = s[k];
		s[k] = temp;
		k++;
	}
}
