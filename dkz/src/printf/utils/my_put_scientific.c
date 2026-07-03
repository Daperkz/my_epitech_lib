/*
** EPITECH PROJECT, 2025
** libdkz
** File description:
** my_put_scientific
*/

#include <stdlib.h>

#include "dkz/string.h"
#include "dkz/utils.h"

struct builder_s {
    int exponent;
    int entier;
    int decimal;
    char *str;
    short error;
};

static void append(struct builder_s *b, char *s)
{
    if (b->error)
        return;
    if (!my_strappend(&b->str, s))
        b->error = 1;
}

static void append_sign(struct builder_s *b, double *nb)
{
    if (*nb < 0) {
        append(b, "-");
        *nb = -(*nb);
    }
}

static void calculate_parts(double nb, struct builder_s *b)
{
    b->exponent = 0;
    while (nb >= 10.0) {
        nb /= 10.0;
        (b->exponent)++;
    }
    while (nb < 1.0 && nb > 0) {
        nb *= 10.0;
        (b->exponent)--;
    }
    b->entier = (int)nb;
    b->decimal = (int)((nb - b->entier) * 1000000 + 0.00005);
}

static void append_parts(struct builder_s *b, char *base)
{
    char *e_str = my_itoab(b->entier, base);
    char *d_str = my_itoab(b->decimal, base);

    if (!e_str || !d_str) {
        b->error = 1;
    } else {
        append(b, e_str);
        append(b, ".");
        for (int i = 100000; i > b->decimal && i > 1; i /= 10)
            append(b, "0");
        append(b, d_str);
    }
    free(e_str);
    free(d_str);
}

static void append_exponent(struct builder_s *b, char *base, int cap)
{
    char *exp_str = NULL;

    append(b, cap ? "E" : "e");
    append(b, b->exponent >= 0 ? "+" : "-");
    if (b->exponent < 0)
        b->exponent = -b->exponent;
    if (b->exponent < 10)
        append(b, "0");
    exp_str = my_itoab(b->exponent, base);
    if (!exp_str) {
        b->error = 1;
    } else {
        append(b, exp_str);
        free(exp_str);
    }
}

static int is_special(double nb)
{
    return (nb != nb || nb == 1.0 / 0.0 || nb == -1.0 / 0.0);
}

static char *special_case(double nb)
{
    char *str;

    if (nb == 1.0 / 0.0)
        return my_strdup("inf");
    else if (nb == -1.0 / 0.0)
        return my_strdup("-inf");
    else
        return my_strdup("nan");
    return str;
}

char *my_put_scientific(double nb, char *base, int cap)
{
    struct builder_s b = {0, 0, 0, NULL, 0};

    if (is_special(nb))
        return special_case(nb);
    b.str = my_strdup("");
    if (!b.str)
        return (NULL);
    if (nb == 0.0)
        append(&b, cap ? "0.000000E+00" : "0.000000e+00");
    else {
        append_sign(&b, &nb);
        calculate_parts(nb, &b);
        append_parts(&b, base);
        append_exponent(&b, base, cap);
    }
    if (b.error) {
        free(b.str);
        return (NULL);
    }
    return (b.str);
}
