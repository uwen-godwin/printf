#include "main.h"

/**
 * handle_print - Print the arguments according to the format string.
 * @fmt: The format string.
 * @list: The variable argument list.
 * @ind: The current index.
 * @buffer: The buffer array for printing.
 * @flags: The active flags.
 * @width: The specified width.
 * @precision: The precision specification.
 * @size: The size specifier.
 * Return: 1 or 2 based on success or failure.
 */
int handle_print(const char *fmt, int *ind, va_list list, char buffer[],
	int flags, int width, int precision, int size)
{
	int f, notknown_len = 0;
	int printed_chars = -1;
	fmt_t fmt_types[] = {
		{'c', print_char}, {'s', print_string}, {'%', print_percent},
		{'i', print_int}, {'d', print_int}, {'b', print_binary},
		{'u', print_unsigned}, {'o', print_octal}, {'x', print_hexadecimal},
		{'X', print_hexa_upper}, {'p', print_pointer}, {'S', print_non_printable},
		{'r', print_reverse}, {'R', print_rot13string}, {'\0', NULL}
	};
	for (f = 0; fmt_types[f].fmt != '\0'; f++)
		if (fmt[*ind] == fmt_types[f].fmt)
			return (fmt_types[f].fn(list, buffer, flags, width, precision, size));

	if (fmt_types[f].fmt == '\0')
	{
		if (fmt[*ind] == '\0')
			return (-1);
		notknown_len += write(1, "%%", 1);
		if (fmt[*ind - 1] == ' ')
			notknown_len += write(1, " ", 1);
		else if (width)
		{
			--(*ind);
			while (fmt[*ind] != ' ' && fmt[*ind] != '%')
				--(*ind);
			if (fmt[*ind] == ' ')
				--(*ind);
			return (1);
		}
		notknown_len += write(1, &fmt[*ind], 1);
		return (notknown_len);
	}
	return (printed_chars);
}
