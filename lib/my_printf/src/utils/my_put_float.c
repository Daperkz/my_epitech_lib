/*
** EPITECH PROJECT, 2025
** my_put_float
** File description:
** prints out a float value
*/

#include <stdlib.h>

#include "my_strcat.h"
#include "my_putnbr.h"
#include "my_strlen.h"

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

static char *special_case(double nb)
{
    char *str;

    if (nb == 1.0 / 0.0) {
        str = malloc(sizeof(char) * 4);
        return (!str) ? NULL : my_strcpy(str, "inf");
    } else if (nb == -1.0 / 0.0) {
        str = malloc(sizeof(char) * 5);
        return (!str) ? NULL : my_strcpy(str, "-inf");
    } else {
        str = malloc(sizeof(char) * 4);
        return (!str) ? NULL : my_strcpy(str, "nan");
    }
    return NULL;
}

static int pow(int n, int p)
{
    int result = 1;

    for (int i = 0; i < p; i++)
        result *= n;
    return result;
}

static void sign_case_x_decimal_calc(
    double *nb, char **str_ptr, int *decimal_ptr, int decimal_precision)
{
    if (*nb < 0.0 || (
            *nb == 0.0 && (1.0 / *nb < 0.0))) {
        my_strcat((*str_ptr), "-");
        (*nb) *= -1.0;
    }
    (*decimal_ptr) = (int) ((*nb - (int) *nb) * decimal_precision + 0.5);
    if (*decimal_ptr == decimal_precision) {
        (*nb) += 1.0;
        *decimal_ptr = 0;
    }
}

char *my_put_float(double nb, int precision)
{
    int float_len = floatlen(nb, precision);
    int decimal;
    int decimal_precision = pow(10, precision);
    char *integer_part;
    char *decimal_part;
    char *str;

    if (nb != nb || nb == 1.0 / 0.0 || nb == -1.0 / 0.0)
        return special_case(nb);
    str = malloc(sizeof(char) * (float_len + 1));
    str[0] = '\0';
    sign_case_x_decimal_calc(&nb, &str, &decimal, decimal_precision);
    integer_part = my_put_nbr_base((int)nb, "0123456789");
    decimal_part = my_put_nbr_base(decimal, "0123456789");
    my_strcat(my_strcat(my_strcat(str, integer_part), "."), decimal_part);
    for (int i = 0; i < precision - my_strlen(decimal_part); i++)
        my_strcat(str, "0");
    free(integer_part);
    free(decimal_part);
    return str;
}
