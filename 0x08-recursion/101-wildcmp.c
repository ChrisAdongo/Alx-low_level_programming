#include "main.h"

/**
 * wildcmp - compares two strings and returns 1 if identical.
 * @s1: pointer to first string.
 * @s2: pointer to second string that may contain a wildcard character '*'.
 *
 * Return: 1 if strings are identical, otherwise 0.
 */

int wildcmp(char *s1, char *s2)
{
	if (*s1 == '\0')
	{
	if (*s2 == '\0' || *s2 == '*')
		return (1);
	else
		return (0);
	}
	if (*s2 == '*')
	{
	if (wildcmp(s1, s2 + 1) || wildcmp(s1 + 1, s2))
		return (1);
	else
		return (0);
	}
	if (*s1 == *s2)
		return (wildcmp(s1 + 1, s2 + 1));
	return (0);
}
