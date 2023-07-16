#include "main.h"

/**
 * read_textfile - Function that reads a text file
 * and prints it to the POSIX standard output
 * @filename: the name of the file to read
 * @letters: the number of letters to read and print
 *
 * Return: if the file can not be opened or read, return 0
 */

ssize_t read_textfile(const char *filename, size_t letters)
{
	int filedesc, rd, wt;
	char *buffer;

	if (!filename)
		return (0);

	filedesc = open(filename, O_RDONLY);
	if (filedesc == -1)
		return (0);

	buffer = malloc(sizeof(char) * (letters + 1));
	if (!buffer)
		return (0);

	rd = read(filedesc, buffer, letters);
	if (rd == -1)
	{
		free(buffer);
		close(filedesc);
		return (0);
	}

	buffer[rd] = '\0';

	wt = write(STDOUT_FILENO, buffer, rd);
	if (wt == -1 || wt != rd)
	{
		free(buffer);
		close(filedesc);
		return (0);
	}

	free(buffer);
	close(filedesc);

	return (rd);
}
