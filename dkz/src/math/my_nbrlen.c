/*
** EPITECH PROJECT, 2025
** libdkz
** File description:
** my_nbrlen
*/

#include "dkz/utils.h"

int my_intlenb(int x, int baselen)
{
    int len = 0;

    if (x == 0)
        return 1;
    if (x < 0)
        x = -x;
    while (x > 0) {
        x /= baselen;
        len++;
    }
    return len;
}

int my_intlen(int x)
{
    return (my_intlenb(x, 10));
}
