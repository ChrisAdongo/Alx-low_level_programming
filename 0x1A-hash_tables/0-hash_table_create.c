#include "hash_tables.h"

/**
 * hash_table_create - creates a hash table
 *
 * @size: size in number of nodes
 *
 * Return: Pointer to newly created hash table, or NULL if an error occurs.
 */
hash_table_t *hash_table_create(unsigned long int size)
{
	unsigned long int index;
	hash_table_t *new_table;

	new_table = malloc(sizeof(hash_table_t));

	if (new_table == NULL)
	{
		return (NULL);
	}

	new_table->size = size;
	new_table->array = malloc(sizeof(hash_node_t *) * size);

	if (new_table->array == NULL)
	{
		free(new_table);
		return (NULL);
	}

	for (index = 0; index < size; index++)
	{
		new_table->array[index] = NULL;
	}
	return (new_table);
}
