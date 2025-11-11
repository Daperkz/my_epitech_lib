/*
** EPITECH PROJECT, 2025
** my_put_float
** File description:
** prints out a float value
*/

#include <stdlib.h>
#include "my_strcat.h"
#include "my_putnbr.h"

static char * special_case(char *str, double nb)
{
    if (nb == 1.0 / 0.0) {
        my_strcat(str, "inf");
    } else if (nb == -1.0 / 0.0) {
        my_strcat(str, "-inf");
    } else {
        my_strcat(str, "nan");
    }
    return str;
}

char *my_put_float(double nb)
{
    int decimal;
    int nbr_decimal = 1000000;
    int limit = nbr_decimal / 100;
    char *str = malloc(sizeof(char) * 1);

    str[0] = '\0';
    if (nb != nb || nb == 1.0 / 0.0 || nb == -1.0 / 0.0)
        return special_case(str, nb);
    if (nb < 0) {
        my_strcat(str, "-");
        nb *= -1;
    }
    decimal = (int) ((nb - (int) nb) * nbr_decimal + 0.5);
    my_strcat(str, my_strcat(my_put_nbr_base((int) nb, "0123456789"), "."));
    while (limit > 0 && decimal < limit) {
        my_strcat(str, "0");
        limit /= 10;
    }
    return my_strcat(str, my_put_nbr_base(decimal, "0123456789"));
}
