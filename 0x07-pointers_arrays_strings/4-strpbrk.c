#include "main.h"

/**
 * _strpbrk - Search string for set of bytes
 *
 * @s: The string to search
 * @accept: The set of bytes to search for
 *
 * Return: Pointer to first occurrence of byte in accept that matches a byte in s, or NULL if not found
 */

char *_strpbrk(char *s, char *accept)
{
	char *p;
	while (*s != '\0')
	{
		for (p = accept; *p != '\0'; p++)
		{
			if (*s == *p)
			{
				return (s);
			}
		}
		s++;
	}
	return ('\0');
}
