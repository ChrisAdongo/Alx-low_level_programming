#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "main.h"

/**
 * main - Takes in all integer arguments and returns the sum
 * @argc: Number of command line arguments
 * @argv: Array name
 * Return: 1 if a non-integer is among the passed in arguments, 0 otherwise
 */

int main(int argc, char *argv[])
{
	int j, k, length, sum;
	char *ptr;

	if (argc < 2)
	printf("0\n");
	else
	{
		sum = 0;
		for (j = 1; j < argc; j++)
		{
			ptr = argv[j];
			length = strlen(ptr);

			for (k = 0; k < length; k++)
			{
				if (isdigit(*(ptr + k)) == 0)
				{
					printf("Error\n");
					return (1);
				}
			}

			sum += atoi(argv[j]);
		}

		printf("%d\n", sum);
	}
	return (0);
}
