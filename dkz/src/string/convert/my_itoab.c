/*
** EPITECH PROJECT, 2025
** libdkz
** File description:
** my_itoab.c
** itoab converts an int to an array with the base of choice
*/

#include <stdlib.h>
#include <stdio.h>

#include "dkz/math.h"
#include "dkz/string.h"

char *my_itoab(int nb, char const *base)
{
    int base_size = my_strlen(base);
    int nblen = my_intlenb(nb, base_size);
    char *str = malloc(sizeof(char) * (nblen + 1));
    unsigned int abs_nb = (nb < 0) ?
        (unsigned int)-(nb + 1) + 1 : (unsigned int)nb;

    if (!str)
        return (NULL);
    str[nblen] = '\0';
    if (nb == 0) {
        str[0] = base[0];
        return str;
    } else if (nb < 0)
        str[0] = '-';
    for (int i = nblen - 1; abs_nb > 0; i--) {
        str[i] = base[abs_nb % base_size];
        abs_nb /= base_size;
    }
    return str;
}
