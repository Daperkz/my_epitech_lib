/*
** EPITECH PROJECT, 2025
** parameter_e
** File description:
** scientific notation
*/

#include <stdarg.h>
#include "minilib.h"

void parameter_e(int fd, va_list args, cot_err_t *coterr)
{
    double nb = va_arg(args, double);
    char *str = my_put_scientific(nb, "0123456789");

    my_putstr(fd, str, coterr);
    free(str);
}

void parameter_ee(int fd, va_list args, cot_err_t *coterr)
{
    double nb = va_arg(args, double);
    char *str = my_put_scientific_capitalize(nb, "0123456789");

    my_putstr(fd, str, coterr);
    free(str);
}
