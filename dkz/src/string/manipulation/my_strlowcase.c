/*
** EPITECH PROJECT, 2025
** libdkz
** File description:
** my_strlowcase
** puts every uppercase letters to a lowercase
*/

#include "dkz/macro.h"

char *my_strlowcase(char *str)
{
    int i = 0;

    if (!str)
        return (NULL);
    while (str[i]) {
        if (str[i] >= 'A' && str[i] <= 'Z')
            str[i] += ('a' - 'A');
        i++;
    }
    return str;
}
