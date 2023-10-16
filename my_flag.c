#include "main.h"

/**
 * flag_handler - format for pwrcent calculation
 * @str: formated string
 * @args: arguments
 * @i: long iterator
 * Return: Size of the numbers of elements printed
 **/

int flag_handler(const char *str, va_list args, int *i)
{
	int size, k, num_formats;
	form formats[] = {
		{'s', print_string}, {'c', print_char},
		{'d', print_integer}, {'i', print_integer},
		{'b', print_binary}, {'u', print_u},
		{'o', print_o}, {'x', print_x},
		{'X', print_X}, {'p', print_p},
		{'S', print_S}, {'r', print_r},
		{'R', print_R}
	};

	*i = *i + 1;

	if (str[*i] == '\0')
		return (-1);

	if (str[*i] == '%')
	{
		put_char('%');
		return (1);
	}

	num_formats = sizeof(formats) / sizeof(formats[0]);
	for (size = k = 0; k < num_formats; k++)
	{
		if (str[*i] == formats[k].typ)
		{
			size = formats[k].fa(args);
			return (size);
		}
	}

	put_char('%'), put_char(str[*i]);

	return (2);
}
