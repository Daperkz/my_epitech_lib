/*
** EPITECH PROJECT, 2025
** libdkz
** File description:
** my_put_float
*/

#include <stdlib.h>

#include "dkz/io.h"
#include "dkz/string.h"
#include "dkz/math.h"

static int special_case(double nb)
{
    if (nb == 1.0 / 0.0) {
        return my_putstr("inf");
    } else if (nb == -1.0 / 0.0) {
        return my_putstr("-inf");
    } else {
        return my_putstr("nan");
    }
    return 0;
}

static int print_the_nbr(double nb, int precision, double multiplier)
{
    long long integer_part = (long long)nb;
    double fractional_part = nb - (double)integer_part;
    long long decimals;
    int printed = 0;

    printed += my_put_nbr(integer_part);
    if (precision > 0) {
        printed += my_putchar('.');
        decimals = (long long)(fractional_part * multiplier);
        for (int i = 0; i < (precision - my_intlen(decimals)); i++)
            printed += my_putstr("0");
        printed += my_put_nbr(decimals);
    }
    return printed;
}

int my_put_float(double nb, int precision)
{
    int printed = 0;
    double multiplier;

    if (nb != nb || nb == 1.0 / 0.0 || nb == -1.0 / 0.0)
        return special_case(nb);
    if (nb < 0) {
        printed += my_putstr("-");
        nb = -nb;
    }
    multiplier = my_ipow(10, precision);
    nb += 0.5 / multiplier;
    return (printed + print_the_nbr(nb, precision, multiplier));
}
