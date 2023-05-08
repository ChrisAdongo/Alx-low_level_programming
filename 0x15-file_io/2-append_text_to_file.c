#include "main.h"

/**
 * append_text_to_file - Appends text at the end of a file.
 * @filename: Pointer to the name of the file
 * @text_content: The text to append to the end of the file.
 *
 * Return: 1 on success, Otherwise - -1.
 */
int append_text_to_file(const char *filename, char *text_content)
{
	int o;
	int len;
	int my_bytes;

	if (filename == NULL)
		return (-1);

	o = open(filename, O_WRONLY | O_APPEND);
	if (o == -1)
		return (-1);

	if (text_content == NULL)
	{
		close(o);
		return (1);
	}

	len = 0;
	while (text_content[len] != '\0')
		len++;

	my_bytes = write(o, text_content, len);
	close(o);

	if (my_bytes == len)
		return (1);
	else
		return (-1);
}
