#include "main.h"

/**
 * binary_to_uint – Function that converts a binary num to unsigned int.
 * @b: String containing the binary num.
 *
 * Return: Converted number,
 *         Otherwise – 0 if b is NULL.
 */
unsigned int binary_to_uint(const char *b)
{
	int q;
	unsigned int my_num = 0;

	if (!b)
		return (0);

	for (q = 0; b[q]; q++)
	{
		if (b[q] < '0' || b[q] > '1')
			return (0);
		my_num = 2 * my_num + (b[q] - '0');
	}

	return (my_num);
}
