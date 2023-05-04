#include "main.h"

/**
 * flip_bits – Counts num of bits to be changed from one num to another.
 * @n: First num.
 * @m: Second num.
 *
 * Return: num of bits to be changed to get from n to m.
 */
unsigned int flip_bits(unsigned long int n, unsigned long int m)
{
	int i, j = 0;
	unsigned long int k;
	unsigned long int my_bit = n ^ m;

	for (i = 63; i >= 0; i--)
	{
		k = my_bit >> i;
		if (k & 1)
			j++;
	}

	return (j);
}
