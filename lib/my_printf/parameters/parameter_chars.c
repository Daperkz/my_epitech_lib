/*
** EPITECH PROJECT, 2025
** printf
** File description:
** printf
*/

#include <stdarg.h>
#include "minilib.h"
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

void parameter_c(int fd, va_list args, cot_err_t *coterr)
{
    char c = va_arg(args, int);

    my_putchar(fd, c, coterr);
}

void parameter_s(int fd, va_list args, cot_err_t *coterr)
{
    char *str = va_arg(args, char *);

    if (str == NULL) {
        my_putstr(fd, "(null)", coterr);
        return;
    }
    my_putstr(fd, str, coterr);
}

void parameter_percent(int fd, va_list args, cot_err_t *coterr)
{
    my_putchar(fd, '%', coterr);
}
