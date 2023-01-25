#include "main.h"
<<<<<<< HEAD

void print_buffer(char buffer[], int *buff_ind);
/**
 * _printf - printf function
 * @format: format
 * Return: printed chars
 */
int _printf(const char *format, ...)
{
	int i, printed = 0, printed_chars = 0;
	int flags, width, precision, size, buff_ind = 0;
	va_list list;
	char buffer[BUFF_SIZE];

	if (format == NULL)
		return (-1);
	va_start(list, format);

	for (i = 0; format && format[i] != '\0'; i++)
	{
		if (format[i] != '%')
		{
			buffer[buff_ind++] = format[i];
			if (buff_ind == BUFF_SIZE)
				print_buffer(buffer, &buff_ind);
			/* write(1, &format[i], 1);*/
			printed_chars++;
		}
		else
		{
			print_buffer(buffer, &buff_ind);
			flags = get_flags(format, &i);
			width = get_width(format, &i, list);
			precision = get_precision(format, &i, list);
			size = get_size(format, &i);
			++i;
			printed = handle_print(format, &i, list, buffer,
				flags, width, precision, size);
			if (printed == -1)
				return (-1);
			printed_chars += printed;
		}
	}

	print_buffer(buffer, &buff_ind);

	va_end(list);
	return (printed_chars);
}
/**
 * print_buffer - Prints the contents of the buffer if it exist
 * @buffer: array of chars
 * @buff_ind: Index at which to add next char, represents the length.
 */
void print_buffer(char buffer[], int *buff_ind)
{
	if (*buff_ind > 0)
		write(1, &buffer[0], *buff_ind);
	*buff_ind = 0;
=======
#include <stdarg.h>

/**
 * _printf - Function for format handling
 * @format: Format specifier
 * Return: Number of characters printed
 */

int _printf(const char *format, ...)
{
	va_list args;
	unsigned int i = 0, counter = 0;
	int (*f)(va_list);

	if (format == NULL)
		return (-1);

	va_start(args, format);
	while (format &&  format[i])
	{
		if (format[i] != '\0')
		{
			_putchar(format[i]);
			counter++;
			i++;
			continue;
		}
		else
		{
			if (format[i + 1] != '\0')
			{
				_putchar('%');
				counter++;
				i += 2;
				continue;
			}
			else
			{
				f = format_check(&format[i + 1]);
				if (f == NULL)
					return (-1);
				i += 2;
				counter += f(ap);
				continue;
			}
		}
		i++;
	}
	va_end(ap);
	return (counter);
>>>>>>> fc31b8a82ff2faff0d3553e735bc5b7a0012c8cb
}
