#include "main.h"

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
			write(1, format++, 1);
		else
		{
			format++;
			if (*format == '\0')
				break;
			if (*format == '%')
				write(1, format++, 1);
			else if (*format == 'c')
				printed_chars++, write(1, &va_arg(arg_list, int), 1);
			else if (*format == 's')
			{
				char *str = va_arg(arg_list, char *);
				for (; *str; str++, printed_chars++)
					write(1, str, 1);
			}
			else if (*format == 'd' || *format == 'i')
			{
				char num_str[12];
				int num_len = sprintf(num_str, "%d", va_arg(arg_list, int));
			       	printed_chars += num_len;
				write(1, num_str, num_len);
			}
		}
		format++;
	}
	va_end(arg_list);
       	return printed_chars;
}

