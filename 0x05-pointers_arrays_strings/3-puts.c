#include "main.h"

/**
 * _puts - print a string folloed by a new line to stdout
 * @str: string to be print
 * Return nothing on success
 */

void _puts(char *str)
{
	for (; *str != '\0'; str++)
	{
		_putchar(*str);
	}
	_putchar('\n');
}
