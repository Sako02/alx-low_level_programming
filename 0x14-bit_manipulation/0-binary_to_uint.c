#include "main.h"

/**
 * binary_to_uint -  converts a binary number to unsigned int
 *
 * @b: is pointing to a string of 0 and 1 chars
 *
 * Return: the converted number, or 0 if @b is NULL or there is
 *		one or more chars other than 0 or 1
 */

unsigned int binary_to_uint(const char *b)
{
	unsigned int s = 0;
	int l = 0;
	int f;

	if (b == NULL)
		return (0);

	for (l = 0; b[l]; l++)
	{
		if (b[l] != '0' && b[l] != '1')
			return (0);
	}
	for (f = 1, s = 0, l--; l >= 0; l--, f *= 2)
	{
		if (b[l] == '1')
			s += f;
	}

	return (s);
}
