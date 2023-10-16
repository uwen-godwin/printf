#include "main.h"

void print_buffer(char buffer[], int *buff_ind);

/**
 * _printf - Function to Printf
 * @format: format.
 * Return: The character to be printed.
 */
int _printf(const char *format, ...)
{
	int j, print = 0, printed_chars = 0;
	int flag, width, precisn, size, buff_ind = 0;
	va_list list;
	char buffer[BUFF_SIZE];

	if (format == NULL)
		return (-1);

	va_start(list, format);

	for (j = 0; format && format[j] != '\0'; j++)
	{
		if (format[j] != '%')
		{
			buffer[buff_ind++] = format[j];
			if (buff_ind == BUFF_SIZE)
				print_buffer(buffer, &buff_ind);
			/* write(1, &format[i], 1);*/
			printed_chars++;
		}
		else
		{
			print_buffer(buffer, &buff_ind);
			flag = get_flags(format, &j);
			width = get_width(format, &j, list);
			precisn = get_precision(format, &j, list);
			size = get_size(format, &j);
			++j;
			print = handle_print(format, &j, list, buffer,
				flag, width, precisn, size);
			if (print == -1)
				return (-1);
			printed_chars += print;
		}
	}

	print_buffer(buffer, &buff_ind);

	va_end(list);

	return (printed_chars);
}

/**
 * print_buffer - The contents of the buffer if it exist
 * @buffer: Array of chars
 * @buff_ind: add next char, represents the length.
 */
void print_buffer(char buffer[], int *buff_ind)
{
	if (*buff_ind > 0)
		write(1, &buffer[0], *buff_ind);

	*buff_ind = 0;
}
