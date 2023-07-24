#include "main.h"

/****************** PRINT POINTER ******************/
/**
 * print_pointer - Print pointer var value
 * @types: argument list a
 * @buffer: Buffer array handling the print
 * @flags: active flags calculator
 * @width: it is the Width
 * @precision: it is the Precision
 * @size: Specifies size
 * Return: characters printed counter
 */
int print_pointer(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{
	char xtra_b = 0, padd = ' ';
	int ind = BUFF_SIZE - 2, len = 2, padd_start = 1; /* len=2, for '0x' */
	unsigned long num_address;
	char map_to[] = "0123456789abcdef";
	void *address = va_arg(types, void *);

	UNUSED(width);
	UNUSED(size);

	if (address == NULL)
		return (write(1, "(nil)", 5));

	buffer[BUFF_SIZE - 1] = '\0';
	UNUSED(precision);

	num_address = (unsigned long)address;

	while (num_address > 0)
	{
		buffer[ind--] = map_to[num_address % 16];
		num_address /= 16;
		len++;
	}

	if ((flags & F_ZERO) && !(flags & F_MINUS))
		padd = '0';
	if (flags & F_PLUS)
		xtra_b = '+', len++;
	else if (flags & F_SPACE)
		xtra_b = ' ', len++;

	ind++;

	/*return (write(1, &buffer[p], BUFF_SIZE - p - 1));*/
	return (write_pointer(buffer, ind, len,
		width, flags, padd, xtra_b, padd_start));
}

/************************* PRINT NON PRINTABLE *************************/
/**
 * print_non_printable - Print ascii code, hexa nonprintable characters
 * @types: argument list a
 * @buffer: Buffer array handling the print
 * @flags: active flags calculator
 * @width: it is the Width
 * @precision: it is the Precision
 * @size: Specifies size
 * Return: characters printed counter
 */
int print_non_printable(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{
	int p = 0, offset = 0;
	char *string = va_arg(types, char *);

	UNUSED(flags);
	UNUSED(width);
	UNUSED(precision);
	UNUSED(size);

	if (string == NULL)
		return (write(1, "(null)", 6));

	while (string[p] != '\0')
	{
		if (is_printable(string[p]))
			buffer[p + offset] = string[p];
		else
			offset += append_hexa_code(string[p], buffer, p + offset);

		p++;
	}

	buffer[p + offset] = '\0';

	return (write(1, buffer, p + offset));
}

/************************* PRINT REVERSE *************************/
/**
 * print_reverse - Prit string in reverse
 * @types: argument list a
 * @buffer: Buffer array handling the print
 * @flags: active flags calculator
 * @width: it is the Width
 * @precision: it is the Precision
 * @size: Specifies size
 * Return: characters printed counter
 */

int print_reverse(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{
	char *string;
	int p, counter = 0;

	UNUSED(buffer);
	UNUSED(flags);
	UNUSED(width);
	UNUSED(size);

	string = va_arg(types, char *);

	if (string == NULL)
	{
		UNUSED(precision);

		string = ")Null(";
	}
	for (p = 0; string[p]; p++)
		;

	for (p = p - 1; p >= 0; p--)
	{
		char q = string[p];

		write(1, &q, 1);
		counter++;
	}
	return (counter);
}
/************************* PRINT A STRING IN ROT13 *************************/
/**
 * print_rot13string - Print string in rot13
 * @types: argument list a
 * @buffer: Buffer array handling the print
 * @flags: active flags calculator
 * @width: it is the Width
 * @precision: it is the Precision
 * @size: Specifies size
 * Return: characters printed counter
 */
int print_rot13string(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{
	char q;
	char *string;
	unsigned int p, b;
	int counter = 0;
	char in[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
	char out[] = "NOPQRSTUVWXYZABCDEFGHIJKLMnopqrstuvwxyzabcdefghijklm";

	string = va_arg(types, char *);
	UNUSED(buffer);
	UNUSED(flags);
	UNUSED(width);
	UNUSED(precision);
	UNUSED(size);

	if (string == NULL)
		string = "(AHYY)";
	for (p = 0; string[p]; p++)
	{
		for (b = 0; in[b]; b++)
		{
			if (in[b] == string[p])
			{
				q = out[b];
				write(1, &q, 1);
				counter++;
				break;
			}
		}
		if (!in[b])
		{
			q = string[p];
			write(1, &q, 1);
			counter++;
		}
	}
	return (counter);
}

