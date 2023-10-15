#include "main.h"

/**
 * putcha - Print a char to standout
 * @c: char to print function
 * Return: 1 (success)
 */
int putcha(char c)
{
	return (write(1, &c, 1));
}
