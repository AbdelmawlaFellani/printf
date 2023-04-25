#include "main.h"

/**
 * str_len - prints/calculates characters of a string
 *
 * @s: string Input
 *
 * Return: number of characters printed or (-1) in case of error
 */
int str_len(char *s)
{
	int i = 0;

	if (s == NULL) /* handle NULL string argument */
	{
		str_len("(null)");
		return (6);
	}
	while (*s != '\0')
	{
		_putchar(*s);
		s++, i++;
	}
	return (i);
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
	char *str, c;
	int count = 0;

	if (!format)
		return (-1);
	va_start(args, format);
	while (*format)
	{
		if (*format == '%')
		{
			format++;
			if (*format == 'c')
				c = va_arg(args, int), count += str_len(&c);
			else if (*format == 's')
			{
				str = va_arg(args, char *);
				count += str_len(str);
			}
			else if (*format == '%')
				_putchar('%'), count++;
			else
			{
				_putchar('%');
				count++;
				if (*format)
					_putchar(*format), count++;
			}
			format++;
		}
		else
		{
			_putchar(*format);
			count++, format++;
		}
	}
	va_end(args);
	return (count);
}
