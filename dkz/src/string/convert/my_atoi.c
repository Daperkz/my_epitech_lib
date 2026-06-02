/*
** EPITECH PROJECT, 2026
** libdkz
** File description:
** my_atoi
*/

#include "dkz/math.h"
#include "dkz/string.h"

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

int my_atoi(char const *str)
{
    int result = 0;
    int neg;
    int start;

    if (!str)
        return (0);
    start = find_num(str);
    neg = is_negative(str);
    for (int i = start; is_num(str[i]); i++)
        result = ((result * 10) + (str[i] - '0'));
    return neg ? -result : result;
}

int my_getnbrspe(char const *str, int *error_p)
{
    int result = 0;
    int i = 0;
    int neg;
    int start;

    if (!str) {
        (*error_p) = 1;
        return (0);
    }
    start = find_num(str);
    neg = is_negative(str);
    for (i = start; is_num(str[i]); i++)
        result = ((result * 10) + (str[i] - '0'));
    if ((!is_num(str[start]) && str[start] != '-') ||
        (!is_num(str[i]) && str[i])) {
        (*error_p) = 1;
    }
    return neg ? -result : result;
}
