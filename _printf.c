#include "main.h"
#include <stdarg.h>
#include <unistd.h>
#include <stdio.h> // Added for sprintf

/**
 * _printf - Custom printf function.
 * @format: Format string with specifiers (%c, %s, %d/%i).
 *
 * Return: Number of characters written to stdout, or -1 on error.
 */
int _printf(const char *format, ...)
{
    int printed_chars = 0;
    va_list arg_list;

    if (format == NULL)
        return -1;
    
    va_start(arg_list, format);

    while (*format)
    {
        if (*format != '%')
        {
            write(1, format, 1);
            printed_chars++;
        }
        else
        {
            format++;
            if (*format == '\0')
                break;
            if (*format == '%')
            {
                write(1, "%", 1);
                printed_chars++;
            }
            else if (*format == 'c')
            {
                char c = (char)va_arg(arg_list, int);
                write(1, &c, 1);
                printed_chars++;
            }
            else if (*format == 's')
            {
                char *str = va_arg(arg_list, char*);
                if (str == NULL)
                    str = "(null)";
                while (*str)
                {
                    write(1, str, 1);
                    str++;
                    printed_chars++;
                }
            }
            else if (*format == 'd' || *format == 'i')
            {
                char num_str[12];
                int num_len = sprintf(num_str, "%d", va_arg(arg_list, int));
                write(1, num_str, num_len);
                printed_chars += num_len;
            }
        }
        format++;
    }

    va_end(arg_list);
    return printed_chars;
}
