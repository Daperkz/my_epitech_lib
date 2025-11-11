/*
** EPITECH PROJECT, 2025
** parameter_o
** File description:
** octal parameter
*/

#include <stdarg.h>
#include "minilib.h"
#include "flag_to_func.h"

void parameter_o(int fd, va_list args, cot_err_t *coterr)
{
    unsigned int nb = va_arg(args, unsigned int);
    char *str = my_put_unsigned_nbr_base(nb, "01234567");

    my_putstr(fd, str, coterr);
    free(str);
}
