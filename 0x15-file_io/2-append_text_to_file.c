#include "main.h"
/**
 * append_text_to_file - it append text to the end of a file
 * @text_content: stringto add to the file end
 * @filename: points to the name of the file
 * Return: if the funct fail or filename is NULL --1
 * if the file does not exist, user lack write permissions --1
 * else -1
 */
int append_text_to_file(const char *filename, char *text_content)
{
	int x, t, len = 0;

	if (filename == NULL)
		return (-1);
	if (text_content != NULL)
	{
		for (len = 0; text_content[len];)
			len++;
	}
	x = open(filename, O_WRONLY | O_APPEND);
	t = write(x, text_content, len);

	if (x == -1 || t == -1)
		return (-1);
	close(x);

	return (1);
}
