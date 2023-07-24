#include "main.h"
/**
 * handle_print - Print argument based on type
 * @fmt: Formatted string for  printing arguments
 * @list: argument list for printing
 * @ind: ind
 * @buffer: Buffer array handling print
 * @flags: active flags calculator
 * @width: width
 * @precision: specifies Precision
 * @size: Specify size
 * Return: 1 
 */
int handle_print(const char *fmt, int *ind, va_list list, char buffer[],
	int flags, int width, int precision, int size)
{
	int p, unknown_len = 0, printd_chars = -1;
	fmt_t fmt_types[] = {
		{'c', print_char}, {'s', print_string}, {'%', print_percent},
		{'i', print_int}, {'d', print_int}, {'b', print_binary},
		{'u', print_unsigned}, {'o', print_octal}, {'x', print_hexadecimal},
		{'X', print_hexa_upper}, {'p', print_pointer}, {'S', print_non_printable},
		{'r', print_reverse}, {'R', print_rot13string}, {'\0', NULL}
	};
	for (p = 0; fmt_types[p].fmt != '\0'; p++)
		if (fmt[*ind] == fmt_types[p].fmt)
			return (fmt_types[p].fn(list, buffer, flags, width, precision, size));

	if (fmt_types[p].fmt == '\0')
	{
		if (fmt[*ind] == '\0')
			return (-1);
		unknown_len += write(1, "%%", 1);
		if (fmt[*ind - 1] == ' ')
			unknown_len += write(1, " ", 1);
		else if (width)
		{
			--(*ind);
			while (fmt[*ind] != ' ' && fmt[*ind] != '%')
				--(*ind);
			if (fmt[*ind] == ' ')
				--(*ind);
			return (1);
		}
		unknown_len += write(1, &fmt[*ind], 1);
		return (unknown_len);
	}
	return (printd_chars);
}

