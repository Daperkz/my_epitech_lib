/*
** EPITECH PROJECT, 2025
** my_put_long
** File description:
** prints out a long
*/

#include <stdlib.h>
#include "my_strcat.h"
#include "my_strlen.h"

static int intlen(long nb, int base_size)
{
    unsigned long abs_nb = (nb < 0) ?
        (unsigned long)-(nb + 1) + 1 : (unsigned long)nb;
    int len = 0;

    if (nb == 0) {
        return 1;
    } else if (nb < 0) {
        len++;
    }
    while (abs_nb > 0) {
        len++;
        abs_nb /= base_size;
    }
    return len;
}

char *my_put_long_base(long nb, char *base)
{
    int base_size = my_strlen(base);
    int nblen = intlen(nb, base_size);
    char *str = malloc(sizeof(char) * (nblen + 1));
    unsigned long abs_nb = (nb < 0) ?
        (unsigned long)-(nb + 1) + 1 : (unsigned long)nb;

    if (!str)
        return NULL;
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
