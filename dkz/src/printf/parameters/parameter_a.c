/*
** EPITECH PROJECT, 2025
** libdkz
** File description:
** parameter_a
** float hex/HEX
*/

#include <stdarg.h>

#include "dkz/utils.h"

#include "my_printf/internal.h"

char *parameter_a(va_list args, pf_ctx_t *coterr)
{
    double x = va_arg(args, double);
    char *str = my_put_float_hex(x, "0123456789abcdef");

    UNUSED(coterr);
    if (!str)
        return NULL;
    return str;
}

char *parameter_aa(va_list args, pf_ctx_t *coterr)
{
    double x = va_arg(args, double);
    char *str = my_put_float_hex(x, "0123456789ABCDEF");

    UNUSED(coterr);
    if (!str)
        return NULL;
    return str;
}
