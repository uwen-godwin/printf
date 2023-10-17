#include "main.h"

/**
 * get_flags - Determine and calculate the active formatting flags.
 *
 * Description:
 * This function examines the format string to identify
 * and calculate the active formatting flags
 * to be applied during printing.
 *
 * @format: The formatted string containing the arguments.
 * @i: A parameter (or list of arguments) that may affect the flags.
 *
 * Return:
 * The calculated formatting flags.
 */
int get_flags(const char *format, int *i)
{
	int m, cal;
	int flag = 0;
	const char FLAGS_CH[] = {'-', '+', '0', '#', ' ', '\0'};
	const int FLAGS_ARR[] = {F_MINUS, F_PLUS, F_ZERO, F_HASH, F_SPACE, 0};

	for (cal = *i + 1; format[cal] != '\0'; cal++)
	{
		for (m = 0; FLAGS_CH[m] != '\0'; m++)
			if (format[cal] == FLAGS_CH[m])
			{
				flag |= FLAGS_ARR[m];
				break;
			}
		if (FLAGS_CH[m] == 0)
			break;
	}
	*i = cal - 1;

	return (flag);
}
