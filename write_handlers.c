#include "main.h"

/************************* WRITE HANDLE *************************/
/**
 * handle_write_char - Print string
 * @c: types of characters
 * @buffer: Buffer array handling print
 * @flags: active flags calculator
 * @width: width
 * @precision: specifies precision
 * @size: specifies Size
 * Return: characters printed counter
 */
int handle_write_char(char c, char buffer[],
	int flags, int width, int precision, int size)
{ /* character stored at left and padding at buffer right */
	int p = 0;
	char padd = ' ';

	UNUSED(precision);
	UNUSED(size);

	if (flags & F_ZERO)
		padd = '0';

	buffer[p++] = c;
	buffer[p] = '\0';

	if (width > 1)
	{
		buffer[BUFF_SIZE - 1] = '\0';
		for (p = 0; p < width - 1; p++)
			buffer[BUFF_SIZE - p - 2] = padd;

		if (flags & F_MINUS)
			return (write(1, &buffer[0], 1) +
					write(1, &buffer[BUFF_SIZE - p - 1], width - 1));
		else
			return (write(1, &buffer[BUFF_SIZE - p - 1], width - 1) +
					write(1, &buffer[0], 1));
	}

	return (write(1, &buffer[0], 1));
}

/************************* WRITE NUMBER *************************/
/**
 * write_number - Prints string
 * @is_negative: argument list a
 * @ind: types of characters
 * @buffer: Buffer array handling print
 * @flags: active flags calculator
 * @width: width
 * @precision: specifies precision
 * @size: specifies Size
 * Return: characters printed counter
 */
int write_number(int is_negative, int ind, char buffer[],
	int flags, int width, int precision, int size)
{
	int len = BUFF_SIZE - ind - 1;
	char padd = ' ', xtra_ch = 0;

	UNUSED(size);

	if ((flags & F_ZERO) && !(flags & F_MINUS))
		padd = '0';
	if (is_negative)
		xtra_ch = '-';
	else if (flags & F_PLUS)
		xtra_ch = '+';
	else if (flags & F_SPACE)
		xtra_ch = ' ';

	return (write_num(ind, buffer, flags, width, precision,
		len, padd, xtra_ch));
}

/**
 * write_num - Write numb via a bufffer
 * @ind: Index to start numb on buffer
 * @buffer: Buffer
 * @flags: Flag
 * @width: get width
 * @prec: specify Precision
 * @length: length
 * @padd: Pading character for padding
 * @extra_c: xtra char
 * Return: printed characters counter
 */
int write_num(int ind, char buffer[],
	int flags, int width, int prec,
	int length, char padd, char extra_c)
{
	int p, padd_start = 1;

	if (prec == 0 && ind == BUFF_SIZE - 2 && buffer[ind] == '0' && width == 0)
		return (0); /* printf(".0d", 0)  no char is printed */
	if (prec == 0 && ind == BUFF_SIZE - 2 && buffer[ind] == '0')
		buffer[ind] = padd = ' '; /* width is displayed with padding ' ' */
	if (prec > 0 && prec < length)
		padd = ' ';
	while (prec > length)
		buffer[--ind] = '0', length++;
	if (extra_c != 0)
		length++;
	if (width > length)
	{
		for (p = 1; p < width - length + 1; p++)
			buffer[p] = padd;
		buffer[p] = '\0';
		if (flags & F_MINUS && padd == ' ')/* Asign extra character to the left of buffer */
		{
			if (extra_c)
				buffer[--ind] = extra_c;
			return (write(1, &buffer[ind], length) + write(1, &buffer[1], p - 1));
		}
		else if (!(flags & F_MINUS) && padd == ' ')/* extra character to the left of buff */
		{
			if (extra_c)
				buffer[--ind] = extra_c;
			return (write(1, &buffer[1], p - 1) + write(1, &buffer[ind], length));
		}
		else if (!(flags & F_MINUS) && padd == '0')/* extra character to the left of padd */
		{
			if (extra_c)
				buffer[--padd_start] = extra_c;
			return (write(1, &buffer[padd_start], p - padd_start) +
				write(1, &buffer[ind], length - (1 - padd_start)));
		}
	}
	if (extra_c)
		buffer[--ind] = extra_c;
	return (write(1, &buffer[ind], length));
}

/**
 * write_unsgnd - Write unsigned number
 * @is_negative: shows if numb is negative
 * @ind: Index to start numb in buffer
 * @buffer: character array
 * @flags: specifies Flag
 * @width: specifies Width
 * @precision: specifies Precision
 * @size: Specifies size
 * Return: written characters counter
 */
int write_unsgnd(int is_negative, int ind,
	char buffer[],
	int flags, int width, int precision, int size)
{
	/* number is stored buffer's right and begins from  position p */
	int len = BUFF_SIZE - ind - 1, p = 0;
	char padd = ' ';

	UNUSED(is_negative);
	UNUSED(size);

	if (precision == 0 && ind == BUFF_SIZE - 2 && buffer[ind] == '0')
		return (0); /* printf(".0d", 0)  no character is printed */

	if (precision > 0 && precision < len)
		padd = ' ';

	while (precision > len)
	{
		buffer[--ind] = '0';
		len++;
	}

	if ((flags & F_ZERO) && !(flags & F_MINUS))
		padd = '0';

	if (width > len)
	{
		for (p = 0; p < width - len; p++)
			buffer[p] = padd;

		buffer[p] = '\0';

		if (flags & F_MINUS) /* Asign extra character to the left of buffer [buffer>padd]*/
		{
			return (write(1, &buffer[ind], len) + write(1, &buffer[0], p));
		}
		else /* Asign extra character to the left of padding [padd>buffer]*/
		{
			return (write(1, &buffer[0], p) + write(1, &buffer[ind], len));
		}
	}

	return (write(1, &buffer[ind], len));
}

/**
 * write_pointer - Write memory address
 * @buffer: character array
 * @ind: Index to start numb in buffer
 * @length: Length of the numb
 * @width: specifies width
 * @flags: specify flags
 * @padd: Character for padding
 * @extra_c: extra character
 * @padd_start: Index to start padding
 * Return: written characters counter
 */
int write_pointer(char buffer[], int ind, int length,
	int width, int flags, char padd, char extra_c, int padd_start)
{
	int p;

	if (width > length)
	{
		for (p = 3; p < width - length + 3; p++)
			buffer[p] = padd;
		buffer[p] = '\0';
		if (flags & F_MINUS && padd == ' ')/* Asign extra char to the left of buffer */
		{
			buffer[--ind] = 'x';
			buffer[--ind] = '0';
			if (extra_c)
				buffer[--ind] = extra_c;
			return (write(1, &buffer[ind], length) + write(1, &buffer[3], p - 3));
		}
		else if (!(flags & F_MINUS) && padd == ' ')/* extra char to the left of buffer */
		{
			buffer[--ind] = 'x';
			buffer[--ind] = '0';
			if (extra_c)
				buffer[--ind] = extra_c;
			return (write(1, &buffer[3], p - 3) + write(1, &buffer[ind], length));
		}
		else if (!(flags & F_MINUS) && padd == '0')/* extra character to the left of padd */
		{
			if (extra_c)
				buffer[--padd_start] = extra_c;
			buffer[1] = '0';
			buffer[2] = 'x';
			return (write(1, &buffer[padd_start], p - padd_start) +
				write(1, &buffer[ind], length - (1 - padd_start) - 2));
		}
	}
	buffer[--ind] = 'x';
	buffer[--ind] = '0';
	if (extra_c)
		buffer[--ind] = extra_c;
	return (write(1, &buffer[ind], BUFF_SIZE - ind - 1));
}

