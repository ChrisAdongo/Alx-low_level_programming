#include "main.h"
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <stdbool.h>

/**
 * coinConverter - Helper function that works out calculations
 * @i: Passed in variable from main for calculations
 * Return: Number of coins needed minimum for the passed in variable
 */
int coinConverter(int k)
{
	int count = 0;

	while (k != 0)
	{
		if (k % 10 == 9 || k % 10 == 7)
			k -= 2;
		else if (k % 25 == 0)
			k -= 25;
		else if (k % 10 == 0)
			k -= 10;
		else if (k % 5 == 0)
			k -= 5;
			else if (k % 2 == 0)
		{
			if (k % 10 == 6)
				k -= 1;
			else
				k -= 2;
		}
		else
			k -= 1;

		count++;
	}

	return (count);
}

/**
 * main - Takes in exactly one argument for minimum coin count
 * @argc: Number of command line arguments
 * @argv: Array name
 * Return: 0 if exactly 1 argument is passed into this program, 1 otherwise
 */
int main(int argc, char *argv[])
{
	int k, coin;

	coin = 0;

	if (argc != 2)
	{
		printf("Error\n");
		return (1);
	}

	k = atoi(argv[1]);

	if (k < 0)
		printf("0\n");

	else
	{
		coin = coinConverter(k);

		printf("%d\n", coin);
	}

	return (0);
}
