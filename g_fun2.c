#include "main.h"

/**
 * print_pointer - value of a pointer variable
 * @types: Arguments
 * @buffer: Array to handle print
 * @flags:  Calculates active flags
 * @width: width
 * @precision: Specification
 * @size: Specifier
 * Return: Chars printed.
 */
int print_pointer(va_list types, char buffer[],
	int flag, int width, int precisn, int size)
{
	char extra_c = 0, padd = ' ';
	int index = BUFF_SIZE - 2, length = 2, padd_start = 1; /* length=2, for '0x' */
	unsigned long num_addrs;
	char map_to[] = "0123456789abcdef";
	void *addrs = va_arg(types, void *);

	UNUSED(width);
	UNUSED(size);

	if (addrs == NULL)
		return (write(1, "(nil)", 5));

	buffer[BUFF_SIZE - 1] = '\0';
	UNUSED(precisn);

	num_addrs = (unsigned long)addrs;

	while (num_addrs > 0)
	{
		buffer[index--] = map_to[num_addrs % 16];
		num_addrs /= 16;
		length++;
	}

	if ((flag & F_ZERO) && !(flag & F_MINUS))
		padd = '0';
	if (flag & F_PLUS)
		extra_c = '+', length++;
	else if (flag & F_SPACE)
		extra_c = ' ', length++;

	index++;

	/*return (write(1, &buffer[i], BUFF_SIZE - i - 1));*/
	return (write_pointer(buffer, index, length,
		width, flag, padd, extra_c, padd_start));
}

/**
 * print_non_printable - ASCII codes in hexa of non printable chars
 * @types: The lista of arguments
 * @buffer: The Buffer array to handle print
 * @flags:  Parameter to calculates active flags
 * @width: Width
 * @precision: Specification precision
 * @size: The size of the specifier
 * Return: Characters printed
 */

int print_non_printable(va_list types, char buffer[],
	int flag, int width, int precisn, int size)
{
	int n = 0, offset = 0;
	char *str = va_arg(types, char *);

	UNUSED(flag);
	UNUSED(width);
	UNUSED(precisn);
	UNUSED(size);

	if (str == NULL)
		return (write(1, "(null)", 6));
	while (str[n] != '\0')
	{
		if (is_printable(str[n]))
			buffer[n + offset] = str[n];
		else
			offset += append_hexa_code(str[n], buffer, n + offset);
		n++;
	}
	buffer[n + offset] = '\0';
	return (write(1, buffer, n + offset));
}

/**
 * print_reverse - Function to prints reverse string.
 * @types: Arguments list
 * @buffer: Handle buffer array
 * @flag:  Calculates active flags
 * @width: Width
 * @precisn: Specification
 * @size: specifier
 * Return: Nums of chars printed
 */

int print_reverse(va_list types, char buffer[],
	int flag, int width, int precisn, int size)
{
	char *str;
	int n, count = 0;

	UNUSED(buffer);
	UNUSED(flag);
	UNUSED(width);
	UNUSED(size);

	str = va_arg(types, char *);

	if (str == NULL)
	{
		UNUSED(precisn);

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
 * print_rot13string - Function to print a string in rot13.
 * @types: Arguments list
 * @buffer: Handle buffer array
 * @flagx:  Active flags to be calculated
 * @width: Width
 * @precisn: Specification
 * @size: Specifier
 * Return: chars printed
 */

int print_rot13string(va_list types, char buffer[],
	int flag, int width, int precisn, int size)
{
	char x;
	char *str;
	unsigned int n, j;
	int count = 0;
	char indx[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
	char out[] = "NOPQRSTUVWXYZABCDEFGHIJKLMnopqrstuvwxyzabcdefghijklm";

	str = va_arg(types, char *);
	UNUSED(buffer);
	UNUSED(flag);
	UNUSED(width);
	UNUSED(precisn);
	UNUSED(size);

	if (str == NULL)
		str = "(AHYY)";
	for (n = 0; str[n]; n++)
	{
		for (j = 0; indx[j]; j++)
		{
			if (indx[j] == str[n])
			{
				x = out[j];
				write(1, &x,1);
				count++;
				break;
			}
		}
		if (!indx[j])
		{
			x = str[n];
			write(1, &x, 1);
			count++;
		}
	}
	return (count);
}
