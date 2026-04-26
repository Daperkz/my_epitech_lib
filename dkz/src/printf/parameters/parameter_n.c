/*
** EPITECH PROJECT, 2025
** libdkz
** File description:
** parameter_n
*/

#include <stdarg.h>

#include "dkz/string.h"
#include "dkz/utils.h"

#include "internal.h"

char *parameter_n(va_list args, pf_ctx_t *coterr)
{
    int *x = va_arg(args, int *);
    char *str = malloc(sizeof(char) * 1);

    *x = coterr->count;
    if (!str)
        return NULL;
    my_strcpy(str, "");
    return str;
}
