/*
** EPITECH PROJECT, 2025
** libdkz
** File description:
** my_put_float_hex
** prints out a float in hex
*/

#include <stdio.h>
#include <stdlib.h>

#include "dkz/string.h"
#include "dkz/utils.h"

#include "my_printf/floating_point.h"

struct builder_s {
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
    if (*nb < 0.0 || (1.0 / *nb < 0.0)) {
        append(b, "-");
        *nb = -(*nb);
    }
}

static char *my_put_mantissa(long x, char *base)
{
    char *str = malloc(sizeof(char) * 14);
    int max = 13;

    if (!str)
        return (NULL);
    for (int i = max - 1; i >= 0; i--) {
        str[i] = base[x % 16];
        x /= 16;
    }
    str[max] = '\0';
    while (max > 1 && str[max - 1] == '0') {
        str[max - 1] = '\0';
        max--;
    }
    return str;
}

static long extract_mantissa_inbin(double nb, int *power2)
{
    double_t val = {.f = nb};
    unsigned long long bits = val.bits;
    int exp = (bits >> 52) & 0x7FF;
    long mantissa = bits & 0xFFFFFFFFFFFFF;

    if (exp == 0) {
        *power2 = -1022;
        return mantissa;
    }
    *power2 = exp - 1023;
    return mantissa | (1L << 52);
}

static void append_hex_parts(struct builder_s *b, double nb, char *base)
{
    int power2 = 0;
    long mantissa = extract_mantissa_inbin(nb, &power2);
    char *m_str = my_put_mantissa(mantissa, base);
    char *p_str = my_itoab(power2, "0123456789");

    if (!m_str || !p_str) {
        b->error = 1;
    } else {
        append(b, base[15] == 'f' ? "0x1." : "0X1.");
        append(b, m_str);
        append(b, base[15] == 'f' ? "p" : "P");
        append(b, power2 >= 0 ? "+" : "");
        append(b, p_str);
    }
    free(m_str);
    free(p_str);
}

static int is_nan(double_t val)
{
    unsigned long long exponent = (val.bits >> 52) & 0x7FF;
    unsigned long long mantissa = val.bits & 0xFFFFFFFFFFFFF;

    return (exponent == 0x7FF && mantissa != 0);
}

static int is_inf(double_t val)
{
    unsigned long long exponent = (val.bits >> 52) & 0x7FF;
    unsigned long long mantissa = val.bits & 0xFFFFFFFFFFFFF;

    return (exponent == 0x7FF && mantissa == 0);
}

static int is_special(double_t *val)
{
    return (is_nan(*val) || is_inf(*val));
}

static char *special_case(double_t *val)
{
    if (is_nan(*val))
        return my_strdup("nan");
    return my_strdup((val->bits >> 63) ? "-inf" : "inf");
}

char *my_put_float_hex(double nb, char *base)
{
    struct builder_s b = {NULL, 0};
    double_t val = {.f = nb};

    if (is_special(&val))
        return (special_case(&val));
    b.str = my_strdup("");
    if (!b.str)
        return (NULL);
    if (nb == 0.0) {
        append_sign(&b, &nb);
        append(&b, base[15] == 'f' ? "0x0p+0" : "0X0P+0");
    } else {
        append_sign(&b, &nb);
        append_hex_parts(&b, nb, base);
    }
    if (b.error) {
        free(b.str);
        return NULL;
    }
    return (b.str);
}
