#include "main.h"

/************************* WRITE HANDLE *************************/
/**
<<<<<<< HEAD
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
=======
 * handle_write_char - Prints a string
 * @c: char types.
 * @buffer: Buffer array to handle print
 * @flags:  Calculates active flags.
 * @width: get width.
 * @precision: precision specifier
 * @size: Size specifier
 *
 * Return: Number of chars printed.
 */
int handle_write_char(char c, char buffer[],
	int flags, int width, int precision, int size)
{ /* char is stored at left and paddind at buffer's right */
	int i = 0;
>>>>>>> 30e7fc5022331624cd6840609c678b0dd53880fa
	char padd = ' ';

	UNUSED(precision);
	UNUSED(size);

	if (flags & F_ZERO)
		padd = '0';

<<<<<<< HEAD
	buffer[p++] = c;
	buffer[p] = '\0';
=======
	buffer[i++] = c;
	buffer[i] = '\0';
>>>>>>> 30e7fc5022331624cd6840609c678b0dd53880fa

	if (width > 1)
	{
		buffer[BUFF_SIZE - 1] = '\0';
<<<<<<< HEAD
		for (p = 0; p < width - 1; p++)
			buffer[BUFF_SIZE - p - 2] = padd;

		if (flags & F_MINUS)
			return (write(1, &buffer[0], 1) +
					write(1, &buffer[BUFF_SIZE - p - 1], width - 1));
		else
			return (write(1, &buffer[BUFF_SIZE - p - 1], width - 1) +
=======
		for (i = 0; i < width - 1; i++)
			buffer[BUFF_SIZE - i - 2] = padd;

		if (flags & F_MINUS)
			return (write(1, &buffer[0], 1) +
					write(1, &buffer[BUFF_SIZE - i - 1], width - 1));
		else
			return (write(1, &buffer[BUFF_SIZE - i - 1], width - 1) +
>>>>>>> 30e7fc5022331624cd6840609c678b0dd53880fa
					write(1, &buffer[0], 1));
	}

	return (write(1, &buffer[0], 1));
}

/************************* WRITE NUMBER *************************/
/**
<<<<<<< HEAD
 * write_number - Prints string
 * @is_negative: argument list a
 * @ind: types of characters
 * @buffer: Buffer array handling print
 * @flags: active flags calculator
 * @width: width
 * @precision: specifies precision
 * @size: specifies Size
 * Return: characters printed counter
=======
 * write_number - Prints a string
 * @is_negative: Lista of arguments
 * @ind: char types.
 * @buffer: Buffer array to handle print
 * @flags:  Calculates active flags
 * @width: get width.
 * @precision: precision specifier
 * @size: Size specifier
 *
 * Return: Number of chars printed.
>>>>>>> 30e7fc5022331624cd6840609c678b0dd53880fa
 */
int write_number(int is_negative, int ind, char buffer[],
	int flags, int width, int precision, int size)
{
<<<<<<< HEAD
	int len = BUFF_SIZE - ind - 1;
	char padd = ' ', xtra_ch = 0;
=======
	int length = BUFF_SIZE - ind - 1;
	char padd = ' ', extra_ch = 0;
>>>>>>> 30e7fc5022331624cd6840609c678b0dd53880fa

	UNUSED(size);

	if ((flags & F_ZERO) && !(flags & F_MINUS))
		padd = '0';
	if (is_negative)
<<<<<<< HEAD
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
=======
		extra_ch = '-';
	else if (flags & F_PLUS)
		extra_ch = '+';
	else if (flags & F_SPACE)
		extra_ch = ' ';

	return (write_num(ind, buffer, flags, width, precision,
		length, padd, extra_ch));
}

/**
 * write_num - Write a number using a bufffer
 * @ind: Index at which the number starts on the buffer
 * @buffer: Buffer
 * @flags: Flags
 * @width: width
 * @prec: Precision specifier
 * @length: Number length
 * @padd: Pading char
 * @extra_c: Extra char
 *
 * Return: Number of printed chars.
>>>>>>> 30e7fc5022331624cd6840609c678b0dd53880fa
 */
int write_num(int ind, char buffer[],
	int flags, int width, int prec,
	int length, char padd, char extra_c)
{
<<<<<<< HEAD
	int p, padd_start = 1;
=======
	int i, padd_start = 1;
>>>>>>> 30e7fc5022331624cd6840609c678b0dd53880fa

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
<<<<<<< HEAD
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
=======
		for (i = 1; i < width - length + 1; i++)
			buffer[i] = padd;
		buffer[i] = '\0';
		if (flags & F_MINUS && padd == ' ')/* Asign extra char to left of buffer */
		{
			if (extra_c)
				buffer[--ind] = extra_c;
			return (write(1, &buffer[ind], length) + write(1, &buffer[1], i - 1));
		}
		else if (!(flags & F_MINUS) && padd == ' ')/* extra char to left of buff */
		{
			if (extra_c)
				buffer[--ind] = extra_c;
			return (write(1, &buffer[1], i - 1) + write(1, &buffer[ind], length));
		}
		else if (!(flags & F_MINUS) && padd == '0')/* extra char to left of padd */
		{
			if (extra_c)
				buffer[--padd_start] = extra_c;
			return (write(1, &buffer[padd_start], i - padd_start) +
>>>>>>> 30e7fc5022331624cd6840609c678b0dd53880fa
				write(1, &buffer[ind], length - (1 - padd_start)));
		}
	}
	if (extra_c)
		buffer[--ind] = extra_c;
	return (write(1, &buffer[ind], length));
}

/**
<<<<<<< HEAD
 * write_unsgnd - Write unsigned number
 * @is_negative: shows if numb is negative
 * @ind: Index to start numb in buffer
 * @buffer: character array
 * @flags: specifies Flag
 * @width: specifies Width
 * @precision: specifies Precision
 * @size: Specifies size
 * Return: written characters counter
=======
 * write_unsgnd - Writes an unsigned number
 * @is_negative: Number indicating if the num is negative
 * @ind: Index at which the number starts in the buffer
 * @buffer: Array of chars
 * @flags: Flags specifiers
 * @width: Width specifier
 * @precision: Precision specifier
 * @size: Size specifier
 *
 * Return: Number of written chars.
>>>>>>> 30e7fc5022331624cd6840609c678b0dd53880fa
 */
int write_unsgnd(int is_negative, int ind,
	char buffer[],
	int flags, int width, int precision, int size)
{
<<<<<<< HEAD
	/* number is stored buffer's right and begins from  position p */
	int len = BUFF_SIZE - ind - 1, p = 0;
=======
	/* The number is stored at the bufer's right and starts at position i */
	int length = BUFF_SIZE - ind - 1, i = 0;
>>>>>>> 30e7fc5022331624cd6840609c678b0dd53880fa
	char padd = ' ';

	UNUSED(is_negative);
	UNUSED(size);

	if (precision == 0 && ind == BUFF_SIZE - 2 && buffer[ind] == '0')
<<<<<<< HEAD
		return (0); /* printf(".0d", 0)  no character is printed */

	if (precision > 0 && precision < len)
		padd = ' ';

	while (precision > len)
	{
		buffer[--ind] = '0';
		len++;
=======
		return (0); /* printf(".0d", 0)  no char is printed */

	if (precision > 0 && precision < length)
		padd = ' ';

	while (precision > length)
	{
		buffer[--ind] = '0';
		length++;
>>>>>>> 30e7fc5022331624cd6840609c678b0dd53880fa
	}

	if ((flags & F_ZERO) && !(flags & F_MINUS))
		padd = '0';

<<<<<<< HEAD
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
=======
	if (width > length)
	{
		for (i = 0; i < width - length; i++)
			buffer[i] = padd;

		buffer[i] = '\0';

		if (flags & F_MINUS) /* Asign extra char to left of buffer [buffer>padd]*/
		{
			return (write(1, &buffer[ind], length) + write(1, &buffer[0], i));
		}
		else /* Asign extra char to left of padding [padd>buffer]*/
		{
			return (write(1, &buffer[0], i) + write(1, &buffer[ind], length));
		}
	}

	return (write(1, &buffer[ind], length));
}

/**
 * write_pointer - Write a memory address
 * @buffer: Arrays of chars
 * @ind: Index at which the number starts in the buffer
 * @length: Length of number
 * @width: Width specifier
 * @flags: Flags specifier
 * @padd: Char representing the padding
 * @extra_c: Char representing extra char
 * @padd_start: Index at which padding should start
 *
 * Return: Number of written chars.
>>>>>>> 30e7fc5022331624cd6840609c678b0dd53880fa
 */
int write_pointer(char buffer[], int ind, int length,
	int width, int flags, char padd, char extra_c, int padd_start)
{
<<<<<<< HEAD
	int p;

	if (width > length)
	{
		for (p = 3; p < width - length + 3; p++)
			buffer[p] = padd;
		buffer[p] = '\0';
		if (flags & F_MINUS && padd == ' ')/* Asign extra char to the left of buffer */
=======
	int i;

	if (width > length)
	{
		for (i = 3; i < width - length + 3; i++)
			buffer[i] = padd;
		buffer[i] = '\0';
		if (flags & F_MINUS && padd == ' ')/* Asign extra char to left of buffer */
>>>>>>> 30e7fc5022331624cd6840609c678b0dd53880fa
		{
			buffer[--ind] = 'x';
			buffer[--ind] = '0';
			if (extra_c)
				buffer[--ind] = extra_c;
<<<<<<< HEAD
			return (write(1, &buffer[ind], length) + write(1, &buffer[3], p - 3));
		}
		else if (!(flags & F_MINUS) && padd == ' ')/* extra char to the left of buffer */
=======
			return (write(1, &buffer[ind], length) + write(1, &buffer[3], i - 3));
		}
		else if (!(flags & F_MINUS) && padd == ' ')/* extra char to left of buffer */
>>>>>>> 30e7fc5022331624cd6840609c678b0dd53880fa
		{
			buffer[--ind] = 'x';
			buffer[--ind] = '0';
			if (extra_c)
				buffer[--ind] = extra_c;
<<<<<<< HEAD
			return (write(1, &buffer[3], p - 3) + write(1, &buffer[ind], length));
		}
		else if (!(flags & F_MINUS) && padd == '0')/* extra character to the left of padd */
=======
			return (write(1, &buffer[3], i - 3) + write(1, &buffer[ind], length));
		}
		else if (!(flags & F_MINUS) && padd == '0')/* extra char to left of padd */
>>>>>>> 30e7fc5022331624cd6840609c678b0dd53880fa
		{
			if (extra_c)
				buffer[--padd_start] = extra_c;
			buffer[1] = '0';
			buffer[2] = 'x';
<<<<<<< HEAD
			return (write(1, &buffer[padd_start], p - padd_start) +
=======
			return (write(1, &buffer[padd_start], i - padd_start) +
>>>>>>> 30e7fc5022331624cd6840609c678b0dd53880fa
				write(1, &buffer[ind], length - (1 - padd_start) - 2));
		}
	}
	buffer[--ind] = 'x';
	buffer[--ind] = '0';
	if (extra_c)
		buffer[--ind] = extra_c;
	return (write(1, &buffer[ind], BUFF_SIZE - ind - 1));
}
<<<<<<< HEAD

=======
>>>>>>> 30e7fc5022331624cd6840609c678b0dd53880fa
