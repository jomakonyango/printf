#include <stdarg.h>
#include "main.h"

/**
* _printf - produces output according to a format
* @format: character string composed of zero or more directives
*
* Return: the number of characters printed (excluding the null byte
* used to end output to strings)
*/
int _printf(const char *format, ...)
{
va_list args;
int count = 0;

va_start(args, format);

for (int i = 0; format[i]; i++)
{
if (format[i] != '%')
{
_putchar(format[i]);
count++;
}
else
{
i++;
switch (format[i])
{
case 'c':
_putchar(va_arg(args, int));
count++;
break;
case 's':
char *str = va_arg(args, char *);
for (int j = 0; str[j]; j++)
{
_putchar(str[j]);
count++;
}
break;
case '%':
_putchar('%');
count++;
break;
default:
_putchar('%');
_putchar(format[i]);
count += 2;
break;
}
}
}

va_end(args);

return (count);
}

