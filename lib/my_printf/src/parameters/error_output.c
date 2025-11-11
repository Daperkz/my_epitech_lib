/*
** EPITECH PROJECT, 2025
** last_case
** File description:
** error_output
*/

#include <stdarg.h>
#include "minilib.h"

void error_output(char error_char, cot_err_t *coterr)
{
    my_putstr(2, "mini_printf: unknown format specifier '%", coterr);
    my_putchar(2, error_char, coterr);
    my_putstr(2, "'\n", coterr);
}
