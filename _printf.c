#include "main.h"

/**
 * print_char - prints a character and returns 1
 *
 * @c: the character to be printed
 *
 * Return: 1
 */
int print_char(char c)
{
	_putchar(c);
	return (1);
}

/**
 * print_str - prints a string and returns its length
 *
 * @s: the string to be printed
 *
 * Return: the length of the string
 */
int print_str(char *s)
{
	int l = 0;

	if (s == NULL)
		s = "(null)";
	while (*s)
		l += print_char(*s++);
	return (l);
}

/**
 * _printf - Prints out everything
 *
 * @format: String Input
 *
 * Return: (-1) in case of error
 */
int _printf(const char *format, ...)
{
	va_list args;
	int count = 0;

	if (!format || (format[0] == '%' && !format[1]))
		return (-1);
	va_start(args, format);
	while (*format)
	{
		if (*format == '%')
		{
			format++;
			if (*format == 'c')
				count += print_char(va_arg(args, int));
			else if (*format == 's')
				count += print_str(va_arg(args, char *));
			else if (*format == '%')
				count += print_char('%');
			else
			{
				count += print_char('%');
				if (*format)
					count += print_char(*format);
			}
			format++;
		}
		else
		{
			count += print_char(*format++);
		}
	}
	va_end(args);
	return (count);
}
