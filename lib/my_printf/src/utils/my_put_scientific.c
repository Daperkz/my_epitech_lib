/*
** EPITECH PROJECT, 2025
** printf
** File description:
** printf
*/

#include <stdlib.h>
#include "my_strcat.h"
#include "my_putnbr.h"

static char *put_exponent(int exponent, char *str, char *base)
{
    my_strcat(str, "e");
    if (exponent >= 0) {
        my_strcat(str, "+");
    } else {
        my_strcat(str, "-");
        exponent = -exponent;
    }
    if (exponent < 10)
        my_strcat(str, "0");
    my_strcat(str, my_put_nbr_base(exponent, base));
    return str;
}

static char *put_exponent_capitalize(int exponent, char *str, char *base)
{
    my_strcat(str, "E");
    if (exponent >= 0) {
        my_strcat(str, "+");
    } else {
        my_strcat(str, "-");
        exponent = -exponent;
    }
    if (exponent < 10)
        my_strcat(str, "0");
    my_strcat(str, my_put_nbr_base(exponent, base));
    return str;
}

static char *put_decimal(int decimal, char *str, char *base)
{
    int limit = 10000;

    while (limit > 0 && decimal < limit) {
        my_strcat(str, "0");
        limit /= 10;
    }
    my_strcat(str, my_put_nbr_base(decimal, base));
    return str;
}

static void calculate_scientific(
    double nb, int *exponent, int *entier, int *decimal
)
{
    *exponent = 0;
    while (nb >= 10.0) {
        nb /= 10.0;
        (*exponent)++;
    }
    while (nb < 1.0) {
        nb *= 10.0;
        (*exponent)--;
    }
    *entier = (int)nb;
    *decimal = (int)((nb - *entier) * 1000000 + 0.00005);
}

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

char *my_put_scientific(double nb, char *base)
{
    int exponent = 0;
    int entier = 0;
    int decimal = 0;
    char *str = malloc(sizeof(char) * 1);

    str[0] = '\0';
    if (nb != nb || nb == 1.0 / 0.0 || nb == -1.0 / 0.0)
        return special_case(str, nb);
    if (nb == 0.0) {
        my_strcat(str, "0.000000e+00");
        return str;
    }
    if (nb < 0) {
        my_strcat(str, "-");
        nb = -nb;
    }
    calculate_scientific(nb, &exponent, &entier, &decimal);
    my_strcat(str, my_put_nbr_base(entier, base));
    my_strcat(str, ".");
    return put_exponent(exponent, put_decimal(decimal, str, base), base);
}

char *my_put_scientific_capitalize(double nb, char *base)
{
    int exponent = 0;
    int entier = 0;
    int decimal = 0;
    char *str = malloc(sizeof(char) * 1);

    str[0] = '\0';
    if (nb == 0.0 / 0.0 || nb == 1.0 / 0.0 || nb == -1.0 / 0.0)
        return special_case(str, nb);
    if (nb == 0.0) {
        my_strcat(str, "0.000000E+00");
        return str;
    }
    if (nb < 0) {
        my_strcat(str, "-");
        nb = -nb;
    }
    calculate_scientific(nb, &exponent, &entier, &decimal);
    my_strcat(my_strcat(str, my_put_nbr_base(entier, base)), ".");
    put_decimal(decimal, str, base);
    return put_exponent_capitalize(exponent, str, base);
}
