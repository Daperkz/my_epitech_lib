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
    unsigned int abs_x;

    if (x == 0)
        return 1;
    abs_x = (unsigned int)x;
    if (x < 0) {
        len++;
        abs_x = (unsigned int)-(x + 1) + 1;
    }
    while (abs_x > 0) {
        abs_x /= baselen;
        len++;
    }
    return len;
}

int my_intlen(int x)
{
    return (my_intlenb(x, 10));
}
