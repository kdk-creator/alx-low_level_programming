#include "main.h"
/**
 * puts2 -  prints the characters of string with first character
 * @str: strings to be printed
 * return nothing on success
 */

void puts2(char *str)
{
	int count = 0, i;

	while (*str)
	{
		count++;
		str++;
	}
	for (i = 0; i < count; i++)
	{
		str--;
	}
	for (i = 0; i < count; i++)
	{
		if (i % 2 == 0)
			_putchar(str[i]);
	}
	_putchar('\n');
}
