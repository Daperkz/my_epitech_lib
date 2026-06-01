/*
** EPITECH PROJECT, 2025
** libdkz
** File description:
** my_atof
** returns a number, sent to the function as a string
*/

#include "dkz/math.h"

static int is_num(char c)
{
    return ('0' <= c && c <= '9');
}

static int find_num(char const *str)
{
    int i = 0;

    while (str[i] && str[i] == '-' && !is_num(str[i]))
        i++;
    return (i);
}

static int is_negative(char const *str)
{
    int count = 0;

    while (*str && !is_num(*str)) {
        if (*str == '-')
            count++;
        str++;
    }
    return (count % 2);
}

double my_atof(char const *str)
{
    int i;
    int start;
    double result = 0.0;
    int rev10 = 0;

    if (!str)
        return (0.0);
    start = find_num(str);
    for (i = start; (is_num(str[i]) || str[i] == '.') && str[i]; i++) {
        if (str[i] == '.') {
            rev10 = 1;
            continue;
        }
        if (rev10 > 0) {
            result += ((double)(str[i] - '0')) / ((double)my_ipow(10, rev10));
            rev10++;
        } else
            result = ((result * 10) + (str[i] - '0'));
    }
    return is_negative(str) ? -result : result;
}

double my_getfnbrspe(char const *str, int *error_p)
{
    int i;
    int start;
    double result = 0.0;
    int count = 0;
    int rev = 0;

    if (!str) {
        (*error_p) = 1;
        return (0.0);
    }
    start = find_num(str);
    for (i = start; (is_num(str[i]) || str[i] == '.') && str[i]; i++) {
        if (str[i] == '.') {
            count = 1;
            continue;
        }
        result = ((result * 10) + (str[i] - '0'));
        rev += count ? 1 : 0;
    }
    if ((str[i] && !is_num(str[i])) || !is_num(str[start]))
        (*error_p) = 1;
    result /= my_ipow(10, rev);
    return is_negative(str) ? -result : result;
}
