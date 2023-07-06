#include "main.h"
#include <stdlib.h>

/**
 * get_endianness - checks if a machine is little or big endian
 * Return: 0 for big, 1 for little
 */
int get_endianness(void)
{
	int x = 1;
	char *current = (char *) malloc(sizeof(int));
	int *my_ptr;
	int y;

	if (!current)
		exit(1);

	my_ptr = (int *) current;
	*my_ptr = x;

	y = (*current == 1) ? 1 : 0;

	free(current);

	return (y);
}
