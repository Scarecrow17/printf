#include "main.h"
/************************* PRINT UNSIGNED NUMBER *************************/
/**
 * print_unsigned - Print unsigned number
 * @types: argument list a
 * @buffer: Buffer array handling the print
 * @flags: active flags calculator
 * @width: it is the Width
 * @precision: it is the Precision
 * @size: Specifies size
 * Return: characters printed counter
*/
int print_unsigned(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{
	int p = BUFF_SIZE - 2;
	unsigned long int numb = va_arg(types, unsigned long int);

	numb = convert_size_unsgnd(numb, size);

	if (numb == 0)
		buffer[p--] = '0';

	buffer[BUFF_SIZE - 1] = '\0';

	while (numb > 0)
	{
		buffer[p--] = (numb % 10) + '0';
		numb /= 10;
	}

	p++;

	return (write_unsgnd(0, p, buffer, flags, width, precision, size));
}

/************* PRINT UNSIGNED NUMBER IN OCTAL  ****************/
/**
 * print_octal - Print unsigned number, octal notation
 * @types: argument list a
 * @buffer: Buffer array handling the print
 * @flags: active flags calculator
 * @width: it is the Width
 * @precision: it is the Precision
 * @size: Specifies size
 * Return: characters printed counter
*/
int print_octal(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{

	int p = BUFF_SIZE - 2;
	unsigned long int num = va_arg(types, unsigned long int);
	unsigned long int init_num = num;

	UNUSED(width);

	num = convert_size_unsgnd(num, size);

	if (num == 0)
		buffer[p--] = '0';

	buffer[BUFF_SIZE - 1] = '\0';

	while (num > 0)
	{
		buffer[p--] = (num % 8) + '0';
		num /= 8;
	}

	if (flags & F_HASH && init_num != 0)
		buffer[p--] = '0';

	p++;

	return (write_unsgnd(0, p, buffer, flags, width, precision, size));
}

/************** PRINT UNSIGNED NUMBER IN HEXADECIMAL **************/
/**
 * print_hexadecimal - Print unsigned numb,  hexadecimal notation
 * @types: argument list a
 * @buffer: Buffer array handling the print
 * @flags: active flags calculator
 * @width: it is the Width
 * @precision: it is the Precision
 * @size: Specifies size
 * Return: characters printed counter
*/
int print_hexadecimal(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{
	return (print_hexa(types, "0123456789abcdef", buffer,
		flags, 'x', width, precision, size));
}

/************* PRINT UNSIGNED NUMBER IN  UPPER HEXADECIMAL **************/
/**
 * print_hexa_upper - Print unsigned numb,  upper hexadecimal notation
 * @types: argument list a
 * @buffer: Buffer array handling the print
 * @flags: active flags calculator
 * @width: it is the Width
 * @precision: it is the Precision
 * @size: Specifies size
 * Return: characters printed counter
 */
int print_hexa_upper(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{
	return (print_hexa(types, "0123456789ABCDEF", buffer,
		flags, 'X', width, precision, size));
}

/************** PRINT HEXX NUM IN LOWER OR UPPER **************/
/**
 * print_hexa - Print hexadecimal numb, lower or upper
 * @types: argument list a
 * @buffer: Buffer array handling the print
 * @map_to: values array for mapping
 * @flags:  Calculates active flags
 * @flag_ch: Calculates active flags calculator
 * @width: it is the Width
 * @precision: it is the Precision
 * @size: Specifies size
 * Return: characters printed counter
*/
int print_hexa(va_list types, char map_to[], char buffer[],
	int flags, char flag_ch, int width, int precision, int size)
{
	int p = BUFF_SIZE - 2;
	unsigned long int num = va_arg(types, unsigned long int);
	unsigned long int init_num = num;

	UNUSED(width);

	num = convert_size_unsgnd(num, size);

	if (num == 0)
		buffer[p--] = '0';

	buffer[BUFF_SIZE - 1] = '\0';

	while (num > 0)
	{
		buffer[p--] = map_to[num % 16];
		num /= 16;
	}

	if (flags & F_HASH && init_num != 0)
	{
		buffer[p--] = flag_ch;
		buffer[p--] = '0';
	}
	p++;

	return (write_unsgnd(0, p, buffer, flags, width, precision, size));
}

