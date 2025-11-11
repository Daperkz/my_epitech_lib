/*
** EPITECH PROJECT, 2025
** printf
** File description:
** printf
*/

#include <stdarg.h>
#include "minilib.h"

void parameter_n(int fd, va_list args, cot_err_t *coterr)
{
    int *x = va_arg(args, int *);

    *x = coterr->count;
}
