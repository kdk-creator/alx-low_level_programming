#include "main.h"
/**
 * set_bit - sets the value of a bit to 1 at given index
 * @n: points to an unsigned long int
 * @index: index of the bit
 * Return: 1 when it works, -1 if it didnt
 */
int set_bit(unsigned long int *n, unsigned int index)
{
	unsigned int x;

	if (index > 63)
		return (-1);

	x = 1 << index;
	*n = (*n | x);

	return (1);
}
