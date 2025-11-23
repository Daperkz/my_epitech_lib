/*
** EPITECH PROJECT, 2025
** printf
** File description:
** printf
*/

#include <stdarg.h>

#include "string_utils.h"

#include "my_printf_utils.h"
#include "modifiers.h"

/*
static char *modifier_id_c(char *str, char flag, int x, int id)
{
    switch (id) {
        case 0 :
            return left(str, flag, x);
        case 2 :
            return sign_str(str, flag, x)
        default :
            return str;
    }
}

static int modifier_precision_id_c(va_list args, int x, int id)
{
    switch (id) {
        case 1 :
            return va_arg(args, int);
        default :
            return 0;
    }
}
*/

char *parameter_c(va_list args, cot_err_t *coterr)
{
    char c = va_arg(args, int);
    char *str = malloc(sizeof(char) * 1);

    if (!str)
        return NULL;
    my_strcpy(str, &c);
    return str;
}

char *parameter_s(va_list args, cot_err_t *coterr)
{
    char *str = va_arg(args, char *);

    if (str == NULL) {
        str = malloc(sizeof(char) * 7);
        if (!str)
            return NULL;
        my_strcpy(str, "(null)");
    }
    return str;
}

char *parameter_percent(va_list args, cot_err_t *coterr)
{
    char *str = malloc(sizeof(char) * 2);

    if (!str)
        return NULL;
    my_strcpy(str, "%");
    return str;
}
