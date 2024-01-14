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
