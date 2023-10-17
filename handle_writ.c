#include "main.h"

/**
 * handle_write_char - Print a character
 *
 * Description:
 * This function prints a single character,
 * handling any specified formatting options.
 *
 * @c: The character to be printed.
 * @buffer: Buffer array used for printing.
 * @flags: Calculation of active formatting flags.
 * @width: Specified width.
 * @precision: Precision specifier.
 * @size: Size specifier.
 *
 * Return:
 * The number of characters printed.
 */

int handle_write_char(char c, char buffer[],
	int flags, int width, int precision, int size)
{
	int b = 0;
	char padd = ' ';

	UNUSED(precision);
	UNUSED(size);

	if (flags & F_ZERO)
		padd = '0';

	buffer[b++] = c;
	buffer[b] = '\0';

	if (width > 1)
	{
		buffer[BUFF_SIZE - 1] = '\0';
		for (b = 0; b < width - 1; b++)
			buffer[BUFF_SIZE - b - 2] = padd;
		if (flags & F_MINUS)
			return (write(1, &buffer[0], 1) +
		write(1, &buffer[BUFF_SIZE - b - 1], width - 1));
		else
			return (write(1, &buffer[BUFF_SIZE - b - 1], width - 1) +
		write(1, &buffer[0], 1));
	}
	return (write(1, &buffer[0], 1));
}

/**
 * write_number - Print a formatted number
 *
 * Description:
 * This function prints a formatted number,
 * considering various parameters and options.
 *
 * @is_negative: A flag to indicate if the number is negative.
 * @ind: The current index or position in the format string.
 * @buffer: Buffer array used for printing.
 * @flags: Calculation of active formatting flags.
 * @width: Specified width.
 * @precision: Precision specifier.
 * @size: Size specifier.
 *
 * Return:
 * The number of characters printed.
 */
int write_number(int is_negative, int ind, char buffer[],
	int flags, int width, int precision, int size)
{
	int len = BUFF_SIZE - ind - 1;
	char padd = ' ', extra_ch = 0;

	UNUSED(size);
	if ((flags & F_ZERO) && !(flags & F_MINUS))
		padd = '0';
	if (is_negative)
		extra_ch = '-';
	else if (flags & F_PLUS)
		extra_ch = '+';
	else if (flags & F_SPACE)
		extra_ch = ' ';

	return (write_num(ind, buffer, flags, width, precision,
		len, padd, extra_ch));
}

/**
 * write_num - Write a number to a buffer with formatting
 *
 * Description:
 * This function writes a formatted number to a
 * buffer, considering various options and parameters.
 *
 * @ind: Index indicating the start of the number in the buffer.
 * @buffer: The buffer where the number is written.
 * @flags: Formatting flags.
 * @width: The specified width.
 * @prec: Precision specifier.
 * @length: Length of the number.
 * @padd: Padding character.
 * @extra_c: Extra character.
 *
 * Return:
 * The number of characters printed.
 */

int write_num(int ind, char buffer[],
	int flags, int width, int prec,
	int length, char padd, char extra_c)
{
	int v, padd_start = 1;

	if (prec == 0 && ind == BUFF_SIZE - 2 && buffer[ind] == '0' && width == 0)
		return (0);
	if (prec == 0 && ind == BUFF_SIZE - 2 && buffer[ind] == '0')
		buffer[ind] = padd = ' ';
	if (prec > 0 && prec < length)
		padd = ' ';
	while (prec > length)
		buffer[--ind] = '0', length++;
	if (extra_c != 0)
		length++;
	if (width > length)
	{
		for (v = 1; v < width - length + 1; v++)
			buffer[v] = padd;
		buffer[v] = '\0';
		if (flags & F_MINUS && padd == ' ')
		{
			if (extra_c)
				buffer[--ind] = extra_c;
			return (write(1, &buffer[ind], length) + write(1, &buffer[1], v - 1));
		}
		else if (!(flags & F_MINUS) && padd == ' ')
		{
			if (extra_c)
				buffer[--ind] = extra_c;
			return (write(1, &buffer[1], v - 1) + write(1, &buffer[ind], length));
		}
		else if (!(flags & F_MINUS) && padd == '0')
		{
			if (extra_c)
				buffer[--padd_start] = extra_c;
			return (write(1, &buffer[padd_start], v - padd_start) +
				write(1, &buffer[ind], length - (1 - padd_start)));
		}
	}
	if (extra_c)
		buffer[--ind] = extra_c;
	return (write(1, &buffer[ind], length));
}

/**
 * write_unsgnd - Write an unsigned number to a buffer with formatting
 *
 * Description:
 * This function writes a formatted unsigned number
 * to a buffer, considering various options and parameters.
 *
 * @is_negative: A number indicating if the number is negative.
 * @ind: Index indicating the start of the number in the buffer.
 * @buffer: The array of characters where the number is written.
 * @flags: Formatting flags.
 * @width: The specified width.
 * @precision: Precision specifier.
 * @size: Size specifier.
 *
 * Return:
 * The number of characters written.
 */
int write_unsgnd(int is_negative, int ind,
	char buffer[],
	int flags, int width, int precision, int size)
{
	int length = BUFF_SIZE - ind - 1, v = 0;
	char padd = ' ';

	UNUSED(is_negative);
	UNUSED(size);

	if (precision == 0 && ind == BUFF_SIZE - 2 && buffer[ind] == '0')
		return (0);

	if (precision > 0 && precision < length)
		padd = ' ';

	while (precision > length)
	{
		buffer[--ind] = '0';
		length++;
	}

	if ((flags & F_ZERO) && !(flags & F_MINUS))
		padd = '0';

	if (width > length)
	{
		for (v = 0; v < width - length; v++)
			buffer[v] = padd;
		buffer[v] = '\0';

		if (flags & F_MINUS)
		{
			return (write(1, &buffer[ind], length) + write(1, &buffer[0], v));
		}
		else
		{
			return (write(1, &buffer[0], v) + write(1, &buffer[ind], length));
		}
	}

	return (write(1, &buffer[ind], length));
}

/**
 * write_pointer - Write a memory address to a buffer with formatting
 *
 * Description:
 * This function writes a formatted memory address to a character buffer,
 * taking into account various formatting options.
 *
 * @buffer: An array of characters where the memory address is written.
 * @ind: Index indicating the start of the address in the buffer.
 * @length: The length of the address.
 * @width: Width specifier.
 * @flags: Flags specifier.
 * @padd: A character used for padding.
 * @extra_c: An extra character.
 * @padd_start: Index at which padding should start.
 *
 * Return:
 * The number of characters written.
 */
int write_pointer(char buffer[], int ind, int length,
	int width, int flags, char padd, char extra_c, int padd_start)
{
	int n;

	if (width > length)
	{
		for (n = 3; n < width - length + 3; n++)
			buffer[n] = padd;
		buffer[n] = '\0';
		if (flags & F_MINUS && padd == ' ')
		{
			buffer[--ind] = 'x';
			buffer[--ind] = '0';
			if (extra_c)
				buffer[--ind] = extra_c;
			return (write(1, &buffer[ind], length) + write(1, &buffer[3], n - 3));
		}
		else if (!(flags & F_MINUS) && padd == ' ')
		{
			buffer[--ind] = 'x';
			buffer[--ind] = '0';
			if (extra_c)
				buffer[--ind] = extra_c;
			return (write(1, &buffer[3], n - 3) + write(1, &buffer[ind], length));
		}
		else if (!(flags & F_MINUS) && padd == '0')
		{
			if (extra_c)
				buffer[--padd_start] = extra_c;
			buffer[1] = '0';
			buffer[2] = 'x';
			return (write(1, &buffer[padd_start], n - padd_start) +
				write(1, &buffer[ind], length - (1 - padd_start) - 2));
		}
	}
	buffer[--ind] = 'x';
	buffer[--ind] = '0';
	if (extra_c)
		buffer[--ind] = extra_c;
	return (write(1, &buffer[ind], BUFF_SIZE - ind - 1));
}
