/*
** EPITECH PROJECT, 2025
** libdkz
** File description:
** parameter_chars
*/

#include <stdarg.h>

#include "dkz/string.h"
#include "dkz/utils.h"

#include "my_printf/internal.h"
#include "my_printf/modifiers.h"

char *parameter_c(va_list args, pf_ctx_t *coterr)
{
    char c = va_arg(args, int);
    char *str = malloc(sizeof(char) * 2);

    UNUSED(coterr);
    if (!str)
        return NULL;
    str[0] = c;
    str[1] = '\0';
    return (str);
}

char *parameter_s(va_list args, pf_ctx_t *coterr)
{
    char *str = va_arg(args, char *);

    UNUSED(coterr);
    if (str == NULL) {
        return (my_strdup("(null)"));
    }
    return (my_strdup(str));
}

char *parameter_percent(va_list args, pf_ctx_t *coterr)
{
    UNUSED(args);
    UNUSED(coterr);
    return (my_strdup("%"));
}
