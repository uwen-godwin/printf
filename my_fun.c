#include "main.h"

/*
 * my_print_char - a function that print my char
 * @types: the list if arguments to be printed
 * @buffer: the arrays and buffers to be handled
 * @flags:  flags active to be calculated
 * @width: Width
 * @precision: specification
 * @size: byte
 * Return: return a character (success)
 */
int my_print_char(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{
	char c = va_arg(types, int);

	return (handle_write_char(c, buffer, flags, width, precision, size));
}
/**
 * my_print_string - a function that print my char
 * @types: List if arga to be printed
 * @buffer: arrays and buffer to be handled
 * @flags:  flags activuties to the function
 * @width: width
 * @precision: make specufication direct and precise
 * @size: Size
 * Return: Number of chars printed
 */
int my_print_string(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{
	int length = 0, n;
	char *str = va_arg(types, char *);

	UNUSED(buffer);
	UNUSED(flags);
	UNUSED(width);
	UNUSED(precision);
	UNUSED(size);
	if (str == NULL)
	{
		str = "(null)";
		if (precision >= 6)
			str = "      ";
	}

	while (str[length] != '\0')
		length++;

	if (precision >= 0 && precision < length)
		length = precision;

	if (width > length)
	{
		if (flags & F_MINUS)
		{
			write(1, &str[0], length);
			for (n = width - length; n > 0; n--)
				write(1, " ", 1);
			return (width);
		}
		else
		{
			for (i = width - length; n > 0; n--)
				write(1, " ", 1);
			write(1, &str[0], length);
			return (width);
		}
	}

	return (write(1, str, length));
}
/**
 * my_print_percent - Printed character
 * @types: created list
 * @buffer: set of arrays and buffers
 * @flags:  file calculated
 * @width: width
 * @precision: character precision
 * @size: Size of specifier
 * Return: Number of chars printed
 */
int my_print_percent(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{
	UNUSED(types);
	UNUSED(buffer);
	UNUSED(flags);
	UNUSED(width);
	UNUSED(precision);
	UNUSED(size);
	return (write(1, "%%", 1));
}

/*
 * my_print_int - Printed file for me
 * @types: args for me
 * @buffer: my buffer
 * @flags:  flags off character
 * @width: width
 * @precision: specifier and precision
 * @size: specific size of buffer
 * Return: character size
 */
int my_print_int(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{
	int m = BUFF_SIZE - 2;
	int is_negative = 0;
	long int n = va_arg(types, long int);
	unsigned long int num;

	n = convert_size_number(n, size);

	if (n == 0)
		buffer[m--] = '0';

	buffer[BUFF_SIZE - 1] = '\0';
	num = (unsigned long int)n;

	if (n < 0)
	{
		num = (unsigned long int)((-1) * n);
		is_negative = 1;
	}

	while (num > 0)
	{
		buffer[m--] = (num % 10) + '0';
		num /= 10;
	}

	m++;

	return (write_number(is_negative, m, buffer, flags, width, precision, size));
}

/*
 * my_print_binary - unassigned prints
 * @types: printee char
 * @buffer: Buffers and arrays
 * @flags:  acrive cals
 * @width: width.
 * @precision: specifier for precision
 * @size: Sizeed byte
 * Return: Numbers of character
 */
int my_print_binary(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{
	unsigned int x, y, j, sum;
	unsigned int a[32];
	int count;

	UNUSED(buffer);
	UNUSED(flags);
	UNUSED(width);
	UNUSED(precision);
	UNUSED(size);

	x = va_arg(types, unsigned int);
	y = 2147483648; /* (2 ^ 31) */
	a[0] = x / y;
	for (j = 1; j < 32; j++)
	{
		y /= 2;
		a[j] = (x / y) % 2;
	}
	for (j = 0, sum = 0, count = 0; j < 32; j++)
	{
		sum += a[j];
		if (sum || j == 31)
		{
			char z = '0' + a[i];

			write(1, &z, 1);
			count++;
		}
	}
	return (count);
}
