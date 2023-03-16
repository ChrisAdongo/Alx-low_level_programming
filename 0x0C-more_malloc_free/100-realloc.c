#include "main.h"
#include <stdlib.h>

/**
 * _realloc - Reallocates a memory block using malloc and free.
 * @ptr: pointer to the memory previously allocated.
 * @new_size: size in bytes for the new memory block.
 * @old_size: size in bytes of the allocated space for ptr.
 * 
 * Return: If new_size == old_size - ptr.
 *         If new_size == 0 and ptr is not NULL - NULL.
 *         Otherwise - a pointer to the reallocated memory block.
 */
void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size)
{
	void *mem;
	char *new_ptr, *alloc;
	unsigned int i;

	if (new_size == old_size)
		return (ptr);

	if (ptr == NULL)
	{
		mem = malloc(new_size);

		if (mem == NULL)
			return (NULL);

		return (mem);
	}

	if (new_size == 0 && ptr != NULL)
	{
		free(ptr);
		return (NULL);
	}

	new_ptr = ptr;
	mem = malloc(sizeof(*new_ptr) * new_size);

	if (mem == NULL)
	{
		free(ptr);
		return (NULL);
	}

	alloc = mem;

	for (i = 0; i < old_size && i < new_size; i++)
		alloc[i] = *new_ptr++;

	free(ptr);
	return (mem);
}
