#include "main.h"

/**
 * print_most_numbers - print num from 0 to 9
 * Description: prints the number excluding 2 and 4
 * return: void
 */

void print_most_numbers(void)
{
	int x;

	for (; x  <= 9; x++)
	{
		if (x == 2 || x == 4)
		{
			continue;
		}
		else
		{
			_putchar(x + '0');
		}
	}
	_putchar('\n');
}
