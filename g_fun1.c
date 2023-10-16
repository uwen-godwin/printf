#include "main.h"

long int convert_size_unsgnd(unsigned long int num, int size);
int write_unsgnd(int is_negative, int ind, char buffer[],
		int flags, int width, int precision, int size);
/**
 * print_unsigned - Function to prints an unsigned number
 * @types: Arguments
 * @buffer: The buffer array to handle print
 * @flags:  Active flags
 * @width: Parameter to get width
 * @precision: specification
 * @size: specifier
 * Return: Characters to be printed.
 */

int write_unsgnd(int is_negative, int ind, char buffer[],
                int flags, int width, int precision, int size)
{
	int m = BUFF_SIZE - 2;
	unsigned long int num = va_arg(types, unsigned long int);

	num = convert_size_unsgnd(num, size);
	if (num == 0)
		buffer[m--] = '0';
	buffer[BUFF_SIZE - 1] = '\0';
	while (num > 0)
	{
		buffer[m--] = (num % 10) + '0';
		num /= 10;
	}
	m++;
	return (write_unsgnd(0, m, buffer, flags, width, precision, size));
}

/**
 * print_octal - Unsigned number in octal notation
 * @types: Arguments
 * @buffer: Array to handle print
 * @flags:  Active flags to calculate
 * @width: parameter to get width
 * @precision: specification
 * @size: specifier
 * Return: Chars printed
 */

int print_octal(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{

	int m = BUFF_SIZE - 2;
	unsigned long int num = va_arg(types, unsigned long int);
	unsigned long int init_num = num;

	UNUSED(width);
	num = convert_size_unsgnd(num, size);
	if (num == 0)
		buffer[m--] = '0';
	buffer[BUFF_SIZE - 1] = '\0';
	while (num > 0)
	{
		buffer[m--] = (num % 8) + '0';
		num /= 8;
	}
	if (flags & F_HASH && init_num != 0)
		buffer[m--] = '0';
	m++;
	return (write_unsgnd(0, m, buffer, flags, width, precision, size));
}

/**
 * print_hexadecimal - Unsigned number in hexadecimal notation
 * @types: Arguments
 * @buffer: Array to handle print
 * @flags:  Active flags
 * @width: width parameter
 * @precision: specification
 * @size: specifier
 * Return: chars printed
 */
int print_hexadecimal(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{
	return (print_hexa(types, "0123456789abcdef", buffer,
		flags, 'x', width, precision, size));
}

/**
 * print_hexa_upper - Unsigned number in upper hexadecimal notation
 * @types: Arguments
 * @buffer: Array to handle print
 * @flags:  Active flags
 * @width: Width
 * @precision: specification
 * @size: Specifier
 * Return: Chars printed
 */

int print_hexa_upper(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{
	return (print_hexa(types, "0123456789ABCDEF", buffer,
		flags, 'X', width, precision, size));
}

/**
 * print_hexa - Hexadecimal number in lower or upper
 * @types: Arguments
 * @map_to: values to map the number to
 * @buffer: The Buffer array to handle print
 * @flags: Active flags
 * @flag_ch: Calculates active flags
 * @width: Width
 * @precision: Precision specification
 * @size: Size specifier
 * @size: The Size specification
 * Return: Number of chars printed
 */

int print_hexa(va_list types, char map_to[], char buffer[],
	int flags, char flag_ch, int width, int precision, int size)
{
	int m = BUFF_SIZE - 2;
	unsigned long int num = va_arg(types, unsigned long int);
	unsigned long int init_num = num;

	UNUSED(width);

	num = convert_size_unsgnd(num, size);
	if (num == 0)
		buffer[m--] = '0';
	buffer[BUFF_SIZE - 1] = '\0';
	while (num > 0)
	{
		buffer[m--] = map_to[num % 16];
		num /= 16;
	}
	if (flags & F_HASH && init_num != 0)
	{
		buffer[m--] = flag_ch;
		buffer[m--] = '0';
	}
	m++;
	return (write_unsgnd(0, m, buffer, flags, width, precision, size));
}
