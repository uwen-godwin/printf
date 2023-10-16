#include "main.h"

/**
 * get_precision - precision calculation
 * @format: strings formated for storage 
 * @i: argument list to be printed
 * @list: args list
 *
 * Return: Precision.
 */
int my_get_precision(const char *format, int *n, va_list list)
{
	int curr_n = *n + 1;
	int precision = -1;

	if (format[curr_n] != '.')
		return (precision);

	precision = 0;

	for (curr_n += 1; format[curr_n] != '\0'; curr_n++)
	{
		if (is_digit(format[curr_n]))
		{
			precision *= 10;
			precision += format[curr_n] - '0';
		}
		else if (format[curr_n] == '*')
		{
			curr_n++;
			precision = va_arg(list, int);
			break;
		}
		else
			break;
	}

	*n = curr_n - 1;

	return (precision);
}
