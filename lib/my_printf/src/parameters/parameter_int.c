/*
** EPITECH PROJECT, 2025
** parameter_int
** File description:
** all_parameters that requires an int input
*/

#include <stdarg.h>
#include "minilib.h"

void parameter_d(int fd, va_list args, cot_err_t *coterr)
{
    int nb = va_arg(args, int);
    char *str = my_put_nbr_base(nb, "0123456789");

    my_putstr(fd, str, coterr);
    free(str);
}

void parameter_u(int fd, va_list args, cot_err_t *coterr)
{
    unsigned int nb = va_arg(args, unsigned int);
    char *str = my_put_unsigned_nbr_base(nb, "0123456789");

    my_putstr(fd, str, coterr);
    free(str);
}
