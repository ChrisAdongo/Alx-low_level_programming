#include "main.h"
#include <stdlib.h>
#include <stdio.h>

char *my_current(char *file);
void stop_f(int o);

/**
 * main - Copies the contents of a file to another file.
 * @argc: Number of arguments supplied to the program.
 * @argv: Array of pointers to the arguments.
 *
 * Description: If argument count is incorrect - exit with code 97.
 * If file_to can't be written to or created - exit with code 99.
 * If file_from does not exist or cannot be read - exit with code 98.
 * If file_to or file_from can't be closed - exit with code 100.
 *
 * Return: 0 on success.
 */
int main(int argc, char *argv[])
{
	int f;
	int t;
	int r;
	int w;
	char *b;

	if (argc != 3)
	{
		dprintf(STDERR_FILENO, "Usage: cp file_from file_to\n");
		exit(97);
	}

	b = my_current(argv[2]);
	f = open(argv[1], O_RDONLY);
	r = read(f, b, 1024);
	t = open(argv[2], O_CREAT | O_WRONLY | O_TRUNC, 0664);

	do {
		if (f == -1 || r == -1)
		{
			dprintf(STDERR_FILENO,
				"Error: Can't read from file %s\n", argv[1]);
			free(b);
			exit(98);
		}

		w = write(t, b, r);
		if (t == -1 || w == -1)
		{
			dprintf(STDERR_FILENO,
				"Error: Can't write to %s\n", argv[2]);
			free(b);
			exit(99);
		}

		r = read(f, b, 1024);
		t = open(argv[2], O_WRONLY | O_APPEND);

	} while (r > 0);

	free(b);
	stop_f(f);
	stop_f(t);

	return (0);
}

/**
 * my_current - Allocates 1024 bytes for a buffer.
 * @file: Name of the file buffer is storing chars for.
 *
 * Return: Pointer to the newly-allocated buffer.
 */
char *my_current(char *file)
{
	char *b;

	b = malloc(sizeof(char) * 1024);

	if (b == NULL)
	{
		dprintf(STDERR_FILENO,
			"Error: Can't write to %s\n", file);
		exit(99);
	}

	return (b);
}

/**
 * stop_f - Closes file descriptors.
 * @o: File descriptor to be closed.
 */
void stop_f(int o)
{
	int k;

	k = close(o);

	if (k == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't close fd %d\n", o);
		exit(100);
	}
}
