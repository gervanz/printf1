#ifndef MAIN_H
#define MAIN_H
#include <stdarg.h>
#include <stdio.h>
#include <unistd.h>

/**
 * struct print - structure for printing various types
 * @t: type to print
 * @f: function to print
 */
typedef struct print
{
	char *t;
	int (*f)(va_list);
} print_t;

int _printf(const char *format, ...);
int _putchar(char c);
int (*check_format(const char *format))(va_list);
int print_chr(va_list chr);
int print_str(va_list s);
int print_perC(va_list perC);

#endif /* MAIN_H */
