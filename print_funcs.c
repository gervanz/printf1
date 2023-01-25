#include "main.h"

/*------------------------- PRINT CHAR -------------------------*/
/**
 * print_chr - Prints a char
 * @chr: character to print
 * Return: Always 1 (Success)
 */
int print_chr(va_list chr)
{
	char character = (char)va_arg(chr, int);

	_putchar(character);
	return (1);
}

/*------------------------- PRINT STR -------------------------*/
/**
 * print_str - Prints a string
 * @s: String to print
 * Return: i
 */
int print_str(va_list s)
{
	char *str = va_arg(s, char *);
	int i = 0;

	if (str == NULL)
		str = "(null)";
	while (str[i])
		_putchar(str[i++]);
	return (i);
}

/*------------------------- PRINT % -------------------------*/
/**
 * print_str - Prints a %
 * @perC: Percent
 * Return: Percent
 */
int print_perC(va_list perC)
{
	return (write(1, "%%", 1));
}
