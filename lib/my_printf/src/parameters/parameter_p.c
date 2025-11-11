/*
** EPITECH PROJECT, 2025
** parameter_p
** File description:
** pointer
*/

#include <stdarg.h>
#include "minilib.h"

void parameter_p(int fd, va_list args, cot_err_t *coterr)
{
    void *p = va_arg(args, void *);
    char *str = my_put_adress(p);

    my_putstr(fd, str, coterr);
    free(str);
}
