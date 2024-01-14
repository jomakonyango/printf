#include <stdarg.h>
#include <unistd.h>
#include "main.h"

/* Other function definitions... */

/**
* handle_format - Handles the format specifiers for _printf
* @traverse: Pointer to the current character in the format string
* @args: The list of arguments
* @count: Pointer to the count of characters
*/
void handle_format(const char *traverse, va_list args, int *count)
{
switch (*traverse)
{
case 'c':
print_char(args, count);
break;
case 's':
print_string(args, count);
break;
case '%':
print_percent(count);
break;
case 'b':
print_binary(args, count);
break;
case 'd':
case 'i':
print_int(args, count);
break;
}
}

/**
* _printf - A function that produces output according to a format
* @format: Character string composed of zero or more directives
*
* Return: The number of characters printed (excluding the null byte)
*/
int _printf(const char *format, ...)
{
va_list args;
int count = 0;
const char *traverse;

/* Initialize the argument list */
va_start(args, format);

/* Iterate over the format string */
for (traverse = format; *traverse != '\0'; traverse++)
{
/* Print characters until a '%' or end of string is found */
while (*traverse != '%' && *traverse != '\0')
{
write(1, traverse, 1);
traverse++;
count++;
}

/* If end of string is reached, break the loop */
if (*traverse == '\0')
break;

/* Skip the '%' */
traverse++;

/* Handle the conversion specifier */
handle_format(traverse, args, &count);
}

/* Clean up the argument list */
va_end(args);

/* Return the count of characters printed */
return (count);
}
