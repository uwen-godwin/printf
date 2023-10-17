#include "main.h"

/**
 * get_size - Determine the data size for argument casting.
 *
 * Description:
 * This function calculates the appropriate data size
 * for casting the argument based on the format string and arguments.
 *
 * @format: The formatted string containing the arguments.
 * @i: List of arguments to be formatted.
 *
 * Return:
 * The calculated data size.
 */
int get_size(const char *format, int *i)
{
	int x = *i + 1;
	int size = 0;

	if (format[x] == 'l')
		size = S_LONG;
	else if (format[x] == 'h')
		size = S_SHORT;

	if (size == 0)
		*i = x - 1;
	else
		*i = x;

	return (size);
}
