/*
** EPITECH PROJECT, 2025
** a_parameter
** File description:
** float hex/HEX
*/

#include <stdarg.h>
#include "minilib.h"
#include "flag_to_func.h"

void parameter_a(
    int fd, va_list args, cot_err_t *coterr
)
{
    double x = va_arg(args, double);
    char *str = my_put_float_hex(x, "0123456789abcdef");

    my_putstr(fd, str, coterr);
    free(str);
}

void parameter_aa(
    int fd, va_list args, cot_err_t *coterr
)
{
    double x = va_arg(args, double);
    char *str = my_put_float_hex(x, "0123456789ABCDEF");

    my_putstr(fd, str, coterr);
    free(str);
}
