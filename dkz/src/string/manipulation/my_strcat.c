/*
** EPITECH PROJECT, 2025
** libdkz
** File description:
** my_strcat
** concatenates two strings into dest must have enough space allocated.
*/

#include "dkz/macro.h"

char *my_strcat(char *dest, char const *src)
{
    char *origin = dest;

    if (!dest || !src)
        return (NULL);
    while (*dest)
        dest++;
    while (*src) {
        *dest = *src;
        dest++;
        src++;
    }
    *dest = '\0';
    return origin;
}

char *my_strncat(char *dest, char const *src, int nb)
{
    int i = 0;
    int j = 0;

    if (!dest || !src || nb < 0)
        return (NULL);
    while (dest[i])
        i++;
    while (src[j] && j < nb) {
        dest[i] = src[j];
        i++;
        j++;
    }
    dest[i] = '\0';
    return dest;
}
