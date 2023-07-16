#include "main.h"

/**
 * append_text_to_file - appends text at the end of the file
 * @filename: the name of the file
 * @text_content: the text to append to the file
 *
 * Return: 1 on success, -1 on failure
 */

int append_text_to_file(const char *filename, char *text_content)
{
	int filedesc, bytes_writ;
	size_t txt_len = 0;

	if (filename == NULL)
		return (-1);

	if (text_content != NULL)
	{
		while (text_content[txt_len] != '\0')
			txt_len++;
	}

	filedesc = open(filename, O_WRONLY | O_APPEND);
	if (filedesc == -1)
		return (-1);

	bytes_writ = write(filedesc, text_content, txt_len);
	if (bytes_writ == -1 || (size_t)bytes_writ != txt_len)
	{
		close(filedesc);
		return (-1);
	}

	close(filedesc);
	return (1);
}
