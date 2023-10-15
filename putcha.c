#include "main.h"

/**
 * putcha - Print a char c to stdout
 * @c: char to print
 * Return: 1 (success)
 */
int putcha(char c)
{
	return (write(1, &c, 1));
}
