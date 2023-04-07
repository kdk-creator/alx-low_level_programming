#include "main.h"
#include <stdlib.h>
/**
 * read_textfile - will read text file and print to stdout
 * @filename: file being read
 * @letters: numbers of the letter to be read
 * Return: actual numbers of bytes and print 0 when func fails
 */
ssize_t read_textfile(const char *filename, size_t letters)
{
	char *buf;
	ssize_t ab;
	ssize_t x;
	ssize_t t;

	ab = open(filename, O_RDONLY);
	if (ab == -1)
		return (0);
	buf = malloc(sizeof(char) * letters);
	t = read(ab, buf, letters);
	x = write(STDOUT_FILENO, buf, t);
	free(buf);
	close(ab);
	return (x);
}
