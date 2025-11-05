/*
** EPITECH PROJECT, 2025
** parameter_x
** File description:
** x_parameters HEX/hex
*/

#include <stdarg.h>
#include "minilib.h"

void parameter_x(int fd, va_list args, cot_err_t *coterr)
{
    unsigned int nb = va_arg(args, unsigned int);
    char *str = my_put_unsigned_nbr_base(nb, "0123456789abcdef");

    my_putstr(fd, str, coterr);
    free(str);
}

void parameter_xx(int fd, va_list args, cot_err_t *coterr)
{
    unsigned int nb = va_arg(args, unsigned int);
    char *str = my_put_unsigned_nbr_base(nb, "0123456789ABCDEF");

    my_putstr(fd, str, coterr);
    free(str);
}
