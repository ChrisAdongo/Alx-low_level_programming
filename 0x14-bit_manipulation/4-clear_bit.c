#include "main.h"

/**
 * clear_bit – Sets the value of a given bit to 0
 * @n: Pointer to the num to be changed.
 * @index: The index of the bit.
 *
 * Return: 1 for success, Otherwise -1 for failure
 */
int clear_bit(unsigned long int *n, unsigned int index)
{
	if (index > 63)
		return (-1);

	*n = (~(1UL << index) & *n);
	return (1);
}
