/*
** EPITECH PROJECT, 2025
** libdkz
** File description:
** my_strcapitalize
** capitalizes the first letter of each word
*/

#include "dkz/macro.h"
#include "dkz/string.h"

char *my_strcapitalize(char *str)
{
    if (!str)
        return (NULL);
    for (int i = 0; str[i]; i++) {
        if (is_upper(str[i]))
            str[i] += 'a' - 'A';
        if ((i == 0 || !is_alphanumeric(str[i - 1])) && is_lower(str[i]))
            str[i] += ('A' - 'a');
    }
    return str;
}
