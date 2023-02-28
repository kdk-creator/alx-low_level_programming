#include "main.h"
#include <stdio.h>

/**
 * print_array -  prints n elements of an array of integers
 * @a: array to be printed
 * @n: numbers to be printed
 * Return: nothing on success
 */

void print_array(int *a, int n)
{
	int count = 0;

	while (count < 0)
	{
		printf("%d", a[count]);

		if (count != (n - 1))
			printf(", ");
		count++;
	}
	putchar('\n');
}
