#include "main.h"

/**
 * create_file - Function that creates a file with the given
 * name and writes the given text content to it
 * @filename: the name of the file to create
 * @text_content: the text content to write to the file
 *
 * Return: 1 on success, -1 on failure
 */

int create_file(const char *filename, char *text_content)
{
	int filedesc, res, len = 0;

	if (!filename)
		return (-1);

	filedesc = open(filename, O_WRONLY | O_CREAT | O_TRUNC, S_IRUSR | S_IWUSR);
	if (filedesc == -1)
		return (-1);

	if (text_content)
	{
		while (text_content[len])
			len++;
		res = write(filedesc, text_content, len);
		if (res != len)
		{
			close(filedesc);
			return (-1);
		}
	}

	close(filedesc);
	return (1);
}
