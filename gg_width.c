#include "main.h"

/**
 * get_width - Determine the output width for formatting.
 * @list: Number of items
 * @format: The formatted string containing the arguments.
 * @i: List of arguments to be formatted.
 * Return: The calculated output width.
 */
int get_width(const char *format, int *i, va_list list)
{
	int p;
	int width = 0;

	for (p = *i + 1; format[p] != '\0'; p++)
	{
		if (is_digit(format[p]))
		{
			width *= 10;
			width += format[p] - '0';
		}
		else if (format[p] == '*')
		{
			p++;
			width = va_arg(list, int);
			break;
		}
		else
			break;
	}
	*i = p - 1;

	return (width);
}
