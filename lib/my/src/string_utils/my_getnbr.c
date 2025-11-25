/*
** EPITECH PROJECT, 2025
** my_getnbr
** File description:
** returns a number, sent to the function as a string
*/

#include "my_math.h"

static int is_num(char c)
{
    return ('0' <= c && c <= '9');
}

static int find_num(char *str, int *i)
{
    while (str[*i] == '-' && str[*i] != '\0')
        (*i)++;
    return *i;
}

int my_getnbr(char const *str)
{
    int start;
    int i = 0;
    int result = 0;

    while (!is_num(str[i])) {
        i++;
    }
    start = i;
    while (is_num(str[i])) {
        result = ((result * 10) + (str[i] - '0'));
        i++;
    }
    if (str[start - 1] == '-')
        return -result;
    return result;
}

double my_getfnbrspe(char *str, int *error_ptr)
{
    int i = 0;
    int start = find_num(str, &i);
    double result = 0;
    int count = 0;
    int rev = 0;

    while ((is_num(str[i]) || str[i] == '.') && str[i] != '\0') {
        if (str[i] == '.') {
            count = 1;
            i++;
            continue;
        }
        result = ((result * 10) + (str[i] - '0'));
        rev += count ? 1 : 0;
        i++;
    }
    if ((!is_num(str[i]) && str[i] != '\0') || !is_num(str[start]))
        (*error_ptr) = 1;
    result /= my_ipow(10, rev);
    return str[start - 1] == '-' ? -result : result;
}

int my_getnbrspe(char *str, int *error_ptr)
{
    int i = 0;
    int start = find_num(str, &i);
    int result = 0;

    while (is_num(str[i])) {
        result = ((result * 10) + (str[i] - '0'));
        i++;
    }
    if ((!is_num(str[start]) && str[start] != '-') ||
        (!is_num(str[i]) && str[i] != '\0')) {
        (*error_ptr) = 1;
    }
    if (str[start - 1] == '-')
        return -result;
    return result;
}
