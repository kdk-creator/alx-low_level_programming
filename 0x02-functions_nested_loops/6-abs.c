#include "main.h"

/**
 * _abs - compute absolute values of integers
 * @c: the number that is to be computed
 * Return: absolute value or number of zero
 */

int _abs(int c)

{
	if (c < 0)
	{
		int abs_val;

		abs_val = c * -1;
		return (abs_val);
	}
	return (c);
}
