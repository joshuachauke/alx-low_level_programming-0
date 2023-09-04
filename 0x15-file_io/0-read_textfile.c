#include "main.h"
#include <stdlib.h>

/**
 * read_textfile- To read text file that prints STDOUT.
 * @filename: Text file that should be read
 * @letters: Numb of letters that should be read
 * Return: w- actual numb of the bytes read and printed
 *        When function fails return 0 or when Filename is NULL.
 */
ssize_t read_textfile(const char *filename, size_t letters)
{
	char *buf;
	ssize_t fd;
	ssize_t m;
	ssize_t q;

	fd = open(filename, O_RDONLY);
	if (fd == -1)
		return (0);
	buf = malloc(sizeof(char) * letters);
	m = read(fd, buf, letters);
	q = write(STDOUT_FILENO, buf, m);

	free(buf);
	close(fd);
	return (q);
}
