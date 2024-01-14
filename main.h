#ifndef MAIN_H
#define MAIN_H

#include <stdarg.h>

/* Function Prototypes */
int _printf(const char *format, ...);
void print_char(va_list args, int *count);
void print_string(va_list args, int *count);
void print_percent(int *count);

#endif /* MAIN_H */
