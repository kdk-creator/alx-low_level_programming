#include "main.h"

/**
 * print_rev - print a string in reverse followed by a new line
 * @s: string to be checked
 * Return: nothing on sucess
 */

void print_rev(char *s)
{
	int count = 0;

	while (*s)
	{
		s++;
		count++;
	}
	while (count)
	{
		s--;
		_putchar(*s);
		count--;
	}
	_putchar ('\n');
}
