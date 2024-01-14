#include <stdarg.h>
#include <unistd.h>
#include "main.h"

/**
 * print_char - Prints a character
 * @args: List of arguments
 * @count: Pointer to the count of characters
 */
void print_char(va_list args, int *count)
{
char c = va_arg(args, int);
write(1, &c, 1);
(*count)++;
}

/**
 * print_string - Prints a string
 * @args: List of arguments
 * @count: Pointer to the count of characters
 */
void print_string(va_list args, int *count)
{
char *str = va_arg(args, char *);
while (*str != '\0')
{
write(1, str, 1);
str++;
(*count)++;
}
}

/**
 * print_percent - Prints a percent symbol
 * @count: Pointer to the count of characters
 */
void print_percent(int *count)
{
write(1, "%", 1);
(*count)++;
}

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
print_char(args, &count);
break;
case 's':
print_string(args, &count);
break;
case '%':
print_percent(&count);
break;
}
}
va_end(args);
return (count);
}
