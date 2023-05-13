#include "main.h"

/**
 * append_text_to_file -function that appends text at the end of a file
 * @filename: the name of the file
 * @text_content: the text to append to the file
 *
 * Return: 1 on success, -1 on failure
 */

int append_text_to_file(const char *filename, char *text_content)
{
	int fl, bytes_written;
	size_t lent = 0;

	if (filename == NULL)
		return (-1);

	if (text_content != NULL)
	{
		while (text_content[lent] != '\0')
			lent++;
	}

	fl = open(filename, O_WRONLY | O_APPEND);
	if (fl == -1)
		return (-1);

	bytes_written = write(fl, text_content, lent);
	if (bytes_written == -1 || (size_t)bytes_written != lent)
	{
		close(fl);
		return (-1);
	}

	close(fl);
	return (1);
}
