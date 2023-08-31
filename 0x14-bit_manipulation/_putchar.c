#include "main.h"
#include <unistd.h>
/**
 * _putchar - Writes the Character c to stdout
 * @c: Character to print
 *
 * Return: 1 on success .
 * On error, RETURN -1, & ERRNO is set appropriately.
 */
int _putchar(char c)
{
	return (write(1, &c, 1));
}
