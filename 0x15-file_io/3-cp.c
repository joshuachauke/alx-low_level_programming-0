#include "main.h"
#include <stdio.h>
#include <stdlib.h>

char *create_buffer(char *file);
void close_file(int fd);

/**
 * create_buffer – Should allocate 1024 bytes for a buf.
 * @file: The file name the buf is storing characters for.
 *
 * Return: Pointer to the buf that is newly-allocated.
 */
char *create_buffer(char *file)
{
	char *buffer;

	buffer = malloc(sizeof(char) * 1024);

	if (buffer == NULL)
	{
		dprintf(STDERR_FILENO,
			"Error: Can't write to %s\n", file);
		exit(99);
	}

	return (buffer);
}

/**
 * close_file - Closes file descriptors.
 * @fd: The file descriptor to be closed.
 */
void close_file(int fd)
{
	int a;

	a = close(fd);

	if (a == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't close fd %d\n", fd);
		exit(100);
	}
}

/**
 * main – should copies file cont to another file.
 * @argc: Arguments numb supplied to the program.
 * @argv: Pointers array to the arguments.
 *
 * Return: On success return 0.
 *
 * Description: Exit code 97 if the argument count is not correct.
 * Exit code 98 if the file_from does not exist or cannot be read.
 * Exit code 99 if file_to cannot be created or written.
 * Exit code 100 if file_to or file_from cannot be closed.
 */
int main(int argc, char *argv[])
{
	int from, to, s, k;
	char *buffer;

	if (argc != 3)
	{
		dprintf(STDERR_FILENO, "Usage: cp file_from file_to\n");
		exit(97);
	}

	buffer = create_buffer(argv[2]);
	from = open(argv[1], O_RDONLY);
	s = read(from, buffer, 1024);
	to = open(argv[2], O_CREAT | O_WRONLY | O_TRUNC, 0664);

	do {
		if (from == -1 || s == -1)
		{
			dprintf(STDERR_FILENO,
				"Error: Can't read from file %s\n", argv[1]);
			free(buffer);
			exit(98);
		}

		k = write(to, buffer, s);
		if (to == -1 || k == -1)
		{
			dprintf(STDERR_FILENO,
				"Error: Can't write to %s\n", argv[2]);
			free(buffer);
			exit(99);
		}

		s = read(from, buffer, 1024);
		to = open(argv[2], O_WRONLY | O_APPEND);

	} while (s > 0);

	free(buffer);
	close_file(from);
	close_file(to);

	return (0);
}
