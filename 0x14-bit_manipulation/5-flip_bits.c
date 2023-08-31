#include "main.h"

/**
 * flip_bits - Counts  numb of bits to change
 * To get from one numb to another
 * @n: First numb
 * @m: Second numb
 *
 * Return: The numb of bits that will change
 */
unsigned int flip_bits(unsigned long int n, unsigned long int m)
{
	int t, count = 0;
	unsigned long int current;
	unsigned long int exclusive = n ^ m;

	for (t = 63; t >= 0; t--)
	{
		current = exclusive >> t;
		if (current & 1)
			count++;
	}

	return (count);
}
