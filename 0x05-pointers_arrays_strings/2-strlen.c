#include "main.h"
#include <stdio.h>

/**
 * _strlen - returns the length of a string
 * @s: string to be checked
 * Return: returns the length of @s
 */

int _strlen(char *s)
{
	int count = 0;

	while (s[count] != '\0')
		count++;
	return (count);
}
