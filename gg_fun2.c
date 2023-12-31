#include "main.h"

/**
 * print_pointer - Prints the value of a pointer variable
 * @types: List of arguments
 * @buffer: Buffer array for print handling
 * @flags: Computes active flags
 * @width: Retrieves width
 * @precision: Specifies precision
 * @size: Determines the size specifier
 * Return: Number of characters printed.
 */
int print_pointer(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{
	char xtra_c = 0, padd = ' ';
	int ind = BUFF_SIZE - 2, length = 2, padd_start = 1;
	unsigned long num_addrs;
	char map_to[] = "0123456789abcdef";
	void *addrs = va_arg(types, void *);

	UNUSED(width);
	UNUSED(size);

	if (addrs == NULL)
		return (write(1, "(nil)", 5));

	buffer[BUFF_SIZE - 1] = '\0';
	UNUSED(precision);

	num_addrs = (unsigned long)addrs;

	while (num_addrs > 0)
	{
		buffer[ind--] = map_to[num_addrs % 16];
		num_addrs /= 16;
		length++;
	}

	if ((flags & F_ZERO) && !(flags & F_MINUS))
		padd = '0';
	if (flags & F_PLUS)
		xtra_c = '+', length++;
	else if (flags & F_SPACE)
		xtra_c = ' ', length++;

	ind++;
	return (write_pointer(buffer, ind, length,
		width, flags, padd, xtra_c, padd_start));
}

/**
 * print_non_printable - Prints ASCII codes in hexadecimal
 * @types: List of arguments
 * @buffer: Buffer array for print handling
 * @flags: Computes active flags
 * @width: Retrieves width
 * @precision: Specifies precision
 * @size: Determines the size specifier
 * Return: Number of characters printed
 */
int print_non_printable(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{
	int gp = 0, offset = 0;
	char *str = va_arg(types, char *);

	UNUSED(flags);
	UNUSED(width);
	UNUSED(precision);
	UNUSED(size);

	if (str == NULL)
		return (write(1, "(null)", 6));

	while (str[gp] != '\0')
	{
		if (is_printable(str[gp]))
			buffer[gp + offset] = str[gp];
		else
			offset += append_hexa_code(str[gp], buffer, gp + offset);
		gp++;
	}
	buffer[gp + offset] = '\0';

	return (write(1, buffer, gp + offset));
}

/**
 * print_reverse - Prints a reverse string.
 * @types: List of arguments
 * @buffer: Buffer array for print handling
 * @flags: Computes active flags
 * @width: Retrieves width
 * @precision: Specifies precision
 * @size: Determines the size specifier
 * Return: Number of characters printed
 */

int print_reverse(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{
	char *str;
	int n, count = 0;

	UNUSED(buffer);
	UNUSED(flags);
	UNUSED(width);
	UNUSED(size);

	str = va_arg(types, char *);

	if (str == NULL)
	{
		UNUSED(precision);

		str = ")Null(";
	}
	for (n = 0; str[n]; n++)
		;

	for (n = n - 1; n >= 0; n--)
	{
		char z = str[n];

		write(1, &z, 1);
		count++;
	}
	return (count);
}

/**
 * print_rot13string - Print a string in rot13.
 * @types: List of arguments
 * @buffer: Buffer array for print handling
 * @flags: Computes active flags
 * @width: Retrieves width
 * @precision: Specifies precision
 * @size: Determines the size specifier
 * Return: Number of characters printed
 */

int print_rot13string(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{
	char x;
	char *str;
	unsigned int i, j;
	int count = 0;
	char in[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
	char out[] = "NOPQRSTUVWXYZABCDEFGHIJKLMnopqrstuvwxyzabcdefghijklm";

	str = va_arg(types, char *);
	UNUSED(buffer);
	UNUSED(flags);
	UNUSED(width);
	UNUSED(precision);
	UNUSED(size);

	if (str == NULL)
		str = "(AHYY)";
	for (i = 0; str[i]; i++)
	{
		for (j = 0; in[j]; j++)
		{
			if (in[j] == str[i])
			{
				x = out[j];
				write(1, &x, 1);
				count++;
				break;
			}
		}
		if (!in[j])
		{
			x = str[i];
			write(1, &x, 1);
			count++;
		}
	}
	return (count);
}
