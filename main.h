#ifndef MAIN_H
#define MAIN_H
#include <stdio.h>
#include <stdarg.h>
#include <unistd.h>

#define UNUSED(x) (void)(x)
#define BUFF_SIZE 1024

/* THE FLAGS SECTIONS*/
#define F_MINUS 1
#define F_PLUS 2
#define F_ZERO 4
#define F_HASH 8
#define F_SPACE 16

/* THE SIZES */
#define S_LONG 2
#define S_SHORT 1

/**
 * struct fmt - Function that Struct op
 *
 * @fmt: format.specifiers
 * @fn: function associated.
 */

struct fmt
{
	char fmt;
	int (*fn)(va_list, char[], int, int, int, int);
};

/**
 * typedef struct fmt fmt_t - The Struct op
 *
 * @fmt: format.specifiers
 * @fm_t: function associated.
 */

typedef struct fmt fmt_t;
int putcha(char c);
int _printf(const char *format, ...);
int handle_print(const char *fmt, int *i,
va_list list, char buffer[], int flags, int width, int precision, int size);

/* A Funtions that print chars and strings */
int print_char(va_list types, char buffer[],
	int flags, int width, int precision, int size);
int print_string(va_list types, char buffer[],
	int flags, int width, int precision, int size);
int print_percent(va_list types, char buffer[],
	int flags, int width, int precision, int size);

/* A Functions that print numbers */
int print_int(va_list types, char buffer[], int flags, int width,
		int precision, int size);
int print_binary(va_list types, char buffer[], int flags, int width,
		int precision, int size);
int print_unsigned(va_list types, char buffer[], int flags,
		int width, int precision, int size);
int print_octal(va_list types, char buffer[],
	int flags, int width, int precision, int size);
int print_hexadecimal(va_list types, char buffer[],
	int flags, int width, int precision, int size);
int print_hexa_upper(va_list types, char buffer[],
	int flags, int width, int precision, int size);

int print_hexa(va_list types, char map_to[],
char buffer[], int flags, char flag_ch, int width, int precision, int size);

/* A function that print non printable characters */
int print_non_printable(va_list types, char buffer[],
	int flags, int width, int precision, int size);

/* A funcion that print memory address */
int print_pointer(va_list types, char buffer[],
	int flags, int width, int precision, int size);

/* A funciotns that handle other specifiers */
int get_flags(const char *format, int *n);
int get_width(const char *format, int *n, va_list list);
int my_get_precision(const char *format, int *n, va_list list);
int get_size(const char *format, int *n);

/* A function that print string in reverse*/
int print_reverse(va_list types, char buffer[],
	int flags, int width, int precision, int size);

/* A function that print a string in rot 13*/
int print_rot13string(va_list types, char buffer[],
	int flags, int width, int precision, int size);

/* The width handler */
int handle_write_char(char c, char buffer[],
	int flags, int width, int precision, int size);
int write_number(int is_positive, int ind, char buffer[],
	int flags, int width, int precision, int size);
int write_num(int ind, char bff[], int flags, int width, int precision,
	int length, char padd, char extra_c);
int write_pointer(char buffer[], int ind, int length,
	int width, int flags, char padd, char extra_c, int padd_start);

int write_unsgnd(int is_negative, int ind,
char buffer[],
	int flags, int width, int precision, int size);

/****************** THE UTILS ******************/
int is_printable(char);
int append_hexa_code(char, char[], int);
int is_digit(char);

long int convert_size_number(long int num, int size);
long int convert_size_unsgnd(unsigned long int num, int size);

#endif /* MAIN_H */
