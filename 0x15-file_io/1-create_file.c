#include "main.h"

/**
 * create_file – Create the files.
 * @filename: Pointer to the name of the files to be created.
 * @text_content: Pointer to the strings to write within the file.
 *
 * Return: - -1 is returned if the func fails.
 *         Otherwise return - 1.
 */
int create_file(const char *filename, char *text_content)
{
	int fd, k, len = 0;

	if (filename == NULL)
		return (-1);

	if (text_content != NULL)
	{
		for (len = 0; text_content[len];)
			len++;
	}

	fd = open(filename, O_CREAT | O_RDWR | O_TRUNC, 0600);
	k = write(fd, text_content, len);

	if (fd == -1 || k == -1)
		return (-1);

	close(fd);

	return (1);
}
