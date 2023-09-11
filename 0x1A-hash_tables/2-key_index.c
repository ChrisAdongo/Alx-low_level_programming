#include "hash_tables.h"

/**
 * key_index - Returns the index in the hash table to put a key in.
 * @key: The key.
 * @size: The size of the array.
 *
 * Return: The index of the key.
 */
unsigned long int key_index(const unsigned char *key, unsigned long int size)
{
	unsigned long int hash_value = hash_djb2(key);
	unsigned long int index = hash_value % size;

	return (index);
}
