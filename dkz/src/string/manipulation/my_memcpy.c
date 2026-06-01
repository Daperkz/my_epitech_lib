/*
** EPITECH PROJECT, 2026
** libdkz
** File description:
** my_memcpy
*/

#include "dkz/macro.h"

void *my_memcpy(void *dest, void const *src, long n)
{
    char *d;
    const char *s;

    if (!dest || !src)
        return (NULL);
    d = (char *)dest;
    s = (const char *)src;
    for (long i = 0; i < n; i++)
        d[i] = s[i];
    return (dest);
}
