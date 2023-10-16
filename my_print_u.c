#include "main.h"
/**
 *print_u - print unasigned char
 * @args: printed numbers
 * Return: number length
 **/

int print_u(va_list args)
{
	char *fstr;
	int u;

	fstr = itac(va_arg(args, unsigned int), 10);

	u = put_string((fstr != NULL) ? fstr : "NULL");

	return (u);
}

/**
 * print_o - print o function
 * @args: printed function
 * Return: number lebgth
 **/

int print_o(va_list args)
{
	char *fstr;
	int u;

	fstr = itac(va_arg(args, unsigned int), 8);

	u = put_string((fstr != NULL) ? fstr : "NULL");

	return (u);
}

/**
 * print_x- Print a number in hexadecimal format
 * @args: Number to print
 * Return: Length of the number
 **/

int print_x(va_list args)
{
	char *fstr;
	int u;

	fstr = itac(va_arg(args, unsigned int), 16);

	u = put_string((fstr != NULL) ? fstr : "NULL");

	return (u);
}

/**
 * print_X - Print a number in hexadecimal format
 * @args: Number to print
 * Return: Length of the number
 **/

int print_X(va_list args)
{
	char *fstr;
	int u;

	fstr = itac(va_arg(args, unsigned int), 16);
	fstr = stou(fstr);

	u = put_string((fstr != NULL) ? fstr : "NULL");

	return (u);
}
