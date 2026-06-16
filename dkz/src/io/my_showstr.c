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

static int leading_zero(char c)
{
    if (c < 16)
        return my_putchar('0');
    return (0);
}

int my_showstr(char const *str)
{
    int printed = 0;

    if (!str)
        return (0);
    while (*str) {
        if (*str < 32 || *str > 126) {
            printed += my_putchar('\\');
            printed += leading_zero(*str);
            printed += my_put_nbr_base(*str, "0123456789abcdef");
        } else {
            printed += my_putchar(*str);
        }
        str++;
    }
    return (printed);
}
