#include "main.h"

/**
 * get_width - Determine the output width for formatting.
 *
 * Description:
 * This function calculates the appropriate output
 * width for formatting based on the format string and arguments.
 *
 * @format: The formatted string containing the arguments.
 * @i: List of arguments to be formatted.
 *
 * Return:
 * The calculated output width.
 */
int get_width(const char *format, int *i, va_list list)
{
	int j;
	int width = 0;

	for (j = *i + 1; format[j] != '\0'; j++)
	{
		if (is_digit(format[j]))
		{
			width *= 10;
			width += format[j] - '0';
		}
		else if (format[j] == '*')
		{
			j++;
			width = va_arg(list, int);
			break;
		}
		else
			break;
	}
	*i = j - 1;

	return (width);
}