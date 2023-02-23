#include <stdio.h>

/**
 * main - Fizz Buzz code
 *
 * Return: void
 */

int main(void)
{
	int k = 1;

	while (k <= 100)
	{
		if (k % 3 == 0 && k % 5 == 0)
		{
			printf("FizzBuzz");
		}
		else if (k % 3 == 0)
		{
			printf("Fizz");
		}
		else if (k % 5 == 0)
		{
			printf("Buzz");
		}
		else
		{
			printf("%i", k);
		}
		if (k != 100)
		{
			putchar(' ');
		}

		k++;
	}
	putchar('\n');
	return (0);
}
