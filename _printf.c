#include "main.h"

void my_buffer(char buffer[], int *buff_ind);

/**
 * _printf - The Printf function
 * @format: Format specifiers
 * Return: Byte printe
 */
int _printf(const char *format, ...)
{
	int n, printed = 0;
	int printed_chars = 0;
	int flags, width, precision, size, buff_ind = 0;
	va_list list;
	char buffer[BUFF_SIZE];

	if (format == NULL)
		return (-1);

	va_start(list, format);

	for (n = 0; format && format[n] != '\0'; n++)
	{
		if (format[n] != '%')
		{
			buffer[buff_ind++] = format[n];
			if (buff_ind == BUFF_SIZE)
				my_buffer(buffer, &buff_ind);
			/* write(1, &format[i], 1);*/
			printed_chars++;
		}
		else
		{
			my_buffer(buffer, &buff_ind);
			flags = get_flags(format, &n);
			width = get_width(format, &n, list);
			precision = get_precision(format, &n, list);
			size = get_size(format, &n);
			++n;
		}
		if (format[n] == 'r')
		{
			int r_value = va_arg(list, int);
			char temp_buffer[20];
			int temp_buff_ind = 0;

			snprintf(temp_buffer, sizeof(temp_buffer), "[%d]", r_value);
			while (temp_buffer[temp_buff_ind] != '\0')
			{
			buffer[buff_ind++] = temp_buffer[temp_buff_ind];
			if (buff_ind == BUFF_SIZE)
				my_buffer(buffer, &buff_ind);
			temp_buff_ind++;
			}
		}
		else
		{
			printed = handle_print(format, &n, list, buffer,
				flags, width, precision, size);
			if (printed == -1)
				return (-1);
			printed_chars += printed;
		}
	}

	my_buffer(buffer, &buff_ind);

	va_end(list);

	return (printed_chars);
}

/**
 * my_buffer - Function to Prints the contents of the buffer if it exist
 * @buffer: The array of chars
 * @buff_ind: The index at which to add next char, represents the length.
 */

void my_buffer(char buffer[], int *buff_ind)
{
	if (*buff_ind > 0)
		write(1, &buffer[0], *buff_ind);

	*buff_ind = 0;
}
