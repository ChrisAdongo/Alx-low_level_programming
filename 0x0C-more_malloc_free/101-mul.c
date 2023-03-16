#include "main.h"
#include <stdlib.h>

/**
 * _isdigit - checks if a character is a digit
 * @c: character to be checked
 *
 * Return: 1 if c is a digit, 0 otherwise
 */
int _isdigit(char c)
{
	return (c >= '0' && c <= '9');
}

/**
 * _strlen - returns the length of a string
 * @s: input string
 *
 * Return: length of s
 */
int _strlen(char *s)
{
	int i;
	
	for (i = 0; s[i]; i++)
		;
	return (i);
}

/**
 * main - multiplies two positive numbers
 * @argc: argument count
 * @argv: argument vector
 *
 * Return: 0 on success, 98 on failure
 */
int main(int argc, char **argv)
{
	int i, j, len1, len2, len_res, carry, num1, num2, *res;
	
	if (argc != 3)
	{
		printf("Error\n");
		exit(98);
	}
	len1 = _strlen(argv[1]);
	len2 = _strlen(argv[2]);

	for (i = 0; i < len1; i++)
	{
		if (!_isdigit(argv[1][i]))
		{
			printf("Error\n");
			exit(98);
		}
	}
	for (i = 0; i < len2; i++)
	{
		if (!_isdigit(argv[2][i]))
		{
			printf("Error\n");
			exit(98);
		}
	}
	len_res = len1 + len2;
	res = malloc(len_res * sizeof(int));
	if (!res)
		return (1);
	for (i = 0; i < len_res; i++)
		res[i] = 0;
	for (i = len1 - 1; i >= 0; i--)
	{
		carry = 0;
		num1 = argv[1][i] - '0';
		for (j = len2 - 1; j >= 0; j--)
		{
			num2 = argv[2][j] - '0';
			carry += res[i + j + 1] + (num1 * num2);
			res[i + j + 1] = carry % 10;
			carry /= 10;
		}
		if (carry)
		res[i + j + 1] += carry;
	}
	while (*res == 0 && len_res > 1)
	{
		res++;
		len_res--;
	}
	for (i = 0; i < len_res; i++)
		putchar(*res++ + '0');

	putchar('\n');

	return (0);
return (0);
}
