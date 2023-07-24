#include "main.h"

/************************* PRINT CHAR *************************/

/**
 * print_char - Print character
 * @types: argument list a
 * @buffer: Buffer array handling the print
 * @flags: active flags calculator
 * @width: it is the Width
 * @precision: it is the Precision
 * @size: Specifies size
 * Return: characters printed counter
 */
int print_char(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{
	char p = va_arg(types, int);

	return (handle_write_char(p, buffer, flags, width, precision, size));
}
/************************* PRINT A STRING *************************/
/**
 * print_string - Prints a string
 * @types: argument list a
 * @buffer: Buffer array handling the print
 * @flags: active flags calculator
 * @width: it is the Width
 * @precision: it is the Precision
 * @size: Specifies size
 * Return: characters printed counter
 */
int print_string(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{
	int len = 0, p;
	char *string = va_arg(types, char *);

	UNUSED(buffer);
	UNUSED(flags);
	UNUSED(width);
	UNUSED(precision);
	UNUSED(size);
	if (string == NULL)
	{
		string = "(null)";
		if (precision >= 6)
			string = "      ";
	}

	while (string[len] != '\0')
		len++;

	if (precision >= 0 && precision < len)
		len = precision;

	if (width > len)
	{
		if (flags & F_MINUS)
		{
			write(1, &string[0], len);
			for (p = width - len; p > 0; p--)
				write(1, " ", 1);
			return (width);
		}
		else
		{
			for (p = width - len; p > 0; p--)
				write(1, " ", 1);
			write(1, &string[0], len);
			return (width);
		}
	}

	return (write(1, string, len));
}
/************************* PRINT PERCENT SIGN *************************/
/**
 * print_percent - Print percentage sign
 * @types: argument list a
 * @buffer: Buffer array handling the print
 * @flags: active flags calculator
 * @width: it is the Width
 * @precision: it is the Precision
 * @size: Specifies size
 * Return: characters printed counter
 */
int print_percent(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{
	UNUSED(types);
	UNUSED(buffer);
	UNUSED(flags);
	UNUSED(width);
	UNUSED(precision);
	UNUSED(size);
	return (write(1, "%%", 1));
}

/************************* PRINT INT *************************/
/**
 * print_int - Print int
 * @types: argument list a
 * @buffer: Buffer array handling the print
 * @flags: active flags calculator
 * @width: it is the Width
 * @precision: it is the Precision
 * @size: Specifies size
 * Return: characters printed counter
 */
int print_int(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{
	int p = BUFF_SIZE - 2;
	int is_neg = 0;
	long int m = va_arg(types, long int);
	unsigned long int numb;

	m = convert_size_number(m, size);

	if (m == 0)
		buffer[p--] = '0';

	buffer[BUFF_SIZE - 1] = '\0';
	numb = (unsigned long int)m;

	if (m < 0)
	{
		numb = (unsigned long int)((-1) * m);
		is_neg = 1;
	}

	while (numb > 0)
	{
		buffer[p--] = (numb % 10) + '0';
		numb /= 10;
	}

	p++;

	return (write_number(is_neg, p, buffer, flags, width, precision, size));
}

/************************* PRINT BINARY *************************/
/**
 * print_binary - Prints an unsigned number
 * @types: argument list a
 * @buffer: Buffer array handling the print
 * @flags: active flags calculator
 * @width: it is the Width
 * @precision: it is the Precision
 * @size: Specifies size
 * Return: characters printed counter
 */
int print_binary(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{
	unsigned int j, n, p, sum;
	unsigned int b[32];
	int counter;

	UNUSED(buffer);
	UNUSED(flags);
	UNUSED(width);
	UNUSED(precision);
	UNUSED(size);

	j = va_arg(types, unsigned int);
	n = 2147483648; /* (2 ^ 31) */
	b[0] = j / n;
	for (p = 1; p < 32; p++)
	{
		n /= 2;
		b[j] = (j / n) % 2;
	}
	for (p = 0, sum = 0, counter = 0; p < 32; p++)
	{
		sum += b[p];
		if (sum || p == 31)
		{
			char q = '0' + b[p];

			write(1, &q, 1);
			counter++;
		}
	}
	return (counter);
}

