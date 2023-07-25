#include "main.h"

/**
 * get_precision - Calculate precision for print
 * @format: Formatted string for printing arguments
 * @i: argument list for printing
 * @list: argument list
 * Return: The Precision
*/
int get_precision(const char *format, int *i, va_list list)
{
	int curr_p = *i + 1;
	int prec = -1;

	if (format[curr_p] != '.')
		return (prec);

	prec = 0;

	for (curr_p += 1; format[curr_p] != '\0'; curr_p++)
	{
		if (is_digit(format[curr_p]))
		{
			prec *= 10;
			prec += format[curr_p] - '0';
		}
		else if (format[curr_p] == '*')
		{
			curr_p++;
			prec = va_arg(list, int);
			break;
		}
		else
			break;
	}

	*i = curr_p - 1;

	return (prec);
}
