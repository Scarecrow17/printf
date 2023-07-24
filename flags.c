#include "main.h"

/**
 * get_flags - active flags calculator
 * @format: Formatted string for printing arguments
 * @i: contains parameter
 * Return: The flags
 */
int get_flags(const char *format, int *i)
{
	/* - + 0 # ' ' */
	/* 1 2 4 8  16 */
	int q, curr_p;
	int flag = 0;
	const char FLAGS_CH[] = {'-', '+', '0', '#', ' ', '\0'};
	const int FLAGS_ARRAY[] = {F_MINUS, F_PLUS, F_ZERO, F_HASH, F_SPACE, 0};

	for (curr_p = *i + 1; format[curr_p] != '\0'; curr_p++)
	{
		for (q = 0; FLAGS_CH[q] != '\0'; q++)
			if (format[curr_p] == FLAGS_CH[q])
			{
				flag |= FLAGS_ARRAY[q];
				break;
			}

		if (FLAGS_CH[q] == 0)
			break;
	}

	*i = curr_p - 1;

	return (flag);
}

