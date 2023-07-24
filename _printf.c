#include "main.h"

void print_buffer(char buffer[], int *buff_ind);

/**
 * _printf - func of printf
 * @format: formatting
 * Return: characters that are Printed
 */
int _printf(const char *format, ...)
{
	int p, printd = 0, printd_chars = 0;
	int flag, width, prec, size, buff_ind = 0;
	va_list ls;
	char buffer[BUFF_SIZE];

	if (format == NULL)
		return (-1);

	va_start(ls, format);

	for (p = 0; format && format[p] != '\0'; p++)
	{
		if (format[p] != '%')
		{
			buffer[buff_ind++] = format[p];
			if (buff_ind == BUFF_SIZE)
				print_buffer(buffer, &buff_ind);
			/* write(1, &format[p], 1);*/
			printd_chars++;
		}
		else
		{
			print_buffer(buffer, &buff_ind);
			flag = get_flags(format, &p);
			width = get_width(format, &p, ls);
			prec = get_precision(format, &p, ls);
			size = get_size(format, &p);
			++p;
			printd = handle_print(format, &p, ls, buffer,
				flag, width, prec, size);
			if (printd == -1)
				return (-1);
			printd_chars += printd;
		}
	}

	print_buffer(buffer, &buff_ind);

	va_end(ls);

	return (printd_chars);
}

/**
 * print_buffer - Prints buffer contents if in existance
 * @buffer: character array
 * @buff_ind: Index to add next char, it is length
 */
void print_buffer(char buffer[], int *buff_ind)
{
	if (*buff_ind > 0)
		write(1, &buffer[0], *buff_ind);

	*buff_ind = 0;
}

