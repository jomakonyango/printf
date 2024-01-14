#include <stdarg.h>
#include <unistd.h>
#include "main.h"

/**
* print_binary - Converts an unsigned int to binary and prints it
* @args: List of arguments
* @count: Pointer to the count of characters
*/
void print_binary(va_list args, int *count)
{
unsigned int n = va_arg(args, unsigned int);
char buffer[33];
buffer[32] = '\0';
for (int i = 31; i >= 0; i--)
{
buffer[i] = (n % 2) + '0';
n /= 2;
}
char *str = buffer;
while (*str == '0')
{
str++;
}
while (*str != '\0')
{
write(1, str, 1);
str++;
(*count)++;
}
}

/**
* print_int - Converts an int to a signed decimal integer and prints it
* @args: List of arguments
* @count: Pointer to the count of characters
*/
void print_int(va_list args, int *count)
{
int n = va_arg(args, int);
char buffer[12];  /* Buffer big enough for an int */
sprintf(buffer, "%d", n);
char *str = buffer;
while (*str != '\0')
{
write(1, str, 1);
str++;
(*count)++;
}
}
