#include "main.h"
/**
 * create_file - this create a file
 * @filename: A pointer to string which will write the file
 * @text_content: point to a string to write to file
 * Retrun: if the funct fails --1 otherwise -1
 */
int create_file(const char *filename, char *text_content)
{
	int bd, x, len = 0;

	if (filename == NULL)
		return (-1);
	if (text_content != NULL)
	{
		for (len = 0; text_content[len];)
			len++;
	}
	bd = open(filename, O_CREAT | O_RDWR | O_TRUNC, 0600);
	x = write(bd, text_content, len);

	if (bd == -1 || x == -1)
		return (-1);
	close(bd);
	return (1);
}
