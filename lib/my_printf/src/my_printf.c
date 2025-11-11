/*
** EPITECH PROJECT, 2025
** my_printf
** File description:
** printf
*/

#include <unistd.h>
#include "switch_parameters.h"
#include "flag_to_func.h"
#include "minilib.h"
#include "count_error.h"

static int internal_printf(int fd, const char *format, va_list args)
{
    cot_err_t coterr = {0, 0};

    while (*format != '\0') {
        if (*format == '%') {
            format++;
            format_gestion(fd, args, format, &coterr);
        } else {
            my_putchar(fd, *format, &coterr);
        }
        format++;
    }
    return coterr.error ? -1 : coterr.count;
}

int my_printf(const char *format, ...)
{
    va_list args;
    int ret;

    va_start(args, format);
    ret = internal_printf(1, format, args);
    va_end(args);
    return ret;
}

int my_fprintf(int fd, const char *format, ...)
{
    va_list args;
    int ret;

    va_start(args, format);
    ret = internal_printf(fd, format, args);
    va_end(args);
    return ret;
}
