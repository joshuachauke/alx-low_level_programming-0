#include "main.h"

/**
 * binary_to_uint - Converts a binary number to unsigned interge
 * @b: String containing the binary numb
 *
 * Return: A converted numb
 */
unsigned int binary_to_uint(const char *b)
{
	int t;
	unsigned int dec_val = 0;

	if (!b)
		return (0);

	for (t = 0; b[t]; t++)
	{
		if (b[t] < '0' || b[t] > '1')
			return (0);
		dec_val = 2 * dec_val + (b[t] - '0');
	}

	return (dec_val);
}
