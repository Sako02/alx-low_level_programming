#include "main.h"
/**
 * computes the absolute value of an integer.
 * @n: function parameters N 
 *  * Return: Always 0.
 */
int _abs(int N)
{
if (N < 0)
{
N = (-1) * N;
}
_putchar(N);
return (N);
}
