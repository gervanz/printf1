#include "main.h"
#include <stdarg.h>

/**
 * format_check - Check for valid format specifier
 * @format: Format specifier
 * Return: Pointer to valid function if exists
 */

int (*check_format(const char *format))(va_list)
{
	int i = 0;

	print_t p[] = {
		{'c', print_chr},
		{'s', print_str},
		{'%', print_perC},
		{'\0', NULL},
		{NULL, NULL}
	};

	for (; p[i].t != NULL; i++)
	{
		if (*(p[i].t) == *format)
			break;
	}
	
	return (p[i].f);
}
