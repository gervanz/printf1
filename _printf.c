#include "main.h"
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
}
