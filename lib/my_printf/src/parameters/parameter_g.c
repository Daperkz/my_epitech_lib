/*
** EPITECH PROJECT, 2025
** parameter_g
** File description:
** float or scientific
*/

#include <stdarg.h>
#include <stdio.h>
#include "minilib.h"
#include "my_strlen.h"

static int number_of_number(char *str, int *nb_count)
{
    int i = 0;

    if (str[i] == '+' || str[i] == '-') {
        i++;
    }
    while ((str[i] != '\0' && str[i] != '.') ||
        (str[i] >= '0' && str[i] <= '9')) {
        i++;
        (*nb_count)++;
    }
    if (str[i] == '.') {
        i++;
        while ((str[i] != '\0' || (str[i] >= '0' && str[i] <= '9')) &&
            *nb_count < 5) {
            (*nb_count)++;
            i++;
        }
    }
    return i;
}

static char *remove_excess(char *str)
{
    int size = my_strlen(str);
    int i = size - 1;
    int nb_count = 0;
    int nb_max;

    while (str[i] == '0') {
        str[i] = '\0';
        i--;
    }
    if (str[i] == '.') {
        str[i] = '\0';
    }
    nb_max = number_of_number(str, &nb_count);
    if (nb_count > 5) {
        if (str[nb_max + 1] > '5') {
            str[nb_max]++;
        }
        str[nb_max + 1] = '\0';
    }
    return str;
}
/*
static char *remove_excess_e(char *str, int cap)
{
    int size = my_strlen(str);
    int i = size - 1;
    int nb_count = 0;
    int nb_max;

    while (str[i + 1] != (cap ? 'E' : 'e'))
        i--;
    while (str[i] == '0') {
        str[i] = str[i + 1];
        i--;
    }
    if (str[i] == '.')
        str[i] = '\0';
    nb_max = number_of_number(str, &nb_count);
    if (nb_count > 5) {
        if (str[nb_max + 1] > '5')
            str[nb_max]++;
        str[nb_max + 1] = '\0';
    }
    return str;
}
*/
void parameter_g(int fd, va_list args, cot_err_t *coterr)
{
    double nb = va_arg(args, double);
    char *str = remove_excess(my_put_float(nb, 6));
    char *str2 = my_put_scientific(nb, "0123456789", 0);

    if (my_strlen(str) <= my_strlen(str2)) {
        my_putstr(fd, str, coterr);
    } else {
        my_putstr(fd, str2, coterr);
    }
    free(str);
    free(str2);
}

void parameter_gg(int fd, va_list args, cot_err_t *coterr)
{
    double nb = va_arg(args, double);
    char *str = remove_excess(my_put_float(nb, 6));
    char *str2 = my_put_scientific(nb, "0123456789", 1);

    if (my_strlen(str) <= my_strlen(str2)) {
        my_putstr(fd, str, coterr);
    } else {
        my_putstr(fd, str2, coterr);
    }
    free(str);
    free(str2);
}
