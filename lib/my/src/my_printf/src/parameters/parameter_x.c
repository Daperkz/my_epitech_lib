/*
** EPITECH PROJECT, 2025
** parameter_x
** File description:
** x_parameters HEX/hex
*/

#include <stdarg.h>

#include "my_printf_utils.h"

#include "utils.h"

char *parameter_x(va_list args, cot_err_t *coterr)
{
    unsigned int nb = va_arg(args, unsigned int);
    char *str = my_uitoab(nb, "0123456789abcdef");

    if (!str)
        return NULL;
    return str;
}

char *parameter_xx(va_list args, cot_err_t *coterr)
{
    unsigned int nb = va_arg(args, unsigned int);
    char *str = my_uitoab(nb, "0123456789ABCDEF");

    if (!str)
        return NULL;
    return str;
}
