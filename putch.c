#include "main.h"

/**
 * _putchar - Fucntion to writes the character c to stdout
 * @c: Character to print
 *
 * Return: 1 (success)
 * On error, -1
 */
int _putchar(char c)
{
	return (write(1, &c, 1));
}
