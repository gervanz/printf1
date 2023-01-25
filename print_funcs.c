#include "main.h"

/**
 * print_chr - A function that prints a char
 * @chr: character to print
 * Return: Always 1 (Success)
 */
int print_chr(va_list chr)
{
	char character = (char)va_arg(chr, int);

	_putchar(character);
	return (1);
}
