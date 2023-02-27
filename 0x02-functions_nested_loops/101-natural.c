#include <stdio.h>

/**
 * main - Prints sum of all multiples of 3 or 5 up to 1024
 * Return: Always (Success)
*/
int main(void)
{
	int i, a = 0;

	while (i < 1024)
	{
		if ((i % 3 == 0) || (i % 5 == 0))
		{
			a += i;
		}

		i++;
	}

	printf("%d\n", a);
	return (0);
}
