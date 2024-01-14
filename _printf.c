#include <stdarg.h>
#include <unistd.h>
#include "main.h"

/**
 * _printf - a function that produces output according to a format
 * @format: character string composed of zero or more directives
 *
 * Return: the number of characters printed (excluding the null byte)
 */
int _printf(const char *format, ...)
{
    va_list args;
    int count = 0;
    const char *traverse;
    char *str;
    char c;

    va_start(args, format);
    for (traverse = format; *traverse != '\0'; traverse++)
    {
        while (*traverse != '%' && *traverse != '\0')
        {
            write(1, traverse, 1);
            traverse++;
            count++;
        }
        if (*traverse == '\0')
            break;
        traverse++;  /* skip the '%' */
        switch (*traverse)
        {
            case 'c':
            {
                c = va_arg(args, int);
                write(1, &c, 1);
                count++;
                break;
            }
            case 's':
            {
                str = va_arg(args, char *);
                while (*str != '\0')
                {
                    write(1, str, 1);
                    str++;
                    count++;
                }
                break;
            }
            case '%':
                write(1, traverse, 1);
                count++;
                break;
        }
    }
    va_end(args);
    return (count);
}
