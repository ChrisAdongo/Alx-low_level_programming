#include "main.h"

int strlen_no_wcrds(char *str);
void iterate_wcrd(char **wildstr);
char *postfix_match(char *str, char *postfix);
int wildcmp(char *s1, char *s2);

/**
 * strlen_no_wcrds - Returns length of a string,
 *                   ignoring wildcard characters.
 * @str: String to be measured.
 *
 * Return: Length.
 */
int strlen_no_wcrds(char *str)
{
	int len = 0, index = 0;

	if (*(str + index))
	{
		if (*str != '*')
			len++;

		index++;
		len += strlen_no_wcrds(str + index);
	}

	return (len);
}

/**
 * iterate_wcrd - Iterates through a string located at a wildcard
 *                until it points to a non-wildcard character.
 * @wildstr: The string to be iterated through.
 */
void iterate_wcrd(char **wildstr)
{
	if (**wildstr == '*')
	{
		(*wildstr)++;
		iterate_wcrd(wildstr);
	}
}

/**
 * postfix_match - Checks if a string str matches the postfix of
 *                 another string potentially containing wildcards.
 * @str: The string to be matched.
 * @postfix: The postfix.
 *
 * Return: If str and postfix are identical - a pointer to the null byte
 *                                            located at the end of postfix.
 *         Otherwise - a pointer to the first unmatched character in postfix.
 */
char *postfix_match(char *str, char *postfix)
{
	int str_len = strlen_no_wcrds(str) - 1;
	int postfix_len = strlen_no_wcrds(postfix) - 1;

	if (*postfix == '*')
		iterate_wcrd(&postfix);

	if (*(str + str_len - postfix_len) == *postfix && *postfix != '\0')
	{
		postfix++;
		return (postfix_match(str, postfix));
	}

	return (postfix);
}

/**
 * wildcmp - Compares two strings, considering wildcard characters.
 * @s1: The first string to be compared.
 * @s2: The second string to be compared - may contain wildcards.
 *
 * Return: If the strings can be considered identical - 1.
 *         Otherwise - 0.
 */
int wildcmp(char *s1, char *s2)
{
	if (*s2 == '*')
	{
		iterate_wcrd(&s2);
		s2 = postfix_match(s1, s2);
	}

	if (*s2 == '\0')
		return (1);

	if (*s1 != *s2)
		return (0);

	return (wildcmp(++s1, ++s2));
}
