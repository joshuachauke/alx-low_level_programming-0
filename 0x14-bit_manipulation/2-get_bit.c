#include "main.h"

/**
 * get_bit - A value of a bit at an index in a decimal numb is returned
 * @n: Numb to search
 * @index: The bit index
 *
 * Return: The bit value
 */
int get_bit(unsigned long int n, unsigned int index)
{
	int bit_val;

	if (index > 63)
		return (-1);

	bit_val = (n >> index) & 1;

	return (bit_val);
}
