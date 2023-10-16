#include "main.h"

/**
 * _islower - lowercase calculation
 * @c: checking the character
 * Return: 1  c loeercase (success)
 */
int _islower(int c)
{
	return (c >= 'a' && c <= 'z');
}

/**
 * stou - Change the string to uppercase
 * @f: String
 * Return: String uppercase
 **/
char *stou(char *f)
{
	int x;

	for (x = 0; f[x] != '\0'; x++)
	{
		if (_islower(f[x]))
		{
			f[x] = f[x] - 32;
		}
	}

	return (f);
}
