/**
 * hash_djb2 - Custom implementation of the djb2 algorithm
 * @str: String used to generate the hash value
 *
 * Return: Hash value
 */
unsigned long int hash_djb2(const unsigned char *str)
{
	unsigned long int hash = 5381;
	int c;

	while ((c = *str++))
	{
		hash = ((hash << 5) + hash) ^ c;
	}
	return (hash);
}
