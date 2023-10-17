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
	int j = *i + 1;
	int precision = -1;

	if (format[j] != '.')
		return (precision);

	precision = 0;

	for (j += 1; format[j] != '\0'; ++)
	{
		if (is_digit(format[j]))
		{
			precision *= 10;
			precision += format[j] - '0';
		}
		else if (format[j] == '*')
		{
			j++;
			precision = va_arg(list, int);
			break;
		}
		else
			break;
	}
	*i = j - 1;

	return (precision);
}
