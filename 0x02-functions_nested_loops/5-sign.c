#include "main.h"
/**
 * print_sign - a function that prints the sign of a number.
 * @n: function parameters
 * Return: 1 for positive num, -2 for negative num or 0 for anything else
 */
int print_sign(int n)
{
if (n > 0)
{
_putchar('+');
return (1);
}
else if (n == 0)
{
_putchar('0');
return (0);
}
else
{
_putchar('-');
return (-1);       
}
}
