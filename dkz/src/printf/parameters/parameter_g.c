/*
** EPITECH PROJECT, 2025
** libdkz
** File description:
** parameter_g
** float or scientific
*/

#include <stdarg.h>
#include <stdio.h>

#include "dkz/string.h"
#include "dkz/math.h"
#include "dkz/utils.h"

#include "my_printf/internal.h"

static int number_of_number(char *str, int *nb_count)
{
    int i = 0;

    if (str[i] == '-')
        i++;
    while (str[i] && str[i] >= '0' && str[i] <= '9') {
        i++;
        (*nb_count)++;
    }
    if (str[i] != '.')
        return (i);
    i++;
    while ((*nb_count) <= 5) {
        (*nb_count)++;
        i++;
    }
    return (i);
}

static void round_and_truncate(char *str, int nb_max, int nb_count)
{
    if (nb_count <= 5)
        return;
    if (str[nb_max + 1] > '5')
        str[nb_max]++;
    str[nb_max + 1] = '\0';
}

static char *remove_excess(char *str)
{
    int size = 0;
    int i = 0;
    int nb_count = 0;
    int nb_max;

    if (!str)
        return (NULL);
    size = my_strlen(str);
    i = size - 1;
    while (str[i] == '0') {
        str[i] = '\0';
        i--;
    }
    if (str[i] == '.')
        str[i] = '\0';
    nb_max = number_of_number(str, &nb_count);
    round_and_truncate(str, nb_max, nb_count);
    return (str);
}

static char *select_best_format(double nb, char *str, char *str2)
{
    if (nb != 0 && (ABS(nb) < 0.0001 || ABS(nb) >= 1000000)) {
        free(str);
        return (str2);
    }
    free(str2);
    return (str);
}

char *parameter_g(va_list args, pf_ctx_t *coterr)
{
    double nb = va_arg(args, double);
    char *str = remove_excess(my_ftoa(nb, 6));
    char *str2 = my_put_scientific(nb, "0123456789", 0);

    UNUSED(coterr);
    if (!str || !str2) {
        free(str);
        free(str2);
        return NULL;
    }
    return select_best_format(nb, str, str2);
}

char *parameter_gg(va_list args, pf_ctx_t *coterr)
{
    double nb = va_arg(args, double);
    char *str = remove_excess(my_ftoa(nb, 6));
    char *str2 = my_put_scientific(nb, "0123456789", 1);

    UNUSED(coterr);
    if (!str || !str2) {
        free(str);
        free(str2);
        return NULL;
    }
    return select_best_format(nb, str, str2);
}
