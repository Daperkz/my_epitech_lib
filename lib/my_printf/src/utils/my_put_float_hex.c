/*
** EPITECH PROJECT, 2025
** my_put_float_hex
** File description:
** prints out a float in hex
*/

#include <stdio.h>
#include <stdlib.h>
#include "my_strcat.h"
#include "my_putnbr.h"
#include "floating_point.h"

static char *my_put_mantissa(long x, char *base)
{
    char *str = malloc(sizeof(char) * 14);
    int mantissa_hex_max = 13;

    for (int i = mantissa_hex_max - 1; i >= 0; i--) {
        str[i] = base[x % 16];
        x /= 16;
    }
    str[mantissa_hex_max] = '\0';
    mantissa_hex_max--;
    while (str[mantissa_hex_max] == '0') {
        str[mantissa_hex_max] = '\0';
        mantissa_hex_max--;
    }
    return str;
}

static long extract_mantissa_inbin(double nb, int *power2)
{
    double_t deconstructed_float = {.f = nb};
    unsigned long long bits = deconstructed_float.bits;
    unsigned int exponent = ((bits >> 52) & 0x7FF);
    long mantissa = bits & 0xFFFFFFFFFFFFF;
    int bias = 1023;

    *power2 = exponent - bias;
    return mantissa;
}

char *my_put_float_hex(double nb, char *base)
{
    int power2 = 0;
    long mantissa;
    char *str = malloc(sizeof(char) * 1);

    str[0] = '\0';
    if (nb == 0.0) {
        return my_strcat(str, base[15] == 'f' ? "0x0p+0" : "0X0P+0");
    }
    if (nb < 0) {
        my_strcat(str, "-");
        nb = -nb;
    }
    my_strcat(str, base[15] == 'f' ? "0x1." : "0X1.");
    mantissa = extract_mantissa_inbin(nb, &power2);
    my_strcat(str, my_put_mantissa(mantissa, base));
    my_strcat(str, base[15] == 'f' ? "p" : "P");
    if (power2 >= 0) {
        my_strcat(str, "+");
    }
    return my_strcat(str, my_put_nbr_base(power2, "0123456789"));
}
