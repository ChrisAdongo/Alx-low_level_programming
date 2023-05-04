#include "function_pointers.h"

/**
 * int_index - Searches for an integer in an array using a given function
 * @array: Pointer to the array to search
 * @size: Number of elements in the array
 * @cmp: Pointer to the function used to compare values
 *
 * Return: index of first element for which cmp function does not return 0,
 *         or -1 if no element matches or if size <= 0
 */
int int_index(int *array, int size, int (*cmp)(int))
{
	int i;

	if (array == NULL || cmp == NULL || size <= 0)
		return (-1);

	for (i = 0; i < size; i++)
	{
		if (cmp(array[i]))
		return (i);
	}

	return (-1);
}

