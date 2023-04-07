#include "main.h"

/**
 * print_binary – Prints the binary representation of a number.
 * @n: The number to be printed in binary.
 *
 * Description: Prints the binary represenation of a given long int.
 * Return: Void.
 */
void print_binary(unsigned long int n)
{
	int j, index = 0;
	unsigned long int k;

	for (j = 63; j >= 0; j--)
	{
		k = n >> j;

		if (index & 1)
		{
			_putchar('1');
			index++;
		}
		else if (index)
			_putchar('0');
	}
	if (!index)
		_putchar('0');
}
