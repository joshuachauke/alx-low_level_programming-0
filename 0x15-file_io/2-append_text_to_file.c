#include "main.h"

/**
 * append_text_to_file - At the end of a file write Appends text.
 * @filename: Pointer to the file’s name.
 * @text_content: String added to the end of the file.
 *
 * Return: - -1 is returned If the function fails or filename is NULL.
 *        also, - -1 If the file does not exist the user lacks  rights.
 *       - 1 Otherwise.
 */
int append_text_to_file(const char *filename, char *text_content)
{
	int p, k, len = 0;

	if (filename == NULL)
		return (-1);

	if (text_content != NULL)
	{
		for (len = 0; text_content[len];)
			len++;
	}

	p = open(filename, O_WRONLY | O_APPEND);
	k = write(p, text_content, len);

	if (p == -1 || k == -1)
		return (-1);

	close(p);

	return (1);
}
