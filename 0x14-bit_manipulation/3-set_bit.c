#include "main.h"

/**
 * set_bit - Sets the bit at a given index to 1
 * @n: Pointer to a numb to change
 * @index: Set index of the bit to 1
 *
 * Return: On success 1, -1 On failure
 */
int set_bit(unsigned long int *n, unsigned int index)
{
	if (index > 63)
		return (-1);

	*n = ((1UL << index) | *n);
	return (1);
}
