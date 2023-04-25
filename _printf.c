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
	while (s)
	{
		_putchar(s);
		s++;
		i++;
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
	va_list args, char c, *str;
	int count = 0;

	if (!format)
		return (-1);
	va_start(args, format);
	while (*format)
	{
		if (*format == '%')
		{
			format++;
			switch (*format)
			{
				case 'c':
					c = va_arg(args, int), count += str_len(c);
					break;
				case 's':
					*str = va_arg(args, char*), count += str_len(c);
					break;
				case '%':
					_putchar("%");
					count++;
					break;
				case '\0':
					va_end(args);
					return (-1);
				default:
					_putchar("%"), _putchar(*format);
					count += 2;
					break;
			}
		}
		else
		{
			_putchar(*format), count++;
		}
		format++;
	}
	va_end(args);
	return (count);
}
