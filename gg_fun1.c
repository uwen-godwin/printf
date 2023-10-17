#include "main.h"

/**
 * print_unsigned - Display an unsigned number
 * @types: A list of arguments
 * @buffer: An array used for printing
 * @flags: Active flag calculation
 * @width: Width specification
 * @precision: Precision setting
 * @size: Size determination
 * Return: The count of printed characters.
 */
int print_unsigned(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{
	int jl = BUFF_SIZE - 2;
	unsigned long int num = va_arg(types, unsigned long int);

	num = convert_size_unsgnd(num, size);

	if (num == 0)
		buffer[jl--] = '0';
	buffer[BUFF_SIZE - 1] = '\0';

	while (num > 0)
	{
		buffer[jl--] = (num % 10) + '0';
		num /= 10;
	}

	jl++;

	return (write_unsgnd(0, jl, buffer, flags, width, precision, size));
}

/**
 * print_octal - Outputs an unsigned number in octal format
 * @types: A list of arguments
 * @buffer: An array for printing management
 * @flags: Computes active flags
 * @width: Retrieves width
 * @precision: Specifies precision
 * @size: Determines size
 * Return: The count of printed characters
 */
int print_octal(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{

	int jl = BUFF_SIZE - 2;
	unsigned long int num = va_arg(types, unsigned long int);
	unsigned long int init_num = num;

	UNUSED(width);

	num = convert_size_unsgnd(num, size);

	if (num == 0)
		buffer[jl--] = '0';
	buffer[BUFF_SIZE - 1] = '\0';

	while (num > 0)
	{
		buffer[jl--] = (num % 8) + '0';
		num /= 8;
	}
	if (flags & F_HASH && init_num != 0)
		buffer[jl--] = '0';

	jl++;
	return (write_unsgnd(0, jl, buffer, flags, width, precision, size));
}

/*
 * print_hexadecimal - Outputs an unsigned number in hexadecimal format
 * @types: A list of arguments
 * @buffer: An array for printing management
 * @flags: Computes active flags
 * @width: Retrieves width
 * @precision: Specifies precision
 * @size: Determines size
 * Return: The count of printed characters
 */

int print_hexadecimal(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{
	return (print_hexa(types, "0123456789abcdef", buffer,
		flags, 'x', width, precision, size));
}

/**
 * print_hexa_upper - Outputs an unsigned number
 * in uppercase hexadecimal format
 * @types: List of arguments
 * @buffer: Buffer array for printing management
 * @flags: Computes active flags
 * @width: Retrieves width
 * @precision: Specifies precision
 * @size: Determines size
 * Return: The count of printed characters
 */
int print_hexa_upper(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{
	return (print_hexa(types, "0123456789ABCDEF", buffer,
		flags, 'X', width, precision, size));
}

/**
 * print_hexa - Outputs a hexadecimal number in lowercase or uppercase format
 * @types: List of arguments
 * @map_to: Array of values for mapping the number
 * @buffer: Buffer array for print handling
 * @flags: Computes active flags
 * @flag_ch: Calculates active flags
 * @width: Retrieves width
 * @precision: Specifies precision
 * @size: Determines the size specifier
 * Return: The count of printed characters
 */
int print_hexa(va_list types, char map_to[], char buffer[],
	int flags, char flag_ch, int width, int precision, int size)
{
	int jl = BUFF_SIZE - 2;
	unsigned long int num = va_arg(types, unsigned long int);
	unsigned long int init_num = num;

	UNUSED(width);

	num = convert_size_unsgnd(num, size);

	if (num == 0)
		buffer[jl--] = '0';

	buffer[BUFF_SIZE - 1] = '\0';

	while (num > 0)
	{
		buffer[jl--] = map_to[num % 16];
		num /= 16;
	}

	if (flags & F_HASH && init_num != 0)
	{
		buffer[jl--] = flag_ch;
		buffer[jl--] = '0';
	}

	jl++;

	return (write_unsgnd(0, jl, buffer, flags, width, precision, size));
}
