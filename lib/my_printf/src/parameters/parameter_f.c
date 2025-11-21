/*
** EPITECH PROJECT, 2025
** parameter_f
** File description:
** floats
*/

#include <stdarg.h>
#include "minilib.h"

void parameter_f(int fd, va_list args, cot_err_t *coterr)
{
    double nb = va_arg(args, double);
    char *str = my_put_float(nb, 6);

    my_putstr(fd, str, coterr);
    free(str);
}

void parameter_ff(int fd, va_list args, cot_err_t *coterr)
{
    double nb = va_arg(args, double);
    char *str = my_put_float(nb, 6);

    my_putstr(fd, str, coterr);
    free(str);
}
