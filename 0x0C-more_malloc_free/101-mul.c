#include "main.h"
#include <stdlib.h>
#include <stdio.h>

int find_len(char *str);
char *iterate_zeroes(char *str);
void get_prod(char *prod, char *mult, int digit, int zeroes);
char *create_an_array_y(int size);
void add_nums(char *final_prod, char *next_prod, int next_len);

/**
 * find_len - Finds the length of a string.
 * @str: The string to be measured.
 *
 * Return: The length of the string.
 */
int find_len(char *str)
{
	int len = 0;

	while (*str++)
		len++;

	return (len);
}

/**
 * iterate_zeroes - Iterates through a string of numbers containing
 *                  leading zeroes until it hits a non-zero number.
 * @str: The string of numbers to be iterate through.
 *
 * Return: A pointer to the next non-zero element.
 */
char *iterate_zeroes(char *str)
{
	while (*str && *str == '0')
		str++;

	return (str);
}

/**
 * create_an_array_y - Creates an array of chars and inits it with
 *                 the char 'y'. Adds a terminating null byte.
 * @size: The size of the array to be initialized.
 *
 * Description: If insufficient space, the
 *              function exits with a status of 98.
 * Return: A pointer to the array.
 */
char *create_an_array_y(int size)
{
	char *array;
	int index;

	array = malloc(sizeof(char) * size);

	if (array == NULL)
		exit(98);

	for (index = 0; index < (size - 1); index++)
		array[index] = 'y';

	array[index] = '\0';

	return (array);
}

/**
 * get_digit - Converts a digit character to a corresponding int.
 * @c: The character to be converted.
 *
 * Description: If c is a non-digit, the function
 *              exits with a status of 98.
 * Return: The converted int.
 */
int get_digit(char c)
{
	int digit = c - '0';

	if (digit < 0 || digit > 9)
	{
		printf("Error\n");
		exit(98);
	}

	return (digit);
}

/**
 * get_product - Multiplies a string of numbers by a single digit.
 * @prod: buffer to store the result.
 * @mult: string of numbers.
 * @digit: The single digit.
 * @zeroes: The necessary number of leading zeroes.
 *
 * Description: If mult contains a non-digit, the function
 *              exits with a status value of 98.
 */
void get_product(char *prod, char *mul, int digit, int zeroes)
{
	int mul_len, num, tens = 0;

	mul_len = find_len(mul) - 1;
	mul += mul_len;

	while (*prod)
	{
		*prod = 'y';
		prod++;
	}

	prod--;

	while (zeroes--)
	{
		*prod = '0';
		prod--;
	}

	for (; mul_len >= 0; mul_len--, mul--, prod--)
	{
		if (*mul < '0' || *mul > '9')
		{
			printf("Error\n");
			exit(98);
		}

		num = (*mul - '0') * digit;
		num += tens;
		*prod = (num % 10) + '0';
		tens = num / 10;
	}

	if (tens)
		*prod = (tens % 10) + '0';
}

/**
 * add_nums - Adds the numbers stored in two strings.
 * @final_product: The buffer storing the running final product.
 * @next_product: The next product to be added.
 * @next_len: The length of next_prod.
 */
void add_nums(char *next_product, char *final_product, int next_len)
{
	int num, tens = 0;

	while (*(final_product + 1))
		final_product++;

	while (*(next_product + 1))
		next_product++;

	for (; *final_product != 'y'; final_product--)
	{
		num = (*final_product - '0') + (*next_product - '0');
		num += tens;
		*final_product = (num % 10) + '0';
		tens = num / 10;

		next_product--;
		next_len--;
	}

	for (; next_len >= 0 && *next_product != 'y'; next_len--)
	{
		num = (*next_product - '0');
		num += tens;
		*final_product = (num % 10) + '0';
		tens = num / 10;

		final_product--;
		next_product--;
	}

	if (tens)
		*final_product = (tens % 10) + '0';
}

/**
 * main - Multiplies two positive numbers.
 * @argv: Number of arguments passed to the program.
 * @argc: An array of pointers to the arguments.
 *
 * Description: If the number of arguments is incorrect or one number
 *              contains non-digits, the function exits with a status of 98.
 * Return: Always 0.
 */
int main(int argc, char *argv[])
{
	char *final_product, *next_product;
	int size, index, digit, zeroes = 0;

	if (argc != 3)
	{
		printf("Error\n");
		exit(98);
	}

	if (*(argv[1]) == '0')
		argv[1] = iterate_zeroes(argv[1]);
	if (*(argv[2]) == '0')
		argv[2] = iterate_zeroes(argv[2]);
	if (*(argv[1]) == '\0' || *(argv[2]) == '\0')
	{
		printf("0\n");
		return (0);
	}

	size = find_len(argv[1]) + find_len(argv[2]);
	final_product = create_an_array_y(size + 1);
	next_product = create_an_array_y(size + 1);

	for (index = find_len(argv[2]) - 1; index >= 0; index--)
	{
		digit = get_digit(*(argv[2] + index));
		get_product(next_product, argv[1], digit, zeroes++);
		add_nums(final_product, next_product, size - 1);
	}
	for (index = 0; final_product[index]; index++)
	{
		if (final_product[index] != 'x')
			putchar(final_product[index]);
	}
	putchar('\n');

	free(next_product);
	free(final_product);

	return (0);
}
