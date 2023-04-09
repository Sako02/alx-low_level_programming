#include "main.h"

/**
 * _pow_recursion - Calculate the power of x of a giving number y
 * @x: Value to multiply
 * @y: Time to multiply
 *
 * Return: Int
 */

int _pow_recursion(int x, int y)
{
	if (y < 0)
		return (-1);

	if (y == 0)
		return (1);

	return (x * _pow_recursion(x, y - 1));
}

