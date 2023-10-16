#ifndef MAIN_H
#define MAIN_H

#include <unistd.h>
#include <stdlib.h>
#include <stdarg.h>

/**
 * struct _form - Typedef struct
 * @typ: Format
 * @fa: The function associated
 **/
typedef struct _form
{
	char typ;
	int (*fa)(va_list);
} form;

int _printf(const char *format, ...);
char *itac(long int num, int base);
int put_char(char c);
int print_char(va_list);
int _strlen(const char *s);
int print_string(va_list);
int put_string(char *str);
int print_integer(va_list);
int handle_format_specifier(const char *, va_list);
int flag_handler(const char *, va_list, int *);
int print_binary(va_list);
int w_buffer(char a);
int can_print(char c);
int print_p(va_list);
int print_S(va_list args);
int print_r(va_list args);
int print_R(va_list args);

/* uoxX */
char *stou(char *f);
int _islower(int c);
int print_u(va_list);
int print_o(va_list);
int print_x(va_list);
int print_X(va_list);

#endif /* MAIN_H */
