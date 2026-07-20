/*
** EPITECH PROJECT, 2025
** libdkz
** File description:
** my_convert_base
** returns the result from the nbr string conversion
** (expressed in a base_from radix to a base_to radix),
** in the form of a newly, and sufficiently, allocated string.
** The number, represented by nbr, fits in an integer.
*/

#include <unistd.h>
#include <stdlib.h>

#include "dkz/utils.h"

static int get_char_index(char c, char const *base)
{
    for (int i = 0; base[i]; i++) {
        if (base[i] == c)
            return i;
    }
    return -1;
}

static int get_base_len(char const *base)
{
    int len = 0;

    if (!base)
        return 0;
    while (base[len]) {
        if (base[len] == '+' || base[len] == '-')
            return 0;
        if (get_char_index(base[len], base) < len)
            return 0;
        len++;
    }
    return (len < 2) ? 0 : len;
}

static long parse_to_int(char const *str, char const *base, int base_len)
{
    long result = 0;
    int sign = 1;
    int i = 0;
    int idx;

    while (str[i] == '+' || str[i] == '-') {
        if (str[i] == '-')
            sign *= -1;
        i++;
    }
    while (str[i]) {
        idx = get_char_index(str[i], base);
        if (idx == -1)
            break;
        result = result * base_len + idx;
        i++;
    }
    return result * sign;
}

static int get_num_len(long nbr, int base_len)
{
    int len = 0;

    if (nbr <= 0) {
        len++;
        nbr = -nbr;
    }
    while (nbr > 0) {
        nbr /= base_len;
        len++;
    }
    return len;
}

static void fill_result(
    char *result, long decimal_val, char const *base_to, int len_to
)
{
    int res_len = get_num_len(decimal_val, len_to);
    int is_neg = (decimal_val < 0) ? 1 : 0;
    long num = is_neg ? -decimal_val : decimal_val;

    result[res_len] = '\0';
    if (decimal_val == 0) {
        result[0] = base_to[0];
        return;
    }
    for (int i = res_len - 1; i >= is_neg; i--) {
        result[i] = base_to[num % len_to];
        num /= len_to;
    }
    if (is_neg)
        result[0] = '-';
}

char *convert_base(char const *nbr, char const *base_from, char const *base_to)
{
    int len_from = get_base_len(base_from);
    int len_to = get_base_len(base_to);
    long decimal_val = 0;
    char *result = NULL;

    if (!nbr || len_from < 2 || len_to < 2)
        return NULL;
    decimal_val = parse_to_int(nbr, base_from, len_from);
    result = malloc(sizeof(char) * (get_num_len(decimal_val, len_to) + 1));
    if (!result)
        return NULL;
    fill_result(result, decimal_val, base_to, len_to);
    return result;
}
