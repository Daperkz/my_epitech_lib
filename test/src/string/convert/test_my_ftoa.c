/*
** EPITECH PROJECT, 2026
** libdkz
** File description:
** test_my_ftoa
*/

#include "test.h"

Test(my_ftoa, basic_conversion)
{
    char *str1;
    char *str2;
    char *str3;

    str1 = my_ftoa(3.1415, 2);
    cr_assert_not_null(str1);
    cr_assert_str_eq(str1, "3.14");
    free(str1);
    str2 = my_ftoa(-0.5, 1);
    cr_assert_not_null(str2);
    cr_assert_str_eq(str2, "-0.5");
    free(str2);
    str3 = my_ftoa(10.9, 0);
    cr_assert_not_null(str3);
    cr_assert_str_eq(str3, "11");
    free(str3);
}

Test(my_ftoa, edge_cases_and_rounding)
{
    char *str1;
    char *str2;
    char *str3;
    char *str4;

    str1 = my_ftoa(10.99, 1);
    cr_assert_not_null(str1);
    cr_assert_str_eq(str1, "11.0");
    free(str1);
    str2 = my_ftoa(-0.0, 2);
    cr_assert_not_null(str2);
    cr_assert_str_eq(str2, "-0.00");
    free(str2);
    str3 = my_ftoa(1.005, 4);
    cr_assert_not_null(str3);
    cr_assert_str_eq(str3, "1.0050");
    free(str3);
    str4 = my_ftoa(0.0, 2);
    cr_assert_not_null(str4);
    cr_assert_str_eq(str4, "0.00");
    free(str4);
}

Test(my_ftoa, special_cases)
{
    char *str_inf;
    char *str_minf;
    char *str_nan;

    str_inf = my_ftoa(1.0 / 0.0, 2);
    cr_assert_not_null(str_inf);
    cr_assert_str_eq(str_inf, "inf");
    free(str_inf);
    str_minf = my_ftoa(-1.0 / 0.0, 2);
    cr_assert_not_null(str_minf);
    cr_assert_str_eq(str_minf, "-inf");
    free(str_minf);
    str_nan = my_ftoa(0.0 / 0.0, 2);
    cr_assert_not_null(str_nan);
    cr_assert_str_eq(str_nan, "nan");
    free(str_nan);
}

Test(my_ftoa, malloc_fail, .fini = reset_malloc_wrapper)
{
    set_malloc_fail(1);
    set_malloc_count(0);
    cr_assert_null(my_ftoa(3.1415, 2));
}
