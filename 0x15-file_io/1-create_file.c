#include "main.h"

/**
 * create_file - A function that creates a file.
 * @filename: Pointer to the name of the file to be created.
 * @text_content: Pointer to a string to write to the file.
 *
 * Return: 1, Otherwise - -1 if the function fails.
 */
int create_file(const char *filename, char *text_content)
{
	int len = 0;
	int o;
	int w;

	if (filename == NULL)
		return (-1);

	if (text_content != NULL)
	{
		for (len = 0; text_content[len];)
			len++;
	}

	o = open(filename, O_CREAT | O_TRUNC | O_RDWR, 0600);
	w = write(o, text_content, len);

	if (o == -1 || w == -1)
	{
		return (-1);
	}

	close(o);

	return (1);
}
