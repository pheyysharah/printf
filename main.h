#ifndef MAIN_H
#define MAIN_H
#include <unistd.h>
#include <stdarg.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define UNUSED(x) (void)(x)
#define BUFF_SIZE 1024

#define F_MINUS 1
#define F_PLUS 2
#define F_ZERO 4
#define F_HASH 8
#define F_SPACE 16

#define S_LONG 2
#define S_SHORT 1

/**
 * struct fmt - struct
 * @fmt: format
 * @fn: fn
 */
struct fmt
{
	char fmt;
	int (*fn)(va_list, char[], int, int, int, int);
};


/**
 * typedef struct fmt fmt_t - Struct
 * @fmt: The format.
 * @fm_t: The function associated.
 */
typedef struct fmt fmt_t;

int _printf(const char *format, ...);
int handle_print(const char *fmt, int *p,
va_list list, char buffer[], int flag, int sizes, int width, int prec);

int print_char(va_list types, char buffer[],
	int flag, int sizes, int width, int prec);
int print_string(va_list types, char buffer[],
	int flag, int sizes, int width, int prec);
int print_percent(va_list types, char buffer[],
	int flag, int sizes, int width, int prec);

int print_int(va_list types, char buffer[],
	int flag, int sizes, int width, int prec);
int print_binary(va_list types, char buffer[],
	int flag, int sizes, int width, int prec);
int print_unsigned(va_list types, char buffer[],
	int flag, int sizes, int width, int prec);
int print_octal(va_list types, char buffer[],
	int flag, int sizes, int width, int prec);
int print_hexadecimal(va_list types, char buffer[],
	int flag, int sizes, int width, int prec);
int print_hexa_upper(va_list types, char buffer[],
	int flag, int sizes, int width, int prec);

int print_hexa(va_list types, char map_to[],
char buffer[], int flag, char flag_ch, int sizes, int width, int prec);

int print_non_printable(va_list types, char buffer[],
	int flag, int sizes, int width, int prec);

int print_pointer(va_list types, char buffer[],
	int flag, int sizes, int width, int prec);

int handle_print(const char *fmt, int *p,
va_list list, char buffer[], int flag, int sizes, int width, int prec);

void print_buffer(char buffer[], int *buff_ind);
int get_flags(const char *format, int *p);
int get_width(const char *format, int *p, va_list list);
int get_prec(const char *format, int *p, va_list list);
int get_sizes(const char *format, int *p);

int print_reverse(va_list types, char buffer[],
	int flag, int sizes, int width, int prec);

int print_rot13string(va_list types, char buffer[],
	int flag, int sizes, int width, int prec);

int handle_write_char(char c, char buffer[],
	int flag, int sizes, int width, int prec);
int write_number(int is_negative, int ind, int flag,
		int sizes, char buffer[], int width, int prec);
int write_num(int ind, char buffer[], int flag, int width, int prec,
	int length, char padd, char extra_c);
int write_pointer(char buffer[], int ind, int length,
	int width, int flag, char padd, char extra_c, int padd_start);

int write_unsigned(int is_negative, int ind,
char buffer[],
	int flag, int sizes, int width, int prec);

int is_printable(char);
int append_hexa_code(char, char[], int);
int is_digit(char);

long int convert_size_number(long int num, int sizes);
long int convert_size_unsigned(unsigned long int num, int sizes);

#endif
