#include <unistd.c>
/**
 * _putchar - writes the character a to stdout
 * @c: char to printed
 * Return: 1 on sucess
 */
int _putchar(char c)
{
	return (write(1, &c, 1));
}
