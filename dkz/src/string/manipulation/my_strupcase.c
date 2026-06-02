/*
** EPITECH PROJECT, 2025
** libdkz
** File description:
** my_strupcase
** puts every letter in uppercase
*/

#include "dkz/macro.h"

char *my_strupcase(char *str)
{
    int i = 0;

    if (!str)
        return (NULL);
    while (str[i]) {
        if (str[i] >= 'a' && str[i] <= 'z')
            str[i] += ('A' - 'a');
        i++;
    }
    return str;
}
