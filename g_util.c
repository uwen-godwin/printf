#include "main.h"

/**
 * is_printable - Function to evaluate if a char is printable
 * @c: The valuated character
 *
 * Return: 1 otherwise 0, if c is printed
 */
int is_printable(char c)
{
	if (c >= 32 && c < 127)
		return (1);

	return (0);
}

/**
 * append_hexa_code - Function to append ascci in hexadecimal code to buffer
 * @buffer: Character array
 * @n: Appending index
 * @ascii_code: The ASSCI CODE.
 * Return: 3
 */
int append_hexa_code(char ascii_code, char buffer[], int n)
{
	char map_to[] = "0123456789ABCDEF";

	if (ascii_code < 0)
		ascii_code *= -1;

	buffer[n++] = '\\';
	buffer[n++] = 'x';

	buffer[n++] = map_to[ascii_code / 16];
	buffer[n] = map_to[ascii_code % 16];

	return (3);
}

/**
 * is_digit - Function to verifies if a char is a digit
 * @c: The evaluated character
 * Return: 1 otherwise 0, if c is a digit.
 */
int is_digit(char c)
{
	if (c >= '0' && c <= '9')
		return (1);

	return (0);
}

/**
 * convert_size_number - Function to Casts a number to the specified size
 * @num: Casted number
 * @size: Size of number to be casted.
 * Return: Value casted
 */
long int convert_size_number(long int num, int size)
{
	if (size == S_LONG)
		return (num);
	else if (size == S_SHORT)
		return ((short)num);

	return ((int)num);
}

/**
 * convert_size_unsgnd - Function to specify the size to be casted
 * @num: The number to be casted
 * @size: Indicating the type to be casted
 * Return: Value of num casted
 */

long int convert_size_unsgnd(unsigned long int num, int size)
{
	if (size == S_LONG)
		return (num);
	else if (size == S_SHORT)
		return ((unsigned short)num);

	return ((unsigned int)num);
}
