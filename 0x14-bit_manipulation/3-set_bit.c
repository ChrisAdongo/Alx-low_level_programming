#include "main.h"

/**
 * set_bit – Function that sets a bit at a given index to 1
 * @n: Pointer to the num to change
 * @index: The index of the bit to be set to 1
 *
 * Description: A function that sets the value of a bit to 1 at a given index.
 * Return: 1 for success, Otherwise -1 for failure
 */
int set_bit(unsigned long int *n, unsigned int index)
{
	if (index > 63)
		return (-1);

	*n = ((1UL << index) | *n);
	return (1)
