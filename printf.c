#include "main.h"

/**
 * str_len - function that calc/prints the length of a string
 *
 * @s: string Input
 *
 * Return: number of characters printed
 */
int str_len(char* s)
{
	int i = 0;
	if (s == NULL) /* handle NULL string argument */
	{
		str_len("(null)");
		return (6);::Wq:Wq
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
 * __printf - Prints out everything
 *
 * @format: String Input
 *
 * Return: (-1) in case of error and
 * the number of character printed in case of success.
 */
int __printf(const char *format, ...)
{
	va_list args;
	int count = 0;
	if (!format)
		return (-1);

	va_start(args, format);

	while (format)
	{
		if (*format == "%")
		{
			format++;
			switch (*format)
			{
				case 'c':
					char c = va_arg(args, int);
					count += str_len(c);
					break;
				case 's':
					char* str = va_arg(args, char*);
					count += str_len(str);
					break;
				case '%':
					_putchar('%');
					count++;
					break;
				case '\0':
					va_end(args);
					return (-1);
					break;
				default:
					_putchar("%");
					_putchar(*format);
					count += 2;
					break;
			}
		}
		else
		{
			_putchar(*format);
			count++;
		}
		format++;
	}
	va_end(args);
	return (count);
}
