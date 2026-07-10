/*
** EPITECH PROJECT, 2026
** libdkz
** File description:
** test_precision
*/

#include "test.h"

Test(apply_precision, string_specifier_truncation)
{
    pf_info_t info = {.precision = 3};
    char *str = strdup("Hello World");
    char *res;

    cr_assert_not_null(str);
    res = apply_precision(str, &info, 's');
    cr_assert_not_null(res);
    cr_assert_str_eq(res, "Hel");
    free(res);
}

Test(apply_precision, string_specifier_no_truncation)
{
    pf_info_t info = {.precision = 20};
    char *str = strdup("Hello");
    char *res;

    cr_assert_not_null(str);
    res = apply_precision(str, &info, 's');
    cr_assert_not_null(res);
    cr_assert_str_eq(res, "Hello");
    free(res);
}

Test(apply_precision, no_padding_needed)
{
    pf_info_t info = {.precision = 3};
    char *str = strdup("12345");
    char *res;

    cr_assert_not_null(str);
    res = apply_precision(str, &info, 'd');
    cr_assert_not_null(res);
    cr_assert_str_eq(res, "12345");
    free(res);
}

Test(apply_precision, positive_number_padding)
{
    pf_info_t info = {.precision = 5};
    char *str = strdup("42");
    char *res;

    cr_assert_not_null(str);
    res = apply_precision(str, &info, 'd');
    cr_assert_not_null(res);
    cr_assert_str_eq(res, "00042");
    free(res);
}

Test(apply_precision, negative_number_padding)
{
    pf_info_t info = {.precision = 5};
    char *str = strdup("-42");
    char *res;

    cr_assert_not_null(str);
    res = apply_precision(str, &info, 'd');
    cr_assert_not_null(res);
    cr_assert_str_eq(res, "-00042");
    free(res);
}

Test(apply_precision, precision_zero_on_empty)
{
    pf_info_t info = {.precision = 0};
    char *str = strdup("");
    char *res;

    cr_assert_not_null(str);
    res = apply_precision(str, &info, 'd');
    cr_assert_not_null(res);
    cr_assert_str_eq(res, "");
    free(res);
}

Test(apply_precision, malloc_failure, .fini = reset_malloc_wrapper)
{
    pf_info_t info = {.precision = 5};
    char *str = strdup("42");
    char *res;

    cr_assert_not_null(str);
    set_malloc_fail(1);
    set_malloc_count(0);
    res = apply_precision(str, &info, 'd');
    cr_assert_not_null(res);
    cr_assert_str_eq(res, "42");
    free(res);
}
