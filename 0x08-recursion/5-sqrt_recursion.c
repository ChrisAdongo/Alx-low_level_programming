#include "main.h"

/**
 * sqrt_finder - function to find the natural square root of a number.
 * @n: input integer.
 * @i: integer counter.
 *
 * Return: integer.
 */

int sqrt_finder(int n, int i);

/**
 * _sqrt_recursion - returns the natural square root of a number.
 * @n: input integer.
 *
 * Return: integer.
 */

int _sqrt_recursion(int n)
{
	if (n < 0)
		return (-1);
	else if (n == 0 || n == 1)
		return (n);
	else
		return (sqrt_finder(n, 1));
}

/**
 * sqrt_finder - function to find the natural square root of a number.
 * @n: input integer.
 * @i: integer counter.
 *
 * Return: integer.
 */

int sqrt_finder(int n, int i)
{
	if (i * i == n)
		return (i);
	else if (i * i > n)
		return (-1);
	else
		return (sqrt_finder(n, i + 1));
}
