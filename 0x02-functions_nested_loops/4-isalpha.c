#include "main.h"

/**
 * _isalpha - this checks for alphabetical chrarcters
 * @c: the chracter to be checked
 * Return: 1 for alphabetical charater and 0 for anything else
 */

int _isalpha(int c)
{
	if ((c >= 65 && c <= 90) || (c >= 97 && c <= 122))
	{
		return (1);
	}
	return (0);
}
