#include "main.h"
#include <stdlib.h>

/**
 * malloc_checked - allocates memory using malloc
 * @b: bytes allocate
 * Return: pointer
 * terminates the program with exit status 98.
 */

void *malloc_checked(unsigned int b)
{
void *ptr;
ptr = malloc(b);
if (ptr == NULL)
{
	exit(98);
}
return (ptr);
}
