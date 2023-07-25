#include "main.h"

/**
 * get_size - Calculate size to save argument
 * @format: Formatted string for printing arguments
 * @i: argument list to be printed
 * Return: The size
*/
int get_size(const char *format, int *i)
{
	int curr_p = *i + 1;
	int size = 0;

	if (format[curr_p] == 'l')
		size = S_LONG;
	else if (format[curr_p] == 'h')
		size = S_SHORT;

	if (size == 0)
		*i = curr_p - 1;
	else
		*i = curr_p;

	return (size);
}
