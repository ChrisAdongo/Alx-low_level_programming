#include "hash_tables.h"

/**
 * hash_table_print - prints the keys and values of the hash table
 *
 * @ht: pointer to the hash table
 * Return: no return
 */
void hash_table_print(const hash_table_t *ht)
{
	unsigned long int index;
	hash_node_t *current_node;
	char *separator;

	if (ht == NULL)
	{
		return;
	}
	printf("{");
	separator = "";

	for (index = 0; index < ht->size; index++)
	{
		current_node = ht->array[index];
		while (current_node != NULL)
		{
			printf("%s'%s': '%s'", separator, current_node->key, current_node->value);
			separator = ", ";
			current_node = current_node->next;
		}
	}
	printf("}\n");
}

