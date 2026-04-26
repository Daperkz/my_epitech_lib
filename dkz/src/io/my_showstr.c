/*
** EPITECH PROJECT, 2025
** libdkz
** File description:
** my_showstr
** prints a string and returns 0. If this string contains non-printable
** characters, they must be printed hexadecimally (in lowercase letters)
** with a backslash before the given value.
*/

#include "dkz/macro.h"
#include "dkz/io.h"

static void leading_zero(char c)
{
    if (c < 16)
        my_putchar('0');
}

int my_showstr(char const *str)
{
    if (!str)
        return (EXIT_FAILURE);
    while (*str) {
        if (*str < 32 || *str > 126) {
            my_putchar('\\');
            leading_zero(*str);
            my_put_nbr_base(*str, "0123456789abcdef");
        } else {
            my_putchar(*str);
        }
        str++;
    }
    return (EXIT_SUCCESS);
}
