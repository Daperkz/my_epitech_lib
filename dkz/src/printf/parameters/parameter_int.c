/*
** EPITECH PROJECT, 2025
** libdkz
** File description:
** parameter_int
** all_parameters that requires an int input
*/

#include <stdarg.h>

#include "internal.h"

#include "dkz/utils.h"

char *parameter_d(va_list args, pf_ctx_t *coterr)
{
    int nb = va_arg(args, int);
    char *str = my_itoab(nb, "0123456789");

    coterr->count += 0;
    if (!str)
        return NULL;
    return str;
}

char *parameter_u(va_list args, pf_ctx_t *coterr)
{
    unsigned int nb = va_arg(args, unsigned int);
    char *str = my_uitoab(nb, "0123456789");

    coterr->count += 0;
    if (!str)
        return NULL;
    return str;
}
