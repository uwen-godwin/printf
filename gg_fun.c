#include "main.h"

/**
 * print_char - Print a single character.
 *
 * Description:
 * This function is used to print a character.
 *
 * @types: List of arguments
 * @buffer: Buffer array for handling the print
 * @flags: Calculate active flags
 * @width: Width specification
 * @precision: Precision specification
 * @size: Size specifier
 *
 * Return:
 * The number of characters printed.
 */
int print_char(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{
	char c = va_arg(types, int);

	return (handle_write_char(c, buffer, flags, width, precision, size));
}

/**
 * print_string - Print a string.
 *
 * Description:
 * This function is used to print a string of characters.
 *
 * @types: List of arguments
 * @buffer: Buffer array for handling the print
 * @flags: Calculate active flags
 * @width: Width specification
 * @precision: Precision specification
 * @size: Size specifier
 *
 * Return:
 * The number of characters printed.
 */
int print_string(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{
	int lem = 0, i;
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
	while (str[lem] != '\0')
		lem++;
	if (precision >= 0 && precision < lem)
		lem = precision;
	if (width > lem)
	{
		if (flags & F_MINUS)
		{
			write(1, &str[0], lem);
			for (i = width - lem; i > 0; i--)
				write(1, " ", 1);
			return (width);
		}
		else
		{
			for (i = width - lem; i > 0; i--)
				write(1, " ", 1);
			write(1, &str[0], lem);
			return (width);
		}
	}
	return (write(1, str, lem));
}
/**
 * print_percent - Print a percent sign.
 *
 * Description:
 * This function is used to print a percent sign ("%").
 *
 * @types: List of arguments
 * @buffer: Buffer array for handling the print
 * @flags: Calculate active flags
 * @width: Width specification
 * @precision: Precision specification
 * @size: Size specifier
 *
 * Return:
 * The number of characters printed.
 */
int print_percent(va_list types, char buffer[],
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
/**
 * print_int - Print an integer.
 *
 * Description:
 * This function is used to print an integer.
 *
 * @types: List of arguments
 * @buffer: Buffer array for handling the print
 * @flags: Calculate active flags
 * @width: Width specification
 * @precision: Precision specification
 * @size: Size specifier
 *
 * Return:
 * The number of characters printed.
 */

int print_int(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{
	int z = BUFF_SIZE - 2;
	int is_negative = 0;
	long int n = va_arg(types, long int);
	unsigned long int num;

	n = convert_size_number(n, size);

	if (n == 0)
		buffer[z--] = '0';
	buffer[BUFF_SIZE - 1] = '\0';
	num = (unsigned long int)n;
	if (n < 0)
	{
		num = (unsigned long int)((-1) * n);
		is_negative = 1;
	}
	while (num > 0)
	{
		buffer[z--] = (num % 10) + '0';
		num /= 10;
	}
	z++;
	return (write_number(is_negative, z, buffer,
				flags, width, precision, size));
}

/**
 * print_binary - Output an unsigned number in binary format.
 *
 * Description:
 * This function is responsible for printing an
 * unsigned number in binary format.
 *
 * @types: Argument list
 * @buffer: Buffer array for printing
 * @flags: Active flags calculation
 * @width: Width specification
 * @precision: Precision specification
 * @size: Size specifier
 *
 * Return:
 * The count of characters printed.
 */
int print_binary(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{
	unsigned int num, m, j, sum;
	unsigned int a[32];
	int count;

	UNUSED(buffer);
	UNUSED(flags);
	UNUSED(width);
	UNUSED(precision);
	UNUSED(size);

	num = va_arg(types, unsigned int);
	m = 2147483648; /* (2 ^ 31) */
	a[0] = num / m;
	for (j = 1; j < 32; j++)
	{
		m /= 2;
		a[j] = (num / m) % 2;
	}
	for (j = 0, sum = 0, count = 0; j < 32; j++)
	{
		sum += a[j];
		if (sum || j == 31)
		{
			char z = '0' + a[j];

			write(1, &z, 1);
			count++;
		}
	}
	return (count);
}
