#include <stdio.h>

/**
 * main - Prints first 52 fibonacci numbers
 *
 * Return: Nothing!
 */
int main(void)
{
	int i = 0;
	long a = 1, b = 2;

	while (i < 50)
	{
		if (i == 0)
			printf("%ld", a);
		else if (i == 1)
			printf(", %ld", b);
		else
		{
			b += a;
			a = b - a;
			printf(", %ld", b);
		}

		++i;
	}

	printf("\n");
	return (0);
}
