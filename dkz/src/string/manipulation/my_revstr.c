/*
** EPITECH PROJECT, 2025
** libdkz
** File description:
** my_revstr
** reverses a string
*/

#include "dkz/macro.h"
#include "dkz/string.h"

char *my_revstr(char *str)
{
    int size = my_strlen(str);
    int half = (size / 2);
    int i = 0;
    char temp;

    if (!str)
        return (NULL);
    while (i < half) {
        temp = str[i];
        str[i] = str[size - i - 1];
        str[size - i - 1] = temp;
        i++;
    }
    return str;
}
