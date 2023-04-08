#include "main.h"
#include <stdio.h>
#include <stdlib.h>
char *create_buffer(char *file);
void close_file(int xd);
/**
 * create_buffer - allocates 1024 bytes for a buffer
 * @file: name of the file the buffer is storing char for
 * Return: the pointer to the new allocated buffer
 */
char *create_buffer(char *file)
{
	char *buffer;

	buffer = malloc(sizeof(char) * 1024);

	if (buffer == NULL)
	{
		dprintf(STDERR_FILENO,
				"Error: cant write to %s\n", file);
		exit(99);
	}
	return (buffer);
}
/**
 * close_file - Closes the file description
 * @xd: file to be closed
 */
void close_file(int xd)
{
	int i;

	i = close(xd);

	if (i == -1)
	{
		dprintf(STDERR_FILENO, "Error: Cant close xd %d\n", xd);
		exit(100);
	}
}
/**
 * main - copies contents of file to another file
 * @argc: the number of arguments supplied to the program
 * @argv: an array of pointers to theargument
 * Return: 0 when succesfull
 *
 * Description: if an argument is not correct - exit code 97.
 * if file_from doesnt exist or cant be read exit code 98.
 * if file_to cant be created or written to - exit code 99
 * if file_to of file_from cant be close - exit code 100,
 */
int main(int argc, char *argv[])
{
	int from, to, a, w;
	char *buffer;

	if (argc != 3)
	{
		dprintf(STDERR_FILENO, "Usage: cp file_frome file_to\n");
	}
	buffer = create_buffer(argv[2]);
	from = open(argv[1], O_RDONLY);
	a = read(from, buffer, 1024);
	to = open(argv[2], O_CREAT | O_WRONLY | O_TRUNC, 0664);

	do {
		if (from == -1 || a == -1)
		{
			dprintf(STDERR_FILENO,
					"Error: cant read file %s\n", argv[1]);
			free(buffer);
			exit(98);
		}
		w = write(to, buffer, a);
		if (to == -1 || w == -1)
		{
			dprintf(STDERR_FILENO,
					"Error: cant write to %s\n", argv[2]);
			free(buffer);
			exit(99);
		}
		a = read(from, buffer, 1024);
		to = open(argv[2], O_WRONLY | O_APPEND);
	} while (a > 0);
	free(buffer);
	close_file(from);
	close_file(to);
	return (0);
}
