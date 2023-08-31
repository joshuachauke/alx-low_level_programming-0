#include "main.h"

/**
 * clear_bit - Sets a value of a given bit to 0
 * @n: Pointer to a numb to change
 * @index: To clear index of the bit
 *
 * Return: On success 1, -1 On failure
 */
int clear_bit(unsigned long int *n, unsigned int index)
{
	if (index > 63)
		return (-1);

	*n = (~(1UL << index) & *n);
	return (1);
}
