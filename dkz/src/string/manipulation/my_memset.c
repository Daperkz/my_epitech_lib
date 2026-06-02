/*
** EPITECH PROJECT, 2026
** libdkz
** File description:
** my_memset
*/

#include "dkz/macro.h"

void *my_memset(void *dest, int c, long n)
{
    unsigned char *d;

    if (!dest)
        return (NULL);
    d = dest;
    while (n > 0) {
        *d = (unsigned char)c;
        d++;
        n--;
    }
    return (d);
}
