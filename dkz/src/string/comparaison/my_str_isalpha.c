/*
** EPITECH PROJECT, 2025
** libdkz
** File description:
** my_str_isalpha
** returns 1 if the string passed as parameter only contains alphabetical
** characters and 0 if the string contains another type of character.
*/

#include "dkz/string.h"

int is_alphabetical(char const c)
{
    return (is_upper(c) || is_lower(c));
}

int is_alphanumeric(char const c)
{
    return (is_upper(c) || is_lower(c) || is_num(c));
}

int my_str_isalpha(char const *str)
{
    if (!str)
        return (0);
    while (*str) {
        if (!is_alphabetical(*str)) {
            return (0);
        }
        str++;
    }
    return (1);
}
