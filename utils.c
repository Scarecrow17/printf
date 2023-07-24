#include "main.h"

/**
 * is_printable: check if character can be printed
 * @c: Char to check
 * Return: 1 (c is printable), 0 otherwise
 */
int is_printable(char c)
{
	if (c >= 32 && c < 127)
		return (1);

	return (0);
}

/**
 * append_hexa_code - Appends ascci in hexadecimal code 
 * @buffer: character array
 * @i: Index to begin changes
 * @ascii_code: ASSCI CODE
 * Return: 3 (always)
 */
int append_hexa_code(char ascii_code, char buffer[], int i)
{
	char map_to[] = "0123456789ABCDEF";
	/* hexa format code always 2 digits long */
	if (ascii_code < 0)
		ascii_code *= -1;

	buffer[i++] = '\\';
	buffer[i++] = 'x';

	buffer[i++] = map_to[ascii_code / 16];
	buffer[i] = map_to[ascii_code % 16];

	return (3);
}

/**
 * is_digit - Verify if character is digit
 * @c: Character to be verified
 * Return: 1(c is digit), 0 otherwise
 */
int is_digit(char c)
{
	if (c >= '0' && c <= '9')
		return (1);

	return (0);
}

/**
 * convert_size_number - Cast number to specific size
 * @num: casting number
 * @size: indicate cast type
 * Return: number value casted
 */
long int convert_size_number(long int num, int size)
{
	if (size == S_LONG)
		return (num);
	else if (size == S_SHORT)
		return ((short)num);

	return ((int)num);
}

/**
 * convert_size_unsgnd - Cast number to specific size
 * @num: casting number
 * @size: indicate cast type
 * Return: number value casted
 */
long int convert_size_unsgnd(unsigned long int num, int size)
{
	if (size == S_LONG)
		return (num);
	else if (size == S_SHORT)
		return ((unsigned short)num);

	return ((unsigned int)num);
}

