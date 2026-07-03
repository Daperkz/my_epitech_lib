/*
** EPITECH PROJECT, 2026
** libdkz
** File description:
** test_my_put_float_hex
*/

#include "test.h"

Test(my_put_float_hex, zero_and_sign)
{
    char *res1 = my_put_float_hex(0.0, "0123456789abcdef");
    char *res2 = my_put_float_hex(-0.0, "0123456789abcdef");

    cr_assert_not_null(res1);
    cr_assert_not_null(res2);
    cr_assert_str_eq(res1, "0x0p+0");
    cr_assert_str_eq(res2, "-0x0p+0");
    free(res1);
    free(res2);
}

Test(my_put_float_hex, standard_value)
{
    char *res = my_put_float_hex(1.0, "0123456789abcdef");

    cr_assert_not_null(res);
    cr_assert_str_eq(res, "0x1.0p+0");
    free(res);
}

Test(my_put_float_hex, capital_base)
{
    char *res = my_put_float_hex(1.0, "0123456789ABCDEF");

    cr_assert_not_null(res);
    cr_assert_str_eq(res, "0X1.0P+0");
    free(res);
}

Test(my_put_float_hex, my_strdup_fail, .fini = reset_malloc_wrapper)
{
    char *res;

    set_malloc_fail(1);
    set_malloc_count(0);
    res = my_put_float_hex(1.5, "0123456789abcdef");
    cr_assert_null(res);
}

Test(my_put_float_hex, allocation_fail, .fini = reset_malloc_wrapper)
{
    char *res;

    set_malloc_fail(1);
    set_malloc_count(1);
    res = my_put_float_hex(-1.5, "0123456789abcdef");
    cr_assert_null(res);
}

Test(my_put_float_hex, subnormal_number)
{
    char *res = my_put_float_hex(1e-315, "0123456789abcdef");

    cr_assert_not_null(res);
    cr_assert_not_null(res);
    free(res);
}

Test(my_put_float_hex, special_cases)
{
    char *nan = my_put_float_hex(0.0/0.0, "0123456789abcdef");
    char *inf = my_put_float_hex(1.0/0.0, "0123456789abcdef");
    char *ninf = my_put_float_hex(-1.0/0.0, "0123456789abcdef");

    cr_assert_not_null(nan);
    cr_assert_not_null(inf);
    cr_assert_not_null(ninf);
    cr_assert_str_eq(nan, "nan");
    cr_assert_str_eq(inf, "inf");
    cr_assert_str_eq(ninf, "-inf");
    free(nan);
    free(inf);
    free(ninf);
}

Test(my_put_float_hex, hex_parts_malloc_fail, .fini = reset_malloc_wrapper)
{
    char *res;

    set_malloc_fail(1);
    set_malloc_count(2);
    res = my_put_float_hex(1.5, "0123456789abcdef");
    cr_assert_null(res);
}

Test(my_put_float_hex, append_short_circuit, .fini = reset_malloc_wrapper)
{
    char *res;

    set_malloc_fail(1);
    set_malloc_count(3);
    res = my_put_float_hex(1.5, "0123456789abcdef");
    cr_assert_null(res);
}
