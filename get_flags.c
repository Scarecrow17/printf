#include "main.h"

/**
 * get_flags - Calculate active flags
 * @format: Formatted string to print arguments in
 * @i: takes parameter
 * Return: Flags
 */
int get_flags(const char *format, int *i)
{
	/* - + 0 # ' ' */
	/* 1 2 4 8  16 */
	int p, curr_i;
	int flag = 0;
	const char FLAGS_CH[] = {'-', '+', '0', '#', ' ', '\0'};
	const int FLAGS_ARR[] = {F_MINUS, F_PLUS, F_ZERO, F_HASH, F_SPACE, 0};

	for (curr_i = *i + 1; format[curr_i] != '\0'; curr_i++)
	{
		for (p = 0; FLAGS_CH[p] != '\0'; p++)
			if (format[curr_i] == FLAGS_CH[p])
			{
				flag |= FLAGS_ARR[p];
				break;
			}

		if (FLAGS_CH[p] == 0)
			break;
	}

	*i = curr_i - 1;

	return (flag);
}
