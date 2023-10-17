#include "main.h"
/**
 * get_precision - Determine the precision for formatting.
 *
 * Description:
 * This function calculates the precision for formatting
 * based on the format string and arguments.
 *
 * @format: The formatted string containing the arguments.
 * @i: List of arguments to be formatted.
 * @list: List of arguments.
 *
 * Return:
 * The calculated precision.
 */

int get_precision(const char *format, int *i, va_list list)
{
	int p = *i + 1;
	int precision = -1;

	if (format[p] != '.')
		return (precision);

	precision = 0;

	for (p += 1; format[p] != '\0'; p++)
	{
		if (is_digit(format[p]))
		{
			precision *= 10;
			precision += format[p] - '0';
		}
		else if (format[p] == '*')
		{
			p++;
			precision = va_arg(list, int);
			break;
		}
		else
			break;
	}
	*i = p - 1;

	return (precision);
}
