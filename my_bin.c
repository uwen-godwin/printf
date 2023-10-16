#include "main.h"

/**
 * print_binary - base printing2
 * @args: argument converted to bases
 * Return: binary length
 **/
int print_binary(va_list args)
{
	char *fstr;
	int m;

	fstr = itac(va_arg(args, unsigned int), 2);

	m = put_string(fstr);

	return (m);
}
