#include "main.h"
#include <stdio.h>

/* Helper function to convert an unsigned int to binary and print it */
void print_binary(unsigned int n)
{
if (n > 1)
print_binary(n / 2);
putchar((n % 2) + '0');
}
/* Helper function to handle %c, %s, and %d specifiers */
int handle_specifier(int c, va_list args)
{
char *s;
int count = 0;

switch (c)
{
case 'c':
c = va_arg(args, int);
putchar(c);
count++;
break;
case 's':
s = va_arg(args, char *);
while (*s)
{
putchar(*s++);
count++;
}
break;
case 'd':
case 'i':
{
int num = va_arg(args, int);
char str[12]; /* Buffer big enough for an int. */
sprintf(str, "%d", num);
for (s = str; *s; s++, count++)
putchar(*s);
break;
}
}

return count;
}

/**
* _printf - Produces output according to a format.
* @format: A string containing the desired format.
*
* Return: The number of characters printed.
*/
int _printf(const char *format, ...)
{
va_list args;
int count = 0;
int i;

va_start(args, format);
for (i = 0; format[i] != '\0'; i++)
{
if (format[i] != '%')
{
putchar(format[i]);
count++;
}
else
{
i++;
count += handle_specifier(format[i], args);
}
}
va_end(args);

return (count);
}
