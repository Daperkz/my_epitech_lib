/*
** EPITECH PROJECT, 2025
** my_putnbr.c
** File description:
** prints out a number
*/

#include <stdlib.h>
#include "my_strcat.h"
#include "my_strlen.h"

static int intlen(unsigned int nb, int base_size)
{
    int len = 0;

    if (nb == 0) {
        return 1;
    }
    while (nb >= 1) {
        len++;
        nb /= base_size;
    }
    return len;
}

char *my_put_unsigned_nbr_base(unsigned int nb, char *base)
{
    int base_size = my_strlen(base);
    int nblen = intlen(nb, base_size);
    char *str = malloc(sizeof(char) * (nblen + 1));
    int i = nblen - 1;

    if (nb == 0) {
        str[0] = base[0];
        str[nblen] = '\0';
        return str;
    }
    while (nb >= 1) {
        str[i] = base[nb % base_size];
        nb /= base_size;
        i--;
    }
    str[nblen] = '\0';
    return str;
}
