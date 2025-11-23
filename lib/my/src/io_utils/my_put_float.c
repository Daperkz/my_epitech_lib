/*
** EPITECH PROJECT, 2025
** my_put_float.c
** File description:
** my_put_float
*/

/*
** EPITECH PROJECT, 2025
** my_ftoa.c
** File description:
** my_ftoa
*/

/*
** EPITECH PROJECT, 2025
** my_put_float
** File description:
** prints out a float value
*/

#include "io_utils.h"
#include "string_utils.h"
#include "my_math.h"
#include "utils.h"

static int floatlen(double nb, int precision)
{
    int len = 1 + precision;
    double abs_ipart;

    if (nb == 0.0) {
        return (1.0 / nb < 0.0) ? 3 + precision : 2 + precision;
    } else if (nb < 0.0) {
        len++;
        abs_ipart = -(int)nb;
    } else
        abs_ipart = (int)nb;
    do {
        len++;
        abs_ipart /= 10;
    } while (abs_ipart >= 1.0);
    return len;
}

static void special_case(double nb)
{
    if (nb == 1.0 / 0.0) {
        my_putstr("inf");
    } else if (nb == -1.0 / 0.0) {
        my_putstr("-inf");
    } else {
        my_putstr("nan");
    }
}

int my_put_float(double nb, int precision)
{
    int decimal;
    int decimal_precision = my_ipow(10, precision);
    char *integer_part;
    char *decimal_part;

    if (nb != nb || nb == 1.0 / 0.0 || nb == -1.0 / 0.0) {
        special_case(nb);
        return 0;
    }
    if (nb < 0.0 || (nb == 0.0 && (1.0 / nb < 0.0)))
        my_putchar('-');
    decimal = (int) ((nb - (int) nb) * decimal_precision + 0.5);
    if (decimal == decimal_precision) {
        nb += 1.0;
        decimal = 0;
    }
    my_put_nbr((int)nb);
    my_putchar('.');
    my_put_nbr(decimal);
    for (int i = 0; i < precision - my_strlen(decimal_part); i++)
        my_putchar('0');
    return 0;
}
