#include "main.h"

/**
 * read_textfile - it reads a text file and prints the letters
 * @filename: filename.
 * @letters: numbers of letters printed.
 *
 * Return: numbers of letters printed. It fails, returns 0.
 */
ssize_t read_textfile(const char *filename, size_t letters)
{
    int frw;  
    ssize_t n, m;
    char *buf;

    if (!filename)
        return (0);

    frw = open(filename, O_RDONLY);

    if (frw == -1)
        return (0);

    buf = malloc(sizeof(char) * (letters));
    if (!buf)
        return (0);

    n = read(frw, buf, letters);
    m = write(STDOUT_FILENO, buf, n);

    close(frw);

    free(buf);

    return (m);
}
