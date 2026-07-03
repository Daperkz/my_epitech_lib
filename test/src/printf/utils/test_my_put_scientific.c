/*
** EPITECH PROJECT, 2026
** libdkz
** File description:
** test_my_put_scientific
*/

#include "test.h"

Test(my_put_scientific, special_cases)
{
    char *res1 = my_put_scientific(0.0/0.0, "0123456789abcdef", 0);
    char *res2 = my_put_scientific(1.0/0.0, "0123456789abcdef", 0);
    char *res3 = my_put_scientific(-1.0/0.0, "0123456789abcdef", 0);

    cr_assert_not_null(res1);
    cr_assert_not_null(res2);
    cr_assert_not_null(res3);
    cr_assert_str_eq(res1, "nan");
    cr_assert_str_eq(res2, "inf");
    cr_assert_str_eq(res3, "-inf");
    free(res1);
    free(res2);
    free(res3);
}

Test(my_put_scientific, zero_case)
{
    char *res = my_put_scientific(0.0, "0123456789", 0);
    char *val = my_put_scientific(1.23, "0123456789", 0);

    cr_assert_not_null(res);
    cr_assert_not_null(val);
    cr_assert_str_eq(res, "0.000000e+00");
    cr_assert_str_eq(val, "1.230000e+00");
    free(res);
    free(val);
}

Test(my_put_scientific, standard_values)
{
    char *res_pos = my_put_scientific(123.45, "0123456789", 0);
    char *res_neg = my_put_scientific(-123.45, "0123456789", 1);

    cr_assert_not_null(res_neg);
    cr_assert_not_null(res_pos);
    cr_assert(res_pos[0] != '-');
    cr_assert(res_neg[0] == '-');
    free(res_pos); free(res_neg);
}

Test(my_put_scientific, exponent_padding)
{
    char *res = my_put_scientific(5.0, "0123456789", 0);

    cr_assert_not_null(res);
    cr_assert_str_eq(res, "5.000000e+00", "Expected exact match");
    cr_assert_not_null(strstr(res, "e+00"), "String should contain e+00");
    free(res);
}

Test(my_put_scientific, exponent_logic)
{
    char *res = my_put_scientific(-0.005, "0123456789", 0);

    cr_assert_not_null(res);
    cr_assert_str_eq(res, "-5.000000e-03");
    free(res);
}

Test(my_put_scientific, base_strdup_fail, .fini = reset_malloc_wrapper)
{
    char *res;

    set_malloc_fail(1);
    set_malloc_count(0);
    res = my_put_scientific(1.050, "0123456789", 0);
    cr_assert_null(res);
}

Test(
    my_put_scientific,
    append_malloc_fail,
    .fini = reset_malloc_wrapper
)
{
    char *res;

    set_malloc_fail(1);
    set_malloc_count(1);
    res = my_put_scientific(-1.050, "0123456789", 0);
    cr_assert_null(res);
}

Test(my_put_scientific, itoab_malloc_fail, .fini = reset_malloc_wrapper)
{
    set_malloc_fail(1);
    set_malloc_count(2);
    char *res = my_put_scientific(1.23, "0123456789", 0);
    cr_assert_null(res);
}

Test(my_put_scientific, exponent_ge_10)
{
    char *res = my_put_scientific(10000000000.0, "0123456789", 0);

    cr_assert_not_null(res);
    cr_assert_str_eq(res, "1.000000e+10");
    free(res);
}
