#include "main.h"

/**
 * get_endianness - Checks if a machine is little or big endian
 * Return: If big return 0, If little return 1
 */
int get_endianness(void)
{
	unsigned int t = 1;
	char *c = (char *) &t;

	return (*c);
}
