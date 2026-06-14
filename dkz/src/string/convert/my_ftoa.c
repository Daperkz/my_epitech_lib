/*
** EPITECH PROJECT, 2025
** libdkz
** File description:
** my_ftoa
*/

/*
** EPITECH PROJECT, 2025
** my_put_float
** File description:
** prints out a float value
*/

#include <stdlib.h>

#include "dkz/string.h"
#include "dkz/math.h"
#include "dkz/utils.h"

static int floatlen(double nb, int precision)
{
    int len = (precision > 0) ? (1 + precision) : 0;

    if (nb < 0.0 || (nb == 0.0 && 1.0 / nb < 0.0)) {
        len++;
    }
    len += my_intlen((int)nb);
    return len;
}

static char *special_case(double nb)
{
    if (nb == 1.0 / 0.0) {
        return my_strdup("inf");
    } else if (nb == -1.0 / 0.0) {
        return my_strdup("-inf");
    } else {
        return my_strdup("nan");
    }
    return NULL;
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

void construct_string(
    char *str, char *integer_part, char *decimal_part, int precision
)
{
    int leading_zeros;

    my_strcat(str, integer_part);
    if (precision > 0) {
        my_strcat(str, ".");
        leading_zeros = precision - my_strlen(decimal_part);
        for (int i = 0; i < leading_zeros; i++)
            my_strcat(str, "0");
        my_strcat(str, decimal_part);
    }
}

char *my_ftoa(double nb, int precision)
{
    int float_len = floatlen(nb, precision);
    int decimal;
    int decimal_precision = my_ipow(10, precision);
    char *integer_part;
    char *decimal_part;
    char *str;

    if (nb != nb || nb == 1.0 / 0.0 || nb == -1.0 / 0.0)
        return special_case(nb);
    str = malloc(sizeof(char) * (float_len + 1));
    if (!str)
        return (NULL);
    str[0] = '\0';
    sign_case_x_decimal_calc(&nb, &str, &decimal, decimal_precision);
    integer_part = my_itoab((int)nb, BASE10);
    decimal_part = my_itoab(decimal, BASE10);
    construct_string(str, integer_part, decimal_part, precision);
    free(integer_part);
    free(decimal_part);
    return str;
}
