#include "main.h"

/**
 * _printf - Custom printf function.
 * @format: Format string with specifiers (%c, %s, ,%).
 *
 * Return: Number of characters written to stdout, or -1 on error.
 */

int _printf(const char *format, ...)
{
	int printed_chars = 0;
	va_list arg_list;

	if (format == NULL)
		return (-1);
	va_start(arg_list, format);
	while (*format)
	{
		if (*format != '%')
			write(1, format, 1);
			printed_chars++;
		else
			format++;
			if (format == '\0')
				break;
			if (*format == '%')
				write(1, format, 1);
			printed_chars++;
			else if (*format == 'c')
				char c = va_arg(arg_list, int);

				write(1, &c, 1);
				printed_chars++;
			else if (*format == 's')
				char *str = va_arg(arg_list, char*);
				int str_len = 0;

				while (str[str_len] != '\0')
					str_len++;
				write(1, str, str_len);
				printed_chars += str_len;
		format++;
	}
	va_end(arg_list);
	return (printed_chars);
}
